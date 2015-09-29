
#include <iostream.h>
#include "Date.h"
class CStu
{
friend ostream& operator<<(ostream &os,CStu &s);
//{
//	os<<s.iNo<<" "<<s.SName<<" "<<s.iAge<<" "<<(s.BSex?"ÄÐ":"Å®")<<endl;
//	return os;
//}
friend void output_my(CStu &s);

private:
	char *SName;
	int iNo;
	int iAge;
	bool BSex;
	Date date;
	static int count;
public:
	CStu(int no=0 ,int age=0, bool sex=true,char *name="sucker");
	CStu(const CStu &s);
	void GetV();
	char* GetName();
	static void TStatic();
	void TFriend(const Date &date);
	CStu operator+(const CStu &s1);
	CStu operator-(const CStu &s1);
	CStu operator++();
	CStu operator--();
	CStu operator++(int);
	CStu operator--(int);
	CStu& operator=(const CStu &s);
	~CStu();
};

