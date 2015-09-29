//#include<stdio.h>
//#include<string.h>
//#include<iostream.h>
//#include<stdlib.h>
//#define MAX_SIZE 999
//void CreateNext(char *patten,int prefix[])
//{
//	prefix[0]=0;
//	int plen=0;
//	plen=strlen(patten);
//	int j=1;
//	int i=0,k=0;
//	while(j<plen)
//	{
//		if(patten[i++]==patten[j])
//		{
//			prefix[j++]=++k;
//		}
//		else if(k>0)
//		{
//			k=0;
//			i=0;
//		}
//		else
//		{
//			prefix[j++]=0;
//			k=0;
//			i=0;
//		}
//	}
//}
//void kpmstr(char* target,char* pattern)
//{
//	int prefix[MAX_SIZE];
//	int tlen=strlen(target);
//	int plen=strlen(pattern);
//	CreateNext(pattern,prefix);
//	for(int k=0;k<plen;k++)
//		printf("%d ",prefix[k]);
//	int count=0;
//	for(int i=0;i<tlen;i++)
//	{
//		int j=0;
//		int p=i;
//		while(target[p++]==pattern[j++])
//			count++;
//		if(count!=0&&count!=plen)
//		{
//			i=i+(count-prefix[count-1]);
//			i--;
//			count=0;
//		}
//		if(count==plen)
//		{
//			printf("find it in :%d!\n",i);
//			exit(0);
//		}
//	}
//	printf("no this string !\n");
//}
//
//
//
//
//
//
//
//
//
//
//
//
//void CptPfFunc( char* Pattern, int PrefixFunc[] )                
//{      
//        register int iLen = 0;    // Length of Pattern[]            
//        while( '\0' != Pattern[iLen] )            
//                iLen++;            
//                    
//        int LOLP = 0;     // Lenth of longest prefix            
//        PrefixFunc[1] = 0;            
//         
//        for( int NOCM=2; NOCM<iLen+1; NOCM++ )     // NOCM represent the number of characters matched            
//        {            
//                while( LOLP>0 && (Pattern[LOLP] != Pattern[NOCM-1]) )      //      l=2 n=7
//                        LOLP = PrefixFunc[LOLP];            
//                if( Pattern[LOLP] == Pattern[NOCM-1] )            
//                        LOLP++;            
//                PrefixFunc[NOCM] = LOLP;            
//        }            
//}
//void KMPstrMatching(char* Target,char* Pattern)            
//{            
//        int PrefixFunc[MAX_SIZE];            
//        register int TarLen = 0;            
//        register int PatLen = 0;            
//         
//        // Compute the length of array Target and Pattern            
//        while( '\0' != Target[TarLen] )            
//                TarLen++;            
//         
//        while( '\0' != Pattern[PatLen] )            
//                PatLen++;            
//                    
//        // Compute the prefix function of Pattern            
//        CptPfFunc(Pattern,PrefixFunc);            
//        int NOCM = 0;     // Number of characters matched            
//        for( int i=0; i<TarLen; i++ )            
//        {            
//                while( NOCM>0 && Pattern[NOCM] != Target[i] )            
//                        NOCM = PrefixFunc[NOCM];            
//                if( Pattern[NOCM] == Target[i] )            
//                        NOCM++;            
//                if( NOCM == PatLen )            
//                {            
//                        cout<<"KMP String Matching,pattern occurs with shift "<<i - PatLen + 1<<endl;            
//                        NOCM = PrefixFunc[NOCM];            
//                }            
//        }            
//}      
//void main()
//{
//	int prefix[MAX_SIZE];
//	kpmstr("BBCABCDABCABCDABCDABDE","ABCDABD");
////	CptPfFunc("abcdaabcab",prefix);
////	for(int i=0;i<17;i++){
////		printf("%d\n",prefix[i]);
////	}
////	int prefix[MAX_SIZE];
////	CreateNext("abcdabd",prefix);
////	for(int i=0;i<10;i++)
////	{
////		printf("%d\n",prefix[i]);
////	}
////	KMPstrMatching("bbcabcdababcdabcdabde","abcdabd") ;
//}