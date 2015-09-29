// MFCTestDoc.h : interface of the CMFCTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCTESTDOC_H__9CD52EDD_A6EB_4EBC_9108_228CC06705CD__INCLUDED_)
#define AFX_MFCTESTDOC_H__9CD52EDD_A6EB_4EBC_9108_228CC06705CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCTestDoc : public CDocument
{
protected: // create from serialization only
	CMFCTestDoc();
	DECLARE_DYNCREATE(CMFCTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTESTDOC_H__9CD52EDD_A6EB_4EBC_9108_228CC06705CD__INCLUDED_)
