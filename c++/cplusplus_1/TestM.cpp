#include <iostream>
using namespace std;
void getMax(char *str,char ch)
{
	int max=0;
	int count=0;
	while(*str)
	{
		if(*str==ch)
		{
			count++,str++;
			while(*str==ch)
			{
				count++;
				++str;
			}
			if(count>max)
			{
				max=count;
				count=0;
			}
			count=0;
		}
		str++;
	}
	cout<<max<<endl;
}
int search(char *cpSource, int n, char ch)
{
	int i=0;
	if(*cpSource==NULL) return 0;
	while(i<n)
	{
		if(*cpSource==ch)
			return i;
		cpSource++;
		i++;
	}
	return 0;
}
void main()
{
	
}