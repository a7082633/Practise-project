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
	CString sFile = "Demo.xls"; // 将被读取的Excel文件名  
	
	// 检索是否安装有Excel驱动 "Microsoft Excel Driver (*.xls)"  
	sDriver = GetExcelDriver();  
	if (sDriver.IsEmpty())  
	{  
		// 没有发现Excel驱动  
		AfxMessageBox("没有安装Excel驱动!");  
		return;  
	}  
	
	// 创建进行存取的字符串  
	sDsn.Format("ODBC;DRIVER={%s};DSN='''';DBQ=%s", sDriver, sFile);  
	
	TRY  
	{  
		// 打开数据库(既Excel文件)  
		database.Open(NULL, false, false, sDsn);  
		
		CRecordset recset(&database);  
		
		// 设置读取的查询语句.  
		sSql = "SELECT Name, Age "  
			"FROM demo "  
			"ORDER BY Name ";  
		
		// 执行查询语句  
		recset.Open(CRecordset::forwardOnly, sSql, CRecordset::readOnly);  
		
		// 获取查询结果  
		while (!recset.IsEOF())  
		{  
			//读取Excel内部数值  
			recset.GetFieldValue("Name ", sItem1);  
			recset.GetFieldValue("Age", sItem2);  
			
			// 移到下一行  
			recset.MoveNext();  
		}  
		
		// 关闭数据库  
		database.Close();  
		
	}  
	CATCH(CDBException, e)  
	{  
		// 数据库操作产生异常时...  
		AfxMessageBox("数据库错误: " + e->m_strError);  
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
	
	// 获取已安装驱动的名称(涵数在odbcinst.h里)  
	if (!SQLGetInstalledDrivers(szBuf, cbBufMax, &cbBufOut))  
		return "";  
	
	// 检索已安装的驱动是否有Excel...  
	do  
	{
		if (strstr(pszBuf, "Excel") != 0)  
		{
			//发现 !  
			sDriver = CString(pszBuf);  
			break;
		}
        pszBuf=strchr(pszBuf,''\0'')+1;
	}
	while (pszBuf[1] != ''\0'');
	return sDriver;  
}
