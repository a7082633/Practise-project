// MFC_ShotWordsDoc.cpp : implementation of the CMFC_ShotWordsDoc class
//

#include "stdafx.h"
#include "MFC_ShotWords.h"

#include "MFC_ShotWordsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsDoc

IMPLEMENT_DYNCREATE(CMFC_ShotWordsDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_ShotWordsDoc, CDocument)
	//{{AFX_MSG_MAP(CMFC_ShotWordsDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsDoc construction/destruction

CMFC_ShotWordsDoc::CMFC_ShotWordsDoc()
{
	// TODO: add one-time construction code here

}

CMFC_ShotWordsDoc::~CMFC_ShotWordsDoc()
{
}

BOOL CMFC_ShotWordsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	this->SetTitle("´ò×Ö");
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsDoc serialization

void CMFC_ShotWordsDoc::Serialize(CArchive& ar)
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
// CMFC_ShotWordsDoc diagnostics

#ifdef _DEBUG
void CMFC_ShotWordsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_ShotWordsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsDoc commands
