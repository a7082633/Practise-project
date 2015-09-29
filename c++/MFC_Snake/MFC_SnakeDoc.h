// MFC_SnakeDoc.h : interface of the CMFC_SnakeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_SNAKEDOC_H__BA64700A_92C4_4C54_A0AA_E7E849930491__INCLUDED_)
#define AFX_MFC_SNAKEDOC_H__BA64700A_92C4_4C54_A0AA_E7E849930491__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_SnakeDoc : public CDocument
{
protected: // create from serialization only
	CMFC_SnakeDoc();
	DECLARE_DYNCREATE(CMFC_SnakeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SnakeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_SnakeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_SnakeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SNAKEDOC_H__BA64700A_92C4_4C54_A0AA_E7E849930491__INCLUDED_)
