// MFC_SDIView.cpp : implementation of the CMFC_SDIView class
//

#include "stdafx.h"
#include "MFC_SDI.h"

#include "MFC_SDIDoc.h"
#include "MFC_SDIView.h"
//#include "TBitMap.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIView

IMPLEMENT_DYNCREATE(CMFC_SDIView, CView)

BEGIN_MESSAGE_MAP(CMFC_SDIView, CView)
	//{{AFX_MSG_MAP(CMFC_SDIView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIView construction/destruction

CMFC_SDIView::CMFC_SDIView()
{
	// TODO: add construction code here

}

CMFC_SDIView::~CMFC_SDIView()
{
}

BOOL CMFC_SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIView drawing

void CMFC_SDIView::OnDraw(CDC* pDC)
{
	CMFC_SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rt;
	this->GetClientRect(&rt);
	//CBitmap bmp;
//	BYTE *pPicData;
//	BITMAPINFOHEADER BmpInfoHead={0};
//	BITMAPFILEHEADER BmpFileHead={0};
//	CFile file;
//	//this->MessageBox("test");
//	if (file.Open("D:\\aaa.bmp",CFile::modeReadWrite ))
//	{
//		//this->MessageBox("test");
//		file.Read(&BmpFileHead,sizeof(BmpFileHead));
//		file.Read(&BmpInfoHead,sizeof(BmpInfoHead));
//		pPicData=new BYTE[BmpInfoHead.biSizeImage];
//		file.Read(pPicData, BmpInfoHead.biSizeImage);		
//		file.Close();
//	}



	//this->GetDIBits(hMemDC,hNewBit,0,nHeight,pPicData,(LPBITMAPINFO)&BmpInfoHead,DIB_RGB_COLORS);

//	CDC memDC;
//	memDC.CreateCompatibleDC(pDC);
//	CBitmap bmp;
//	bmp.CreateCompatibleBitmap(pDC,rt.Width(),rt.Height());
//	memDC.SelectObject(bmp);
//	memDC.FillSolidRect(0,0,rt.Width(),rt.Height(),0xffffff);
//=======================�����ⲿλͼ������ʾ

	CDC   MemDC;   
	HBITMAP hBmp;
	BITMAP   bm;   
	CBitmap Bitmap;
	CPoint point(10,10);
	CString cStr;
	
	hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),"aaa.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	Bitmap.DeleteObject();

	Bitmap.Attach( hBmp );
	Bitmap.GetObject(sizeof(BITMAP),&bm);   
	MemDC.CreateCompatibleDC(pDC);   
	MemDC.SelectObject(&Bitmap);   
	pDC->BitBlt(point.x, point.y, bm.bmWidth, bm.bmHeight, &MemDC, 0, 0, SRCCOPY);  
	MemDC.DeleteDC();



	//pDC->Ellipse(0,0,50,50);
	//pDC->BitBlt(0,0,500,500,&MemDC,0,0,SRCCOPY);

	//memDC.DeleteDC();
//	CTBitMap  BitMyMap;
//	//BitMyMap.LoadBmpFile(this->GetWindow(),"d:\\test.bmp");
//	CDC hMemDC;
//	if (BitMyMap.hBitmap) //hBitmap һ��ʼ�� NULL ������ΪNULL ʱ��ʾ��ͼ  	
//	{  
//		hMemDC.CreateCompatibleDC(pDC); //����һ���ڴ��豸������  
//		if (BitMyMap.hPalette.IsSerializable()) //�е�ɫ��  	
//		{  
//			//����ɫ��ѡ����Ļ�豸������  
//			pDC->SelectPalette (&BitMyMap.hPalette,FALSE);    
//			//����ɫ��ѡ���ڴ��豸������  
////			----------------------- Page 22-----------------------
//			hMemDC.SelectPalette (&BitMyMap.hPalette,FALSE);  
//			pDC->RealizePalette ();  
//		}  
//		//��λͼѡ���ڴ��豸������  
//		hMemDC.SelectObject(BitMyMap.hBitmap);  
//		//��ʾλͼ  
//		pDC->BitBlt(0, 0, BitMyMap.bi.biWidth, BitMyMap.bi.biHeight, &hMemDC, 0, 0, SRCCOPY);  
//		//�ͷ��ڴ��豸������  
//		DeleteDC(hMemDC);  
//	}  
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIView printing

BOOL CMFC_SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIView diagnostics

#ifdef _DEBUG
void CMFC_SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_SDIDoc* CMFC_SDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_SDIDoc)));
	return (CMFC_SDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIView message handlers

void CMFC_SDIView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SavePicture("d:\\test.bmp");
	//this->Invalidate();
//===================================================
//	CWindowDC dc1(this->GetDesktopWindow());
//	CClientDC dc2(this);
//
//	dc2.BitBlt(0,0,500,500,&dc1,0,0,SRCCOPY);
//======================================================
//	CRect rt;
//	rt.left=0;
//	rt.top=0;
//	rt.right=500;
//	rt.bottom=500;
//	CBrush bru(RGB(255,0,0));
//	dc1.FillRect(&rt,&bru);

//	for(int i=0;i<1366;i++)
//		for(int j=0;j<768;j++)
//		{
//			dc2.SetPixel(i,j,dc1.GetPixel(i,j));
//		}
	CView::OnLButtonDown(nFlags, point);
}

void CMFC_SDIView::SavePicture(CString sSaveFileName)
{
	//��ȡ��Ļ��λͼ֮�����
	//	CWindowDC dc1(this->GetDesktopWindow());
//	CClientDC dc2(this);
	BeginWaitCursor();
	
	BYTE *pPicData = NULL;
	CDC *pDC = GetDC();
	//HDC hScrDC = pDC->GetSafeHdc();
	CWindowDC hSrcDC(this->GetDesktopWindow());
	CDC hMemDC;
	hMemDC.CreateCompatibleDC(pDC);

	//hSrcDC.GetPath(
	CWnd *desk=this->GetDesktopWindow();
	CRect rt;
	desk->GetClientRect(&rt);

	INT nBitsPixel = pDC->GetDeviceCaps(BITSPIXEL);
//	nBitsPixel=24;
//	CRect rcWndRect;
//	GetClientRect(&rcWndRect);
	INT nWidth = rt.right;
	INT nHeight = rt.bottom;

	
	DWORD nImageSize = nWidth * nHeight * nBitsPixel / 8;
	pPicData = new BYTE[nImageSize];
	
	BITMAPINFOHEADER BmpInfoHead;
	memset(&BmpInfoHead,0,sizeof(BmpInfoHead));
	BmpInfoHead.biSize = sizeof(BmpInfoHead);
	BmpInfoHead.biWidth = nWidth;
	BmpInfoHead.biHeight = nHeight;
	BmpInfoHead.biBitCount = nBitsPixel;
	BmpInfoHead.biCompression = BI_RGB;
	BmpInfoHead.biPlanes = 1;
	BmpInfoHead.biSizeImage = nImageSize;
	
	// ����һ������Ļ�豸��������ݵ�λͼ
    HBITMAP hNewBit = CreateCompatibleBitmap(hSrcDC, nWidth, nHeight);
	
    // ����λͼѡ���ڴ��豸��������
    HBITMAP hOldBitmap = (HBITMAP)SelectObject( hMemDC, hNewBit );
	
    // ����Ļ�豸�����������ڴ��豸��������
	//StretchBlt(hMemDC, 0, 0, nWidth, nHeight,hSrcDC, 0, 0, nWidth, nHeight, SRCCOPY);
	hMemDC.BitBlt(0,0,nWidth,nHeight,&hSrcDC,0,0,SRCCOPY);

	
	//ȡ��λͼ����
	GetDIBits(hMemDC,hNewBit,0,nHeight,pPicData,(LPBITMAPINFO)&BmpInfoHead,DIB_RGB_COLORS);

	//::GetBitmapBits(hNewBit,nImageSize,pPicData);
	
	
	//�õ���Ļλͼ�ľ��,��ԭλͼ����
    SelectObject(hMemDC, hOldBitmap);
	
	//�ͷ�
	ReleaseDC(pDC);
	DeleteDC(hMemDC);
	DeleteObject(hNewBit);
	
	if (pPicData)
	{
		DWORD nLineLen = (nWidth * nBitsPixel + 31) / 32 * 4;
		DWORD nColSize = sizeof(RGBQUAD)*((nBitsPixel <= 8) ? 1<<nBitsPixel : 0);
		DWORD nImageSize = sizeof(BITMAPINFOHEADER) + nColSize + 
			(DWORD)(UINT)nLineLen*(DWORD)(UINT)nHeight;
		
		BITMAPFILEHEADER BmpFileHead;
		BmpFileHead.bfType = MAKEWORD('B','M');
		BmpFileHead.bfSize = sizeof(BITMAPFILEHEADER) + 
			sizeof(BITMAPINFOHEADER) + nImageSize;
		BmpFileHead.bfReserved1 = BmpFileHead.bfReserved2 = 0;
		BmpFileHead.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		
		//BITMAPINFOHEADER BmpInfoHead;
		memset(&BmpInfoHead, 0, sizeof(BITMAPINFOHEADER));
		BmpInfoHead.biSize = sizeof(BITMAPINFOHEADER);
		BmpInfoHead.biWidth = nWidth;
		BmpInfoHead.biHeight = nHeight;
		BmpInfoHead.biBitCount = nBitsPixel;
		BmpInfoHead.biCompression = BI_RGB;
		BmpInfoHead.biPlanes = 1;
		BmpInfoHead.biSizeImage = nImageSize - sizeof(BITMAPINFOHEADER) - nColSize ;
		BmpInfoHead.biXPelsPerMeter = 0 ;
		BmpInfoHead.biYPelsPerMeter = 0 ;
		BmpInfoHead.biClrUsed = (nBitsPixel <= 8) ? 1<<nBitsPixel : 0;
		BmpInfoHead.biClrImportant = 0 ;
		
		CFile file;
		if (file.Open(sSaveFileName, CFile::modeCreate | CFile::modeWrite))
		{
			file.Write(&BmpFileHead,sizeof(BmpFileHead));
			file.Write(&BmpInfoHead,sizeof(BmpInfoHead));
			file.Write(pPicData, nImageSize);
			
			file.Close();
		}
		
		delete []pPicData;
	}
	
	EndWaitCursor();

}

void CMFC_SDIView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	this->Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

void CMFC_SDIView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar == VK_F1)         //��ȡ��Ļ��λͼ
	{
		CWindowDC pDC(this);

		CWnd *dest=this->GetDesktopWindow();
		CWindowDC wDC(this->GetDesktopWindow());
		CRect rt;
		dest->GetClientRect(&rt);

		CBitmap *bmp;
		bmp=wDC.GetCurrentBitmap();

		CDC memDC;
		memDC.CreateCompatibleDC(&pDC);
		memDC.SelectObject(bmp);

		pDC.BitBlt(0,0,800,800,&memDC,0,0,SRCCOPY);

		bmp->DeleteObject();
		memDC.DeleteDC();
		//wDC.DeleteDC();

	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
