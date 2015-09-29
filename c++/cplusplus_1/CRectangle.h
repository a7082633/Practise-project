#include "CFigure.h"
class CRectangle :public CFigure
{
	int w;
	int h;
public:
	CRectangle(int ww=0,int hh=0);
	float GetArea();
	char * GetName();
};