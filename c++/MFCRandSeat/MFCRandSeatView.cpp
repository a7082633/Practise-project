// MFCRandSeatView.cpp : implementation of the CMFCRandSeatView class
//

#include "stdafx.h"
#include "MFCRandSeat.h"

#include "MFCRandSeatDoc.h"
#include "MFCRandSeatView.h"
#include "IllusionExcelFile.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IllusionExcelFile excel;
/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatView

IMPLEMENT_DYNCREATE(CMFCRandSeatView, CView)

BEGIN_MESSAGE_MAP(CMFCRandSeatView, CView)
	//{{AFX_MSG_MAP(CMFCRandSeatView)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatView construction/destruction

CMFCRandSeatView::CMFCRandSeatView()
{
	// TODO: add construction code here

}

CMFCRandSeatView::~CMFCRandSeatView()
{
}

BOOL CMFCRandSeatView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatView drawing

void CMFCRandSeatView::OnDraw(CDC* pDC)
{
	CMFCRandSeatDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatView printing

BOOL CMFCRandSeatView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCRandSeatView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCRandSeatView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatView diagnostics

#ifdef _DEBUG
void CMFCRandSeatView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCRandSeatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCRandSeatDoc* CMFCRandSeatView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCRandSeatDoc)));
	return (CMFCRandSeatDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatView message handlers

void CMFCRandSeatView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CWnd *parent=this->GetParent();
	::PostMessage(*parent,WM_NCLBUTTONDOWN,HTCAPTION,0);
	CView::OnLButtonDown(nFlags, point);
}

void CMFCRandSeatView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==27) ::PostQuitMessage(0);
	if(nChar==VK_F1)
	{
		CWnd *parent=this->GetParent();
		::PostMessage(*parent,WM_CHWNDSIZE,0,0);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CMFCRandSeatView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
//	if(!excel.InitExcel())
//		this->MessageBox("initial file failure!");
//	if(!excel.OpenExcelFile("D:\test.xls"))
//		this->MessageBox("open file failure!");
	return 0;
}

void CMFCRandSeatView::OnDestroy() 
{
	CView::OnDestroy();
	excel.CloseExcelFile();
	// TODO: Add your message handler code here
	
}

void CMFCRandSeatView::ReatExcel()
{
	CDatabase database;  
	CString sSql;  
	CString sItem1, sItem2;  
	CString sDriver;  
	CString sDsn;  
	CString sFile = "Demo.xls"; // ������ȡ��Excel�ļ���  
	
	// �����Ƿ�װ��Excel���� "Microsoft Excel Driver (*.xls)"  
	sDriver = GetExcelDriver();  
	if (sDriver.IsEmpty())  
	{  
		// û�з���Excel����  
		AfxMessageBox("û�а�װExcel����!");  
		return;  
	}  
	
	// �������д�ȡ���ַ���  
	sDsn.Format("ODBC;DRIVER={%s};DSN='''';DBQ=%s", sDriver, sFile);  
	
	TRY  
	{  
		// �����ݿ�(��Excel�ļ�)  
		database.Open(NULL, false, false, sDsn);  
		
		CRecordset recset(&database);  
		
		// ���ö�ȡ�Ĳ�ѯ���.  
		sSql = "SELECT Name, Age "  
			"FROM demo "  
			"ORDER BY Name ";  
		
		// ִ�в�ѯ���  
		recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);  
		
		// ��ȡ��ѯ���  
		while (!recset.IsEOF())  
		{  
			//��ȡExcel�ڲ���ֵ  
			recset.GetFieldValue("Name ", sItem1);  
			recset.GetFieldValue("Age", sItem2);  
			
			// �Ƶ���һ��  
			recset.MoveNext();  
		}  
		
		// �ر����ݿ�  
		database.Close();  
		
	}  
	CATCH(CDBException, e)  
	{  
		// ���ݿ���������쳣ʱ...  
		AfxMessageBox("���ݿ����: " + e->m_strError);  
	}  
	END_CATCH;  

}

CString CMFCRandSeatView::GetExcelDriver()
{
	char szBuf[2001];  
	WORD cbBufMax = 2000;  
	WORD cbBufOut;  
	char *pszBuf = szBuf;  
	CString sDriver;  
	
	// ��ȡ�Ѱ�װ����������(������odbcinst.h��)  
	if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))  
		return "";  
	
	// �����Ѱ�װ�������Ƿ���Excel...  
	do  
	{
		if (strstr(pszBuf, "Excel") != 0)  
		{
			//���� !  
			sDriver = CString(pszBuf);  
			break;
		}
        pszBuf=strchr(pszBuf,''\0'')+1;
	}
	while (pszBuf[1] != ''\0'');
	return sDriver;  
}
