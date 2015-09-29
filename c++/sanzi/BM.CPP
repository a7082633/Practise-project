//#include<stdio.h>
//#include<stdlib.h>
//int* MakeSkip(char *ptrn, int pLen)   
//{      
//    int i;   
//    //为建立坏字符表，申请256个int的空间   
//    //PS:之所以要申请256个，是因为一个字符是8位，  
//    // 所以字符可能有2的8次方即256种不同情况  
//    int *skip = (int*)malloc(256*sizeof(int));   
//  
//    if(skip == NULL)   
//    {   
//        fprintf(stderr, "malloc failed!");   
//        return 0;   
//    }      
//  
//    //初始化坏字符表，256个单元全部初始化为pLen   
//    for(i = 0; i < 256; i++)   
//    {   
//        *(skip+i) = pLen;   
//    }   
//  
//    //给表中需要赋值的单元赋值，不在模式串中出现的字符就不用再赋值了   
//    while(pLen != 0)   
//    {   
//        *(skip+(unsigned char)*ptrn++) = pLen--;   
//    }   
////	for(i=0;i<256;i++)
////	{
////		printf("%c : %d\n",i,skip[i]);
////	}
//    return skip;   
//}   
//void main()
//{
//	MakeSkip("AAACCCGHIDO",11);
//}