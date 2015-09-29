#include "CPoint3D.h"
#include <iostream>
using namespace std;

CPoint3D::CPoint3D(int xx,int yy,int zz):CPoint(xx,yy)
{
	z=zz;
}
void CPoint3D::show()
{
	CPoint::show();
	cout<<z<<endl;
}