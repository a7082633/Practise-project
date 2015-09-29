// IllusionExcelFile.cpp: implementation of the IllusionExcelFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCRandSeat.h"
#include "IllusionExcelFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/******************************************************************************************
Copyright           : 2000-2004, Appache  2.0
FileName            : illusion_excel_file.cpp
Author              : Sail
Version             : 
Date Of Creation    : 2009��4��3��
Description         : 

Others              : 
Function List       : 
    1.  ......
        Modification History:
    1.Date  :
Author  :
Modification  :

    ������Ǵ��������صģ���������ɣ���лԭ�������ߣ���ֻ��������������һ��������
    ��������һЩ������ʹ�ò�������bool ��ΪBOOL��,���ڶ����ϵ���Ҹ���һ���֣��о�ԭ�������߶���OO��˼·���ֲ��Ǻ������
    �������ණ��OLE������ȫ���˽⣬�ñ��˷�װ�Ķ����о����Ƿ����˺ܶ࣬C++��ΰ���C++
     http://blog.csdn.net/gyssoft/archive/2007/04/29/1592104.aspx

    OLE��дEXCEL���Ƚ���������Ӧ�þ�������OLE�Ĵ���
    ���ڶ�ȡ�����н��������������һ��Ԥ���صķ�ʽ���������һ�μ������еĶ�ȡ����,����ٶȾͷɿ��ˡ�
    ��˵д������û��ʲô�����ӿ��
    http://topic.csdn.net/t/20030626/21/1962211.html

    ������һЩд�뷽ʽ�Ĵ��룬��֤����д��EXCEL�����������Ƕ��ڱ��棬�ҷ����������CLOSE���ұ���ķ�ʽ��
    �ٶȷǳ������Ҳ����Ϊʲô��
    �����Ұ�EXCEL���ˣ�������к�������,


******************************************************************************************/




//-----------------------excelfile.cpp----------------




COleVariant
covTrue((short)TRUE),
covFalse((short)FALSE),
covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);    

//
_Application IllusionExcelFile::excel_application_;


IllusionExcelFile::IllusionExcelFile():
    already_preload_(FALSE)
{
}

IllusionExcelFile::~IllusionExcelFile()
{
    //
    CloseExcelFile();
}


//��ʼ��EXCEL�ļ���
BOOL IllusionExcelFile::InitExcel()
{

    //����Excel 2000������(����Excel) 
//    if (!excel_application_.CreateDispatch("Excel.Application",NULL)) 
//    { 
//        AfxMessageBox("����Excel����ʧ��,�����û�а�װEXCEL������!"); 
//        return FALSE;
//    }
//
//    excel_application_.put_DisplayAlerts(FALSE);
//    return TRUE;

	 if(CoInitialize(NULL)==S_FALSE) 
    { 
        AfxMessageBox("��ʼ��COM֧�ֿ�ʧ�ܣ�"); 
        return FALSE; 
    }
    //����Excel 2000������(����Excel) 
    if (!excel_application_.CreateDispatch("Excel.Application", NULL)) 
    { 
        AfxMessageBox("����Excel����ʧ��!");
        return FALSE;
    }
    //m_app.put_DisplayAlerts(FALSE); 
    return TRUE;
}

//
void IllusionExcelFile::ReleaseExcel()
{
    excel_application_.Quit();
    excel_application_.ReleaseDispatch();
    excel_application_=NULL;
}

//��excel�ļ�
BOOL IllusionExcelFile::OpenExcelFile(const char *file_name)
{
    //�ȹر�
    CloseExcelFile();
    
    //����ģ���ļ��������ĵ� 
    excel_books_.AttachDispatch(excel_application_.GetWorkbooks());
	//excel_current_range_.AttachDispatch(excel_application_.GetWorkbooks());


    LPDISPATCH lpDis = NULL;
    //lpDis = excel_books_.Add(COleVariant(file_name)); 
	lpDis = excel_books_.Open(_T("d:\\test.xls"),covOptional, covOptional, covOptional , covOptional, covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional,covOptional);
    if (lpDis)
    {
        excel_work_book_.AttachDispatch(lpDis); 
        //�õ�Worksheets 
        excel_sheets_.AttachDispatch(excel_work_book_.GetWorksheets(),true); 
        
        //��¼�򿪵��ļ�����
        open_excel_file_ = file_name;

        return TRUE;
    }
    
    return FALSE;
}

//�رմ򿪵�Excel �ļ�,Ĭ������������ļ�
void IllusionExcelFile::CloseExcelFile(BOOL if_save)
{
    //����Ѿ��򿪣��ر��ļ�
    if (open_excel_file_.IsEmpty() == FALSE)
    {
        //�������,�����û�����,���û��Լ��棬����Լ�SAVE�������Ī���ĵȴ�
        if (if_save)
        {
            ShowInExcel(TRUE);
        }
        else
        {
            //
            excel_work_book_.Close(COleVariant(short(FALSE)),COleVariant(open_excel_file_),covOptional);
            excel_books_.Close();
        }

        //���ļ����������
        open_excel_file_.Empty();
    }

    

    excel_sheets_.ReleaseDispatch();
    excel_work_sheet_.ReleaseDispatch();
    excel_current_range_.ReleaseDispatch();
    excel_work_book_.ReleaseDispatch();
    excel_books_.ReleaseDispatch();
}

void IllusionExcelFile::SaveasXSLFile(const CString &xls_file)
{
    excel_work_book_.SaveAs(COleVariant(xls_file),
        covOptional,
        covOptional,
        covOptional,
        covOptional,
        covOptional,
        0,
        covOptional,
        covOptional,
        covOptional,
        covOptional,
        covOptional);
    return;
}


int IllusionExcelFile::GetSheetCount()
{
    return excel_sheets_.GetCount();
}


CString IllusionExcelFile::GetSheetName(long table_index)
{
    _Worksheet sheet;
    sheet.AttachDispatch(excel_sheets_.GetItem(COleVariant((long)table_index)),true);
    CString name = sheet.GetName();
    sheet.ReleaseDispatch();
    return name;
}

//������ż���Sheet���,������ǰ�������еı���ڲ�����
BOOL IllusionExcelFile::LoadSheet(long table_index,BOOL pre_load)
{
    LPDISPATCH lpDis = NULL;
    excel_current_range_.ReleaseDispatch();
    excel_work_sheet_.ReleaseDispatch();
    lpDis = excel_sheets_.GetItem(COleVariant((long)table_index));
    if (lpDis)
    {
        excel_work_sheet_.AttachDispatch(lpDis,true);
        excel_current_range_.AttachDispatch(excel_work_sheet_.GetCells(), true);
    }
    else
    {
        return FALSE;
    }
    
    already_preload_ = FALSE;
    //�������Ԥ�ȼ���
    if (pre_load)
    {
        PreLoadSheet();
        already_preload_ = TRUE;
    }

    return TRUE;
}

//�������Ƽ���Sheet���,������ǰ�������еı���ڲ�����
BOOL IllusionExcelFile::LoadSheet(const char* sheet,BOOL pre_load)
{
    LPDISPATCH lpDis = NULL;
    excel_current_range_.ReleaseDispatch();
    excel_work_sheet_.ReleaseDispatch();
    lpDis = excel_sheets_.GetItem(COleVariant(sheet));
    if (lpDis)
    {
        excel_work_sheet_.AttachDispatch(lpDis,true);
        excel_current_range_.AttachDispatch(excel_work_sheet_.GetCells(), true);
        
    }
    else
    {
        return FALSE;
    }
    //
    already_preload_ = FALSE;
    //�������Ԥ�ȼ���
    if (pre_load)
    {
        already_preload_ = TRUE;
        PreLoadSheet();
    }

    return TRUE;
}

//�õ��е�����
int IllusionExcelFile::GetColumnCount()
{
    Range range;
    Range usedRange;
    usedRange.AttachDispatch(excel_work_sheet_.GetUsedRange(), true);
    range.AttachDispatch(usedRange.GetColumns(), true);
    int count = range.GetCount();
    usedRange.ReleaseDispatch();
    range.ReleaseDispatch();
    return count;
}

//�õ��е�����
int IllusionExcelFile::GetRowCount()
{
    Range range;
    Range usedRange;
    usedRange.AttachDispatch(excel_work_sheet_.GetUsedRange(), true);
    range.AttachDispatch(usedRange.GetRows(), true);
    int count = range.GetCount();
    usedRange.ReleaseDispatch();
    range.ReleaseDispatch();
    return count;
}

//���һ��CELL�Ƿ����ַ���
BOOL IllusionExcelFile::IsCellString(long irow, long icolumn)
{
    Range range;
    range.AttachDispatch(excel_current_range_.GetItem (COleVariant((long)irow),COleVariant((long)icolumn)).pdispVal, true);
    COleVariant vResult =range.GetValue2();
    //VT_BSTR��ʾ�ַ���
    if(vResult.vt == VT_BSTR)       
    {
        return TRUE;
    }
    return FALSE;
}

//���һ��CELL�Ƿ�����ֵ
BOOL IllusionExcelFile::IsCellInt(long irow, long icolumn)
{
    Range range;
    range.AttachDispatch(excel_current_range_.GetItem (COleVariant((long)irow),COleVariant((long)icolumn)).pdispVal, true);
    COleVariant vResult =range.GetValue2();
    //����һ�㶼��VT_R8
    if(vResult.vt == VT_INT || vResult.vt == VT_R8)       
    {
        return TRUE;
    }
    return FALSE;
}

//
CString IllusionExcelFile::GetCellString(long irow, long icolumn)
{
   
    COleVariant vResult ;
    CString str;
    //�ַ���
    if (already_preload_ == FALSE)
    {
        Range range;
        range.AttachDispatch(excel_current_range_.GetItem (COleVariant((long)irow),COleVariant((long)icolumn)).pdispVal, true);
        vResult =range.GetValue2();
        range.ReleaseDispatch();
    }
    //�����������Ԥ�ȼ�����
    else
    {
        long read_address[2];
        VARIANT val;
        read_address[0] = irow;
        read_address[1] = icolumn;
        ole_safe_array_.GetElement(read_address, &val);
        vResult = val;
    }

    if(vResult.vt == VT_BSTR)
    {
        str=vResult.bstrVal;
    }
    //����
    else if (vResult.vt==VT_INT)
    {
        str.Format("%d",vResult.pintVal);
    }
    //8�ֽڵ����� 
    else if (vResult.vt==VT_R8)     
    {
        str.Format("%0.0f",vResult.dblVal);
    }
    //ʱ���ʽ
    else if(vResult.vt==VT_DATE)    
    {
        SYSTEMTIME st;
        VariantTimeToSystemTime(vResult.date, &st);
        CTime tm(st); 
        str=tm.Format("%Y-%m-%d");

    }
    //��Ԫ��յ�
    else if(vResult.vt==VT_EMPTY)   
    {
        str="";
    }  

    return str;
}

double IllusionExcelFile::GetCellDouble(long irow, long icolumn)
{
    double rtn_value = 0;
    COleVariant vresult;
    //�ַ���
    if (already_preload_ == FALSE)
    {
        Range range;
        range.AttachDispatch(excel_current_range_.GetItem (COleVariant((long)irow),COleVariant((long)icolumn)).pdispVal, true);
        vresult =range.GetValue2();
        range.ReleaseDispatch();
    }
    //�����������Ԥ�ȼ�����
    else
    {
        long read_address[2];
        VARIANT val;
        read_address[0] = irow;
        read_address[1] = icolumn;
        ole_safe_array_.GetElement(read_address, &val);
        vresult = val;
    }
    
    if (vresult.vt==VT_R8)     
    {
        rtn_value = vresult.dblVal;
    }
    
    return rtn_value;
}

//VT_R8
int IllusionExcelFile::GetCellInt(long irow, long icolumn)
{
    int num;
    COleVariant vresult;

    if (already_preload_ == FALSE)
    {
        Range range;
        range.AttachDispatch(excel_current_range_.GetItem (COleVariant((long)irow),COleVariant((long)icolumn)).pdispVal, true);
        vresult = range.GetValue2();
        range.ReleaseDispatch();
    }
    else
    {
        long read_address[2];
        VARIANT val;
        read_address[0] = irow;
        read_address[1] = icolumn;
        ole_safe_array_.GetElement(read_address, &val);
        vresult = val;
    }
    //
    num = static_cast<int>(vresult.dblVal);

    return num;
}

void IllusionExcelFile::SetCellString(long irow, long icolumn,CString new_string)
{
    COleVariant new_value(new_string);
    Range start_range = excel_work_sheet_.GetRange(COleVariant("A1"),covOptional);
    //Range write_range = start_range.GetOffset(COleVariant((long)(irow -1)),COleVariant((long)(icolumn -1));
	Range write_range = start_range.GetOffset(COleVariant((long)(irow -1)),COleVariant((long)(icolumn -1)));
    write_range.SetValue2(new_value);
    start_range.ReleaseDispatch();
    write_range.ReleaseDispatch();

}

void IllusionExcelFile::SetCellInt(long irow, long icolumn,int new_int)
{
    COleVariant new_value((long)new_int);
    
    Range start_range = excel_work_sheet_.GetRange(COleVariant("A1"),covOptional);
    Range write_range = start_range.GetOffset(COleVariant((long)(irow -1)),COleVariant((long)(icolumn -1)));
    write_range.SetValue2(new_value);
    start_range.ReleaseDispatch();
    write_range.ReleaseDispatch();
}


//
void IllusionExcelFile::ShowInExcel(BOOL bShow)
{
    excel_application_.SetVisible(bShow);
    excel_application_.SetUserControl(bShow);
}

//���ش򿪵�EXCEL�ļ�����
CString IllusionExcelFile::GetOpenFileName()
{
    return open_excel_file_;
}

//ȡ�ô�sheet������
CString IllusionExcelFile::GetLoadSheetName()
{
    return excel_work_sheet_.GetName();
}

//ȡ���е����ƣ�����27->AA
char *IllusionExcelFile::GetColumnName(long icolumn)
{   
    static char column_name[64];
    size_t str_len = 0;
    
    while(icolumn > 0)
    {
        int num_data = icolumn % 26;
        icolumn /= 26;
        if (num_data == 0)
        {
            num_data = 26;
            icolumn--;
        }
        column_name[str_len] = (char)((num_data-1) + 'A' );
        str_len ++;
    }
    column_name[str_len] = '\0';
    //��ת
    _strrev(column_name);

    return column_name;
}

//Ԥ�ȼ���
void IllusionExcelFile::PreLoadSheet()
{

    Range used_range;

    used_range = excel_work_sheet_.GetUsedRange();	


    VARIANT ret_ary = used_range.GetValue2();
    if (!(ret_ary.vt & VT_ARRAY))
    {
        return;
    }
    //
    ole_safe_array_.Clear();
    ole_safe_array_.Attach(ret_ary); 
}


