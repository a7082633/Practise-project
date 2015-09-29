#ifndef MY_API
	#define MY_API __declspec(dllimport)
#endif

MY_API
int Max(int a, int b, int c);

MY_API
int Max(int a, int b);

MY_API
int Min(int a, int b, int c);

MY_API
int Min(int a, int b);
