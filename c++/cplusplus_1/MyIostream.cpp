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
////void (*old_terminate)() = set_terminate(Ownterminate); //�����µ�teminate������������֮ǰteminate����ָ��
//Fxn oldFxn = set_terminate(Ownterminate); //�����µ�teminate������������֮ǰteminate����ָ��
//
//void Ownterminate()			//�Զ���terminate����
//{
//	cout << "���ش����˳�" << endl;
//	set_terminate(oldFxn);	//���û�֮ǰteminate����
//	exit(0);				//�������˳�
//}
//
//void fun()
//{
//	throw "error";			//�׳��ַ������͵��쳣
//}
//
//int main()
//{
//	try
//	{
//		fun();
//	}
//	catch (int x)			//ֻ�����˲���int���쳣�ĺ���
//	{
//		cout << x << endl;
//	}
//
//	set_terminate(oldFxn);	//���û�֮ǰteminate����
//	return 0;
//}
//
