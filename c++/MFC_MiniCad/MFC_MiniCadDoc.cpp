// MFC_MiniCadDoc.cpp : implementation of the CMFC_MiniCadDoc class
//

#include "stdafx.h"
#include "MFC_MiniCad.h"

#include "MFC_MiniCadDoc.h"
#include "Shape.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadDoc

IMPLEMENT_DYNCREATE(CMFC_MiniCadDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_MiniCadDoc, CDocument)
	//{{AFX_MSG_MAP(CMFC_MiniCadDoc)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadDoc construction/destruction

CMFC_MiniCadDoc::CMFC_MiniCadDoc()
{
	// TODO: add one-time construction code here
	iNew=0;

}

CMFC_MiniCadDoc::~CMFC_MiniCadDoc()
{
}

BOOL CMFC_MiniCadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadDoc serialization

void CMFC_MiniCadDoc::Serialize(CArchive& ar)
{
//	m_ObArray.Serialize(ar);
	if (ar.IsStoring())
	{
		int iCount=this->m_ObArray.GetSize();
		ar<<iCount;
		for(int i=0;i<iCount;i++)
		{
			CShape *pNew=(CShape *)m_ObArray[i];
			ar<<pNew;
			int t=pNew->m_PenW;
		}
	}
	else
	{
		iNew=0;
		int iCount=0;
		ar>>iCount;
		for(int i=0;i<iCount;i++)
		{
			CShape *pNew;
			ar>>pNew;
			m_ObArray.Add(pNew);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadDoc diagnostics

#ifdef _DEBUG
void CMFC_MiniCadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_MiniCadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadDoc commands

void CMFC_MiniCadDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	int iCount=m_ObArray.GetSize();
	for(int i=0;i<iCount;i++)
	{
		CShape *pNew = (CShape *)m_ObArray[i];
		delete pNew;
	}
	this->m_ObArray.RemoveAll();
	CDocument::DeleteContents();
}

void CMFC_MiniCadDoc::OnEditUndo() 
{
	// TODO: Add your command handler code here
	int i = m_ObArray.GetSize();
	if(iNew==0) return;
	CShape *pNew=(CShape *)m_ObArray[i-1];
	iNew--;
	delete pNew;
	m_ObArray.RemoveAt(i-1);
	this->UpdateAllViews(NULL);
}






