#include "CFigure.h"
class CCircle :public CFigure
{
	int r;
public:
	CCircle(int rr=0);
	float GetArea();
	char * GetName();
};