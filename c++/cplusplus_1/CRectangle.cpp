#include "CRectangle.h"

CRectangle::CRectangle(int ww,int hh)
{
	w=ww;
	h=hh;
}

float CRectangle::GetArea()
{
	return w*h;
}

char * CRectangle::GetName()
{
	return "¾ØÐÎ";
}