//功能：实现DES及3DES加解密的算法
//作者：XXX
//日期：2008-9-23
#include <string.h>
#include "des.h"
 
 //对输入的字节串作BCD编码扩展
int ByteToBCD(unsigned char* bytes, int count,unsigned char* strBCD)
{
   unsigned char cTmp;
   int i;
 
   for(i=0;i<count;i++)
  {
      cTmp = (bytes[i] & 0xF0) >> 4;
      strBCD[i*2] = (cTmp > 9) ? cTmp - 10 + 'A' : cTmp + '0';
      cTmp = bytes[i] & 0x0F;
      strBCD[i*2+1] = (cTmp > 9) ? cTmp - 10 + 'A' : cTmp + '0'; 
  }
 
  return (count*2); 
}
 
//把输入的BCD编码串还原成字节串
int BCDToByte(unsigned char* strBCD, int count, unsigned char* bytes)
{
   unsigned char cTmp;
   int i;
 
   for(i=0;i<count/2;i++)
  {
      cTmp = strBCD[i*2];
      if(cTmp >= 'A' && cTmp <= 'F')
          cTmp = cTmp - 'A' + 10;
      else if(cTmp >= 'a' && cTmp <= 'f')
          cTmp = cTmp - 'a' + 10;
      else
          cTmp &= 0x0F;
      bytes[i] = cTmp << 4;
      cTmp = strBCD[i*2+1];
      if(cTmp >= 'A' && cTmp <= 'F')
          cTmp = cTmp - 'A' + 10;
      else if(cTmp >= 'a' && cTmp <= 'f')
          cTmp = cTmp - 'a' + 10;
      else
          cTmp &= 0x0F;
      bytes[i] += cTmp;
  }
 
  return (count/2);
}
 
//把字节串变成比特串
int ByteToBit(unsigned char* bytes, int count, unsigned char* strBit)
{
   unsigned char cTmp;
   int i,j;
 
   for(i=0;i<count;i++)
  {
      cTmp = 0x80;
      for(j=0;j<8;j++)
     {
         strBit[i*8+j] = (bytes[i] & cTmp) >> (7-j);
         cTmp = cTmp >> 1;
     } 
  }
 
  return (count*8); 
}
 
//把比特串变成字节串
int BitToByte(unsigned char* strBit, int count, unsigned char* bytes)
{
    unsigned char cTmp;
    int i,j;
 
    for(i=0;i<(count/8);i++)
   {
       cTmp = 0x00;
       for(j=0;j<8;j++)
      {
          cTmp += (strBit[i*8+j] << (7-j));
      }
      bytes[i] = cTmp; 
   }
 
   return (count/8);
}
 
//做异或操作
int Do_XOR(unsigned char* strSrc, int count, unsigned char* strDest)
{
    int i;
 
    if(strSrc == NULL || strDest == NULL)
    return -1;
  
    for(i=0;i<count;i++)
    strDest[i] ^= strSrc[i];
 
    return 0;
}
 
//des算法PC-1变换，把64比特的密钥K变换成56比特
int Des_PC_1(unsigned char* strIn, unsigned char* strOut)
{
    int i;
 
    for(i=0;i<56;i++)
    strOut[i] = strIn[pc_1_table[i]-1];
 
    return 56; 
}
 
//des算法PC-2变换，把56比特变换成48比特
int Des_PC_2(unsigned char* strIn, unsigned char* strOut)
{
    int i;
 
    for(i=0;i<48;i++)
    strOut[i] = strIn[pc_2_table[i]-1];
 
    return 48;
}
 
//des算法的循环左移位运算
int Des_LS(unsigned char* strIn, int count, unsigned char* strOut)
{
//    int i;
//    for(i=0;i<28;i++)
//    strOut[i] = strIn[(i+count)];
//    return 28; 
	int i;
	for(i=0;i<28;i++) 
	{
		strOut[(i-count+28)%28] = strIn[i];
	}
	return 28;

}
 
//des算法中通过父密钥产生16个48比特位的子密钥
int Des_GenSubKey(unsigned char* strKey, unsigned char strSubKey[16][48+1])
{
    unsigned char tmp[56+1],C0[28+1],D0[28+1],Cx[28+1],Dx[28+1];
    int i;
 
    memset(tmp,0,sizeof(tmp));
    memset(C0,0,sizeof(C0));
    memset(D0,0,sizeof(D0));
    memset(Cx,0,sizeof(Cx));
    memset(Dx,0,sizeof(Dx));
 
    Des_PC_1(strKey, tmp);
 
    memcpy(C0,tmp,28);
    memcpy(D0,tmp+28,28);
 
    for(i=0;i<16;i++)
   {
       Des_LS(C0,ls_num_table[i],Cx);
       Des_LS(D0,ls_num_table[i],Dx);
       memcpy(tmp,Cx,28);
       memcpy(tmp+28,Dx,28);
       Des_PC_2(tmp,strSubKey[i]);
       memcpy(C0,Cx,28);
       memcpy(D0,Dx,28);
   }
 
   return 0;
}
 
//des算法IP置换
int Des_IP(unsigned char* strIn, unsigned char* strOut)
{
    int i;
 
    for(i=0;i<64;i++)
    strOut[i] = strIn[ip_table[i]-1];
  
    return 64;
}
 
//des算法IP-1置换
int Des_IP_1(unsigned char* strIn, unsigned char* strOut)
{
    int i;
 
    for(i=0;i<64;i++)
    strOut[i] = strIn[ip_1_table[i]-1];
  
    return 64;
}
 
//des算法e变换，将32比特变成48比特
int Des_E(unsigned char* strIn, unsigned char* strOut)
{
    int i;
 
    for(i=0;i<48;i++)
        strOut[i] = strIn[e_table[i]-1];
  
    return 48;
}
 
//des算法P变换
int Des_P(unsigned char* strIn, unsigned char* strOut)
{
    int i;
 
    for(i=0;i<32;i++)
        strOut[i] = strIn[p_table[i]-1];
  
    return 32;
}
 
//des算法S盒变换
int Des_S_Box(unsigned char* strIn, int nSBox, unsigned char* strOut)
{
    int x,y,i,nValue;
    unsigned char c;
 
    if(nSBox < 1 || nSBox > 8)
        return -1;
 
    x = strIn[0] * 2 + strIn[5];
    y = strIn[1] * 8 + strIn[2] * 4 + strIn[3] * 2 + strIn[4];
 
    nValue = s_box_table[nSBox-1][x][y];
    c = 0x08;
    for(i=0;i<4;i++)
   {
        strOut[i] = (nValue & c) >> (3 - i);
        c = c >> 1; 
   }
 
   return 4;
}
 
//des算法F函数，对Ri-1和Ki进行运算
int Des_F(unsigned char* strR, unsigned char* strK, unsigned char* strOut)
{
    int i,j;
    unsigned char strAftE[48],strPreP[32],sbIn[8][6],sbOut[8][4];
 
    for(i=0;i<48;i++)
    strAftE[i] = strR[e_table[i]-1];
    Do_XOR(strK, 48, strAftE);
 
    for(i=0;i<8;i++)
        for(j=0;j<6;j++)
           sbIn[i][j] = strAftE[i*6+j];
 
    for(i=0;i<8;i++)
        Des_S_Box(sbIn[i], i+1, sbOut[i]);
  
    for(i=0;i<32;i++)
        strPreP[i] = sbOut[i/4][i%4];
    Des_P(strPreP, strOut);
 
    return 32;
}
//做DES加密或解密运算
int Do_DES(char* strSrc, char* strKey, char* strDest, char flag)
{
   int i;
   unsigned char subKey[16][48+1],byte8[8+1],bits[64+1],strTmp[64+1];
   unsigned char L0[32+1],R0[32+1],Lx[32+1],Rx[32+1];
 
   if(!( flag == 'e' || flag == 'E' || flag == 'd' || flag == 'D'))
       return -1;
   if(strSrc == NULL || strKey == NULL)
       return -2;
 
   if(flag == 'e' || flag == 'E')
  {
       memset(byte8,0,sizeof(byte8));
       BCDToByte((unsigned char *)strKey, 16, byte8);
       memset(bits,0,sizeof(bits));
       ByteToBit(byte8, 8, bits);
  
       Des_GenSubKey(bits,subKey);
  
       BCDToByte((unsigned char *)strSrc, 16, byte8);
       ByteToBit(byte8, 8, bits);
       Des_IP(bits, strTmp);
       memcpy(L0,strTmp,32);
       memcpy(R0,strTmp+32,32);
  
       for(i=0;i<16;i++)
      {
          memcpy(Lx,R0,32);
          Des_F(R0,subKey[i],Rx);
          Do_XOR(L0,32,Rx);
          memcpy(L0,Lx,32);
          memcpy(R0,Rx,32);
      }
      memcpy(bits,R0,32);
      memcpy(bits+32,L0,32);
      Des_IP_1(bits,strTmp);
      BitToByte(strTmp,64,byte8);
      ByteToBCD((unsigned char *)byte8,8,(unsigned char *)strDest);
  }
  else
  {
      memset(byte8,0,sizeof(byte8));
      BCDToByte((unsigned char *)strKey, 16, byte8);
      memset(bits,0,sizeof(bits));
      ByteToBit(byte8, 8, bits);
  
      Des_GenSubKey(bits,subKey);
  
      BCDToByte((unsigned char *)strSrc, 16, byte8);
      ByteToBit(byte8, 8, bits);
      Des_IP(bits, strTmp);
      memcpy(L0,strTmp,32);
      memcpy(R0,strTmp+32,32);
  
      for(i=0;i<16;i++)
     {
         memcpy(Lx,R0,32);
         Des_F(R0,subKey[15-i],Rx);
         Do_XOR(L0,32,Rx);
         memcpy(L0,Lx,32);
         memcpy(R0,Rx,32);
     }
     memcpy(bits,R0,32);
     memcpy(bits+32,L0,32);
     Des_IP_1(bits,strTmp);
     BitToByte(strTmp,64,byte8);
     ByteToBCD(byte8,8,(unsigned char *)strDest);
  }
 
  return 0;
}
 
//做3DES加密或解密运算
int Do_3DES(char* strSrc, char* strKey, char* strDest, char flag)
{ 
   char strBCDKey[32+1];
   char strMidDest1[16+1],strMidDest2[16+1];
   char strLKey[16+1],strRKey[16+1];
   long index=strlen(strSrc)/16;
   if(!( flag == 'e' || flag == 'E' || flag == 'd' || flag == 'D'))
       return -1;
   if(strSrc == NULL || strKey == NULL)
       return -2;
 
   if(strlen(strKey) < 32)
       return -3;
   if(index==0||strlen(strSrc)%8!=0)
	   return -4;
   if(flag == 'e' || flag == 'E')
   {
	  for(int i=0;i<index;i++)
	  {
		  memset(strBCDKey,0,sizeof(strBCDKey));
		  memcpy(strBCDKey,strKey,32);
   
		  memset(strLKey,0,sizeof(strLKey));
		  memcpy(strLKey,strBCDKey,16);
		  memset(strRKey,0,sizeof(strRKey));
		  memcpy(strRKey,strBCDKey+16,16);
   
		  Do_DES(strSrc+i*16,strLKey,strMidDest1,'e');
		  Do_DES(strMidDest1,strRKey,strMidDest2,'d');
		  Do_DES(strMidDest2,strLKey,strMidDest1,'e');
   
		  memcpy(strDest+i*16,strMidDest1,16);
	  }
  }
  else
  {
	  for(int i=0;i<index;i++)
	  {
		  memset(strBCDKey,0,sizeof(strBCDKey));
		  memcpy(strBCDKey,strKey,32);
   
		  memset(strLKey,0,sizeof(strLKey));
		  memcpy(strLKey,strBCDKey,16);
		  memset(strRKey,0,sizeof(strRKey));
		  memcpy(strRKey,strBCDKey+16,16);
   
		  Do_DES(strSrc+i*16,strLKey,strMidDest1,'d');
		  Do_DES(strMidDest1,strRKey,strMidDest2,'e');
		  Do_DES(strMidDest2,strLKey,strMidDest1,'d');
   
		  memcpy(strDest+i*16,strMidDest1,16);
	  }
  }
 
  return 0;
}
 
