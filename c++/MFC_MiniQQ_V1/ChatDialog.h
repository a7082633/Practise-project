#if !defined(AFX_CHATDIALOG_H__894F7F49_39EC_4FAB_B3E1_999E1241D08C__INCLUDED_)
#define AFX_CHATDIALOG_H__894F7F49_39EC_4FAB_B3E1_999E1241D08C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChatDialog dialog

class CChatDialog : public CDialog
{
// Construction
public:
	CChatDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChatDialog)
	enum { IDD = IDD_FRIENDDIALOG };
	CListBox	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChatDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDIALOG_H__894F7F49_39EC_4FAB_B3E1_999E1241D08C__INCLUDED_)
