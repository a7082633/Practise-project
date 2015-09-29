// MFC_WUZIDoc.cpp : implementation of the CMFC_WUZIDoc class
//

#include "stdafx.h"
#include "MFC_WUZI.h"

#include "MFC_WUZIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIDoc

IMPLEMENT_DYNCREATE(CMFC_WUZIDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_WUZIDoc, CDocument)
	//{{AFX_MSG_MAP(CMFC_WUZIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIDoc construction/destruction

CMFC_WUZIDoc::CMFC_WUZIDoc()
{
	// TODO: add one-time construction code here

}

CMFC_WUZIDoc::~CMFC_WUZIDoc()
{
}

BOOL CMFC_WUZIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	this->SetTitle("Îå×ÓÆå");
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIDoc serialization

void CMFC_WUZIDoc::Serialize(CArchive& ar)
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
// CMFC_WUZIDoc diagnostics

#ifdef _DEBUG
void CMFC_WUZIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_WUZIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIDoc commands
