// MFC_MiniCadDoc.h : interface of the CMFC_MiniCadDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_MINICADDOC_H__6A078F8D_2254_458C_B6BA_D84DEE26FB27__INCLUDED_)
#define AFX_MFC_MINICADDOC_H__6A078F8D_2254_458C_B6BA_D84DEE26FB27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_MiniCadDoc : public CDocument
{
protected: // create from serialization only
	CMFC_MiniCadDoc();
	DECLARE_DYNCREATE(CMFC_MiniCadDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MiniCadDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	int iNew;
	CObArray m_ObArray;
	virtual ~CMFC_MiniCadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_MiniCadDoc)
	afx_msg void OnEditUndo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MINICADDOC_H__6A078F8D_2254_458C_B6BA_D84DEE26FB27__INCLUDED_)
