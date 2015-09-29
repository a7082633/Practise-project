// MFCRandSeatDoc.h : interface of the CMFCRandSeatDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCRANDSEATDOC_H__860C2852_9D14_4C10_B5F2_A117A104CBF7__INCLUDED_)
#define AFX_MFCRANDSEATDOC_H__860C2852_9D14_4C10_B5F2_A117A104CBF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCRandSeatDoc : public CDocument
{
protected: // create from serialization only
	CMFCRandSeatDoc();
	DECLARE_DYNCREATE(CMFCRandSeatDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCRandSeatDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCRandSeatDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCRandSeatDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCRANDSEATDOC_H__860C2852_9D14_4C10_B5F2_A117A104CBF7__INCLUDED_)
