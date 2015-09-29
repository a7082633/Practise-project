#include "CPoint.h"
class CPoint3D :public CPoint
{
	int z;
public:
	CPoint3D(int xx=0,int yy=0,int zz=0);
	void show();
};