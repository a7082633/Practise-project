// TBitMap.h: interface for the CTBitMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TBITMAP_H__803E4841_462B_48F8_922A_9F7244F2A70F__INCLUDED_)
#define AFX_TBITMAP_H__803E4841_462B_48F8_922A_9F7244F2A70F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTBitMap  
{
public:
	HGLOBAL hImgData;
	CPalette hPalette;
	HBITMAP hBitmap;
	BOOL LoadBmpFile (HWND hWnd,char *BmpFileName);
	BITMAPINFOHEADER bi;
	BITMAPFILEHEADER bf;
	CTBitMap();
	virtual ~CTBitMap();

};

#endif // !defined(AFX_TBITMAP_H__803E4841_462B_48F8_922A_9F7244F2A70F__INCLUDED_)
