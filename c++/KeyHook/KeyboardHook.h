class AFX_EXT_CLASS CKeyboardHook : public CObject  
{
public:
      CKeyboardHook();//钩子类的构造函数

      virtual ~CKeyboardHook();//钩子类的析构函数

public:
      BOOL StartHook(); //安装钩子函数

      BOOL StopHook();//卸载钩子函数 
};