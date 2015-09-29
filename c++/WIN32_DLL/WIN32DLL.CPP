#define MY_API __declspec(dllexport)

MY_API
int Max(int a, int b, int c)
{
	return (a>b)?(a>c?a:c):(b>c?b:c);
}

MY_API
int Max(int a, int b)
{
	return a>b?a:b;
}

MY_API
int Min(int a, int b, int c)
{
	return (a<b)?(a<c?a:c):(b<c?b:c);
}

MY_API
int Min(int a, int b)
{
	return a<b?a:b;
}