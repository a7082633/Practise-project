// MFCTestDoc.cpp : implementation of the CMFCTestDoc class
//

#include "stdafx.h"
#include "MFCTest.h"

#include "MFCTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCTestDoc

IMPLEMENT_DYNCREATE(CMFCTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCTestDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCTestDoc construction/destruction

CMFCTestDoc::CMFCTestDoc()
{
	// TODO: add one-time construction code here

}

CMFCTestDoc::~CMFCTestDoc()
{
}

BOOL CMFCTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCTestDoc serialization

void CMFCTestDoc::Serialize(CArchive& ar)
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
// CMFCTestDoc diagnostics

#ifdef _DEBUG
void CMFCTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCTestDoc commands
