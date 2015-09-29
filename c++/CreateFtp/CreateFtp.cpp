// CreateFtp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include   <comutil.h> 
#pragma   comment(lib, "comsupp.lib ") 
#include   <Iads.h> 
#include   <Adshlp.h> 
#pragma   comment(lib, "ActiveDS.lib ") 
#pragma   comment(lib, "Adsiid.lib ") 
//refer   to   http://seesi.top263.net/article/adsiiis.htm 

BOOL   CreateVirtualDirectry(LPCTSTR   lpszVirtualDirName,LPCTSTR   lpszDiskPath) 
{ 
	IADsContainer*   iContainer; 
	IADs*   iAds; 
	if(ADsGetObject((LPWSTR)"IIS://localhost/w3svc ",IID_IADsContainer,(void**)&iContainer)==S_OK) 
	{ 
		iContainer-> GetObject(_bstr_t( "IIsWebServer "),   _bstr_t( "1 "),(IDispatch**)&iAds); 
		if(iAds-> QueryInterface(IID_IADsContainer,(void**)&iContainer)==S_OK) 
		{ 
			iContainer-> GetObject(_bstr_t( "IIsWebVirtualDir "),_bstr_t( "Root "),(IDispatch**)&iAds); 
			if(iAds-> QueryInterface(IID_IADsContainer,(void**)&iContainer)==S_OK) 
			{ 
				iContainer-> Delete(_bstr_t( "IIsWebVirtualDir "),   _bstr_t(lpszVirtualDirName)); 
				if(iContainer-> Create(_bstr_t( "IIsWebVirtualDir "),   _bstr_t(lpszVirtualDirName),(IDispatch**)&iAds)==S_OK) 
				{ 
					iAds-> Put(_bstr_t( "AccessRead "),_variant_t( "True ")); 
					iAds-> Put(_bstr_t( "AccessWrite "),_variant_t( "True ")); 
					iAds-> Put(_bstr_t( "Path "),_variant_t(lpszDiskPath)); 
					iAds-> Put(_bstr_t( "AccessExecute "),_variant_t( "False ")); 
					iAds-> SetInfo(); 
					iAds-> Release(); 
					iContainer-> Release(); 
					return   TRUE; 
				} 
				else 
				{ 
					iAds-> Release(); 
					iContainer-> Release(); 
					return   FALSE; 
				} 
			} 
			else 
			{ 
				iAds-> Release(); 
				iContainer-> Release(); 
			} 
		} 
		else 
		{ 
			iAds-> Release(); 
		} 
		iContainer-> Release(); 
	} 
	return   FALSE; 
} 


int main(int argc, char* argv[])
{
	CoInitialize(NULL); 
	CreateVirtualDirectry( "testdir", "d:\\tmp "); 
	CoUninitialize(); 
	return 0;
}
