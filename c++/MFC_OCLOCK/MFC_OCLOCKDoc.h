// MFC_OCLOCKDoc.h : interface of the CMFC_OCLOCKDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_OCLOCKDOC_H__5557DF66_F7E7_4E22_80B6_9BDE71866500__INCLUDED_)
#define AFX_MFC_OCLOCKDOC_H__5557DF66_F7E7_4E22_80B6_9BDE71866500__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_OCLOCKDoc : public CDocument
{
protected: // create from serialization only
	CMFC_OCLOCKDoc();
	DECLARE_DYNCREATE(CMFC_OCLOCKDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_OCLOCKDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFC_OCLOCKDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_OCLOCKDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_OCLOCKDOC_H__5557DF66_F7E7_4E22_80B6_9BDE71866500__INCLUDED_)
