class AFX_EXT_CLASS CKeyboardHook : public CObject  
{
public:
      CKeyboardHook();//������Ĺ��캯��

      virtual ~CKeyboardHook();//���������������

public:
      BOOL StartHook(); //��װ���Ӻ���

      BOOL StopHook();//ж�ع��Ӻ��� 
};