// MFC_RUSSIADoc.cpp : implementation of the CMFC_RUSSIADoc class
//

#include "stdafx.h"
#include "MFC_RUSSIA.h"

#include "MFC_RUSSIADoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIADoc

IMPLEMENT_DYNCREATE(CMFC_RUSSIADoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_RUSSIADoc, CDocument)
	//{{AFX_MSG_MAP(CMFC_RUSSIADoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIADoc construction/destruction

CMFC_RUSSIADoc::CMFC_RUSSIADoc()
{
	// TODO: add one-time construction code here
}

CMFC_RUSSIADoc::~CMFC_RUSSIADoc()
{
}

BOOL CMFC_RUSSIADoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	this->SetTitle("ถํยÞหน");
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIADoc serialization

void CMFC_RUSSIADoc::Serialize(CArchive& ar)
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
// CMFC_RUSSIADoc diagnostics

#ifdef _DEBUG
void CMFC_RUSSIADoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_RUSSIADoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIADoc commands
