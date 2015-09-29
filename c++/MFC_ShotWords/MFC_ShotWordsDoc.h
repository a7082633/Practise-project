// MFC_ShotWordsDoc.h : interface of the CMFC_ShotWordsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_SHOTWORDSDOC_H__390FEC59_5707_440E_8431_6501EEB064E1__INCLUDED_)
#define AFX_MFC_SHOTWORDSDOC_H__390FEC59_5707_440E_8431_6501EEB064E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_ShotWordsDoc : public CDocument
{
protected: // create from serialization only
	CMFC_ShotWordsDoc();
	DECLARE_DYNCREATE(CMFC_ShotWordsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_ShotWordsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_ShotWordsDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_ShotWordsDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SHOTWORDSDOC_H__390FEC59_5707_440E_8431_6501EEB064E1__INCLUDED_)
