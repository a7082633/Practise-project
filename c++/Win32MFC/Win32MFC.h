#include <afxwin.h>

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CMyWnd : public CFrameWnd
{
public:
	CMyWnd();

protected:
	afx_msg void OnPaint();	//手工声明消息响应函数
	afx_msg void OnCreate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer();
	DECLARE_MESSAGE_MAP()	//手工声明消息映射
};
