// MFCRandSeatDoc.cpp : implementation of the CMFCRandSeatDoc class
//

#include "stdafx.h"
#include "MFCRandSeat.h"

#include "MFCRandSeatDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatDoc

IMPLEMENT_DYNCREATE(CMFCRandSeatDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCRandSeatDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCRandSeatDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatDoc construction/destruction

CMFCRandSeatDoc::CMFCRandSeatDoc()
{
	// TODO: add one-time construction code here

}

CMFCRandSeatDoc::~CMFCRandSeatDoc()
{
}

BOOL CMFCRandSeatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatDoc serialization

void CMFCRandSeatDoc::Serialize(CArchive& ar)
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
// CMFCRandSeatDoc diagnostics

#ifdef _DEBUG
void CMFCRandSeatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCRandSeatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatDoc commands
