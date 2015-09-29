// MFC_1Doc.cpp : implementation of the CMFC_1Doc class
//

#include "stdafx.h"
#include "MFC_1.h"

#include "MFC_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_1Doc

IMPLEMENT_DYNCREATE(CMFC_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_1Doc, CDocument)
	//{{AFX_MSG_MAP(CMFC_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_1Doc construction/destruction

CMFC_1Doc::CMFC_1Doc()
{
	// TODO: add one-time construction code here

}

CMFC_1Doc::~CMFC_1Doc()
{
}

BOOL CMFC_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_1Doc serialization

void CMFC_1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_1Doc diagnostics

#ifdef _DEBUG
void CMFC_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_1Doc commands
