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
	afx_msg void OnPaint();	//�ֹ�������Ϣ��Ӧ����
	afx_msg void OnCreate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer();
	DECLARE_MESSAGE_MAP()	//�ֹ�������Ϣӳ��
};
