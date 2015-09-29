//#include <windows.h>
//#include <gdiplus.h>
//#include <stdio.h>
//#pragma comment(lib, "gdiplus.lib")
//using namespace Gdiplus;
//int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
//{	
//	ImageCodecInfo* pImageCodecInfo = NULL;	
//	UINT num, size;	GetImageEncodersSize(&num, &size);	
//	if(size == 0) 
//		return -1;	
//	pImageCodecInfo = (ImageCodecInfo*)malloc(size);	
//	if(pImageCodecInfo == NULL) 
//		return -1;	
//	GetImageEncoders(num, size, pImageCodecInfo);	
//	for(UINT j = 0; j < num; ++j) 
//	{		
//		if(!wcscmp(pImageCodecInfo[j].MimeType, format)) 
//		{			
//			*pClsid = pImageCodecInfo[j].Clsid;			
//			free(pImageCodecInfo);			
//			return j;		
//		}    
//	}	
//	free(pImageCodecInfo);	
//	return -1;
//}
//int main(int argc, char **argv)
//{	
//	if(argc < 3) 
//	{		
//		printf("Usage: %s <input file> <output file>\n", argv[0]);		
//		return 1;	
//	}	
//	GdiplusStartupInput gdiplusStartupInput;	
//	ULONG_PTR gdiplusToken;	
//	CLSID encoderClsid;	
//	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);	
//	if(GetEncoderClsid(L"image/jpeg", &encoderClsid) > 0) 
//	{		
//		WCHAR wcInput[64], wcOutput[64];		
//		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, argv[1], -1, wcInput,  64);		
//		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, argv[2], -1, wcOutput, 64);		
//		Image *image = new Image(wcInput);		
//		Status stat  = image->Save(wcOutput, &encoderClsid, NULL);		
//		if(stat == Ok)			
//			printf("Image converted successfully (output file: %s)!\n", argv[2]);		
//		else			
//			printf("Could not save output file: %s (error:%d)\n", argv[2], stat);		
//		delete image;	
//	} else 
//	{		
//		printf("Failed to acquire the image/jpeg image encoder!");	
//	}	
//	GdiplusShutdown(gdiplusToken);	
//	return 0;
//}