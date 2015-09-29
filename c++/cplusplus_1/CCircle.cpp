#include "CCircle.h"
const float PI=3.14f;
CCircle::CCircle(int rr)
{
	r=rr;
}

float CCircle::GetArea()
{
	return PI*r*r;
}

char * CCircle::GetName()
{
	return "т╡пн";
}