// MFC_SnakeDoc.cpp : implementation of the CMFC_SnakeDoc class
//

#include "stdafx.h"
#include "MFC_Snake.h"

#include "MFC_SnakeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeDoc

IMPLEMENT_DYNCREATE(CMFC_SnakeDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_SnakeDoc, CDocument)
	//{{AFX_MSG_MAP(CMFC_SnakeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeDoc construction/destruction

CMFC_SnakeDoc::CMFC_SnakeDoc()
{
	// TODO: add one-time construction code here

}

CMFC_SnakeDoc::~CMFC_SnakeDoc()
{
}

BOOL CMFC_SnakeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeDoc serialization

void CMFC_SnakeDoc::Serialize(CArchive& ar)
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
// CMFC_SnakeDoc diagnostics

#ifdef _DEBUG
void CMFC_SnakeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_SnakeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeDoc commands
