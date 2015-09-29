// MFC_1Doc.h : interface of the CMFC_1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_1DOC_H__5B8D8780_42AF_4457_A05B_DD60EC5CB89A__INCLUDED_)
#define AFX_MFC_1DOC_H__5B8D8780_42AF_4457_A05B_DD60EC5CB89A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_1Doc : public CDocument
{
protected: // create from serialization only
	CMFC_1Doc();
	DECLARE_DYNCREATE(CMFC_1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_1DOC_H__5B8D8780_42AF_4457_A05B_DD60EC5CB89A__INCLUDED_)
