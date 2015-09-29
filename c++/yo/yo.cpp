// yo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int n = 0;
	printf("%d %d %d", ++(++n), ++(++n), ++(++n));
	return 0;
}

