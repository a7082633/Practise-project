// MFC_OCLOCKDoc.cpp : implementation of the CMFC_OCLOCKDoc class
//

#include "stdafx.h"
#include "MFC_OCLOCK.h"

#include "MFC_OCLOCKDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKDoc

IMPLEMENT_DYNCREATE(CMFC_OCLOCKDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_OCLOCKDoc, CDocument)
	//{{AFX_MSG_MAP(CMFC_OCLOCKDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKDoc construction/destruction

CMFC_OCLOCKDoc::CMFC_OCLOCKDoc()
{
	// TODO: add one-time construction code here

}

CMFC_OCLOCKDoc::~CMFC_OCLOCKDoc()
{
}

BOOL CMFC_OCLOCKDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKDoc serialization

void CMFC_OCLOCKDoc::Serialize(CArchive& ar)
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
// CMFC_OCLOCKDoc diagnostics

#ifdef _DEBUG
void CMFC_OCLOCKDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_OCLOCKDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKDoc commands
