// MFC_SDIDoc.h : interface of the CMFC_SDIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_SDIDOC_H__712A4BB2_8DAB_41D1_8173_2C2D33095794__INCLUDED_)
#define AFX_MFC_SDIDOC_H__712A4BB2_8DAB_41D1_8173_2C2D33095794__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_SDIDoc : public CDocument
{
protected: // create from serialization only
	CMFC_SDIDoc();
	DECLARE_DYNCREATE(CMFC_SDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SDIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_SDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_SDIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SDIDOC_H__712A4BB2_8DAB_41D1_8173_2C2D33095794__INCLUDED_)
