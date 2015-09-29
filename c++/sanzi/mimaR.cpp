//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	char pswd[20] = {0};
//	puts("ÇëÊäÈëÃÜÂë: ");	//12 
//
//	int i = 0;
//	while (1)
//	{
//		char c = getch();
//		if (c == '\r')
//		{
//			break;
//		}
//		else if (c == '\b')
//		{
//			if (i > 0)
//			{
//				i--;
//				pswd[i] = 0;
//				printf("\b \b");
//			}
//			else
//			{
//				printf("\a");
//			}
//		}
//		else
//		{
//			pswd[i++] = c;
//			putchar('*');
//		}
//	}
//
//	puts(pswd);
//}
