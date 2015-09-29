// MFC_RUSSIADoc.h : interface of the CMFC_RUSSIADoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_RUSSIADOC_H__3AFA7739_56A3_468B_A24F_1A419BEC82E1__INCLUDED_)
#define AFX_MFC_RUSSIADOC_H__3AFA7739_56A3_468B_A24F_1A419BEC82E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_RUSSIADoc : public CDocument
{
protected: // create from serialization only
	CMFC_RUSSIADoc();
	DECLARE_DYNCREATE(CMFC_RUSSIADoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_RUSSIADoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_RUSSIADoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_RUSSIADoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_RUSSIADOC_H__3AFA7739_56A3_468B_A24F_1A419BEC82E1__INCLUDED_)
