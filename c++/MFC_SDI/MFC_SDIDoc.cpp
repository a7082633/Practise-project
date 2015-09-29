// MFC_SDIDoc.cpp : implementation of the CMFC_SDIDoc class
//

#include "stdafx.h"
#include "MFC_SDI.h"

#include "MFC_SDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIDoc

IMPLEMENT_DYNCREATE(CMFC_SDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_SDIDoc, CDocument)
	//{{AFX_MSG_MAP(CMFC_SDIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIDoc construction/destruction

CMFC_SDIDoc::CMFC_SDIDoc()
{
	// TODO: add one-time construction code here

}

CMFC_SDIDoc::~CMFC_SDIDoc()
{
}

BOOL CMFC_SDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIDoc serialization

void CMFC_SDIDoc::Serialize(CArchive& ar)
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
// CMFC_SDIDoc diagnostics

#ifdef _DEBUG
void CMFC_SDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_SDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIDoc commands
