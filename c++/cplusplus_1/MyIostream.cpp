#include <iostream>
#include <cstdlib>
using namespace std;
void MyTerminate();
typedef void (*FXN)();
FXN old=set_terminate(MyTerminate);

void MyTerminate()
{
	cout<<"this is my exception!"<<endl;
	//set_terminate(old);
	exit(0);
}

void fun()
{
	throw "hello dude!";
}

void main()
{
	try
	{
		fun();
	}
	catch(int)
	{
		cout<<"this is system exception!"<<endl;
	}
	//set_terminate(old);
}
//16-7
//#include <exception>
//#include <iostream>
//using namespace std;
//
//typedef void (*Fxn)();
//void Ownterminate();
//
////void (*old_terminate)() = set_terminate(Ownterminate); //设置新的teminate函数，并返回之前teminate函数指针
//Fxn oldFxn = set_terminate(Ownterminate); //设置新的teminate函数，并返回之前teminate函数指针
//
//void Ownterminate()			//自定义terminate函数
//{
//	cout << "严重错误，退出" << endl;
//	set_terminate(oldFxn);	//设置回之前teminate函数
//	exit(0);				//无条件退出
//}
//
//void fun()
//{
//	throw "error";			//抛出字符串类型的异常
//}
//
//int main()
//{
//	try
//	{
//		fun();
//	}
//	catch (int x)			//只定义了捕获int型异常的函数
//	{
//		cout << x << endl;
//	}
//
//	set_terminate(oldFxn);	//设置回之前teminate函数
//	return 0;
//}
//
