
class Date
{
	friend class CStu;
	int m_iYear;
	int m_iMonth;
	int m_iDay;
public:
	//explicit
	Date(int year=2012,int month=1,int day=1);
	void show();
	void AddDay();
	Date &operator=(Date &date);
	Date &operator++();
	Date &operator++(int);
	Date &operator--();
	Date &operator--(int);
	void operator+=(const Date &date);
	void operator-=(const Date &date);
	int operator-(const Date &date);
	operator int();//强转整形
	operator float();
	operator CStu();
	~Date();
};