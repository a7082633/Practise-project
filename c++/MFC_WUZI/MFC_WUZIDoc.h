// MFC_WUZIDoc.h : interface of the CMFC_WUZIDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_WUZIDOC_H__9A3FBAB3_851A_4B45_9E20_81B67CB5C616__INCLUDED_)
#define AFX_MFC_WUZIDOC_H__9A3FBAB3_851A_4B45_9E20_81B67CB5C616__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_WUZIDoc : public CDocument
{
protected: // create from serialization only
	CMFC_WUZIDoc();
	DECLARE_DYNCREATE(CMFC_WUZIDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_WUZIDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_WUZIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_WUZIDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_WUZIDOC_H__9A3FBAB3_851A_4B45_9E20_81B67CB5C616__INCLUDED_)
