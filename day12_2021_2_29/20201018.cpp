#include <iostream>
using namespace std;


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


Date TestDate1(Date d)
{
	Date temp(d);
	temp = d;
	return temp;
}

Date& TestDate2(Date& d)
{
	Date temp(d);
	temp = d;
	return d;
}

Date TestDate3(Date d)
{
	return d;
}

void TestDate()
{
	Date d1(2020, 10, 14);
	//Date d2(d1);

	//d2 = TestDate1(d1);
	//d2 = TestDate2(d1);
	d1 = TestDate3(TestDate3(d1));
}

int main()
{
	TestDate();
	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
		, ra(_day)
		, a(10)
		//, _day(day)
	{
		// ���캯�������Ǹ�ֵ
		_year = year;
		_month = month;
		_day = day;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
	int& ra;
	const int a;
};

int main()
{
	int a = 10;
	int& ra = a;

	const int b = 10;
	return 0;
}
#endif


#if 0
class Time
{
public:
	// �������������Ĺ��캯��
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

	// ����û��������κι��캯��������������������޲εĹ��캯����
	/*Time()
	{
	cout << "Time()" << endl;
	}*/

private:
	int _hour;
	int _minute;
	int _second;
};


class Date
{
public:
	// ע�⣺���캯�����г�ʼ���б�
	// ��ʹ�û�û��д���������Ჹ�ϣ��Ծɻ�ִ�г�ʼ���б�Ĳ���
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
		, t(20,26,30)
		//, t()
	{
		cout << "Date(int,int,int)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time t;
};


int main()
{
	Time t(20,15,30);
	Date d(2020,10,18);
	//Time t;
	return 0;
}
#endif


#if 0
class Date
{
public:

	// ע�⣺��Ա�����ĳ�ʼ�������Ǹ��ݳ�Ա�ڳ�ʼ���б��г��ֵ��Ⱥ�����й�
	// �������Ա���������е������������
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _day(day)
		, _month(_day)

	{
		cout << "Date(int,int,int)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d;
	return 0;
}
#endif


#if 0
class Date
{
public:

	// ע�⣺���ι��캯����������ת��������
	explicit Date(int year = 1900)
		: _year(year)
		, _month(1)
		, _day(1)

	{
		cout << "Date(int,int,int):"<< this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


void TestDate()
{
	Date d1(2020);
	d1 = 2021;
}

int main()
{
	TestDate();
	return 0;
}
#endif


#if 0
void TestStatic()
{
	static int a = 0;
	a++;
	cout << a << endl;
}

int main()
{
	TestStatic();
	TestStatic();
	TestStatic();
	TestStatic();
	return 0;
}
#endif


// ����һ���ഴ���˶��ٸ�����----����int
#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
		, _count(0)
	{
		_count++;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
		, _count(++d._count)
	{
		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
		_count--;
	}

private:
	int _year;
	int _month;
	int _day;

	int _count;
};

#endif



#if 0
// �������ڶ�����---ֻ��һ��

int _count = 0;

// ����ȫ�ֱ�������ʵ�֣�ȱ���ǣ�����λ�ö������޸�
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
		_count--;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2020,10,18);
	Date d2(d1);
}

int main()
{
	Date d(2020, 10, 18);
	TestDate();
	_count = 100;
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++_count;
		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
		_count--;
	}

private:
	int _year;
	int _month;
	int _day;

	static int _count;  // ��̬��Ա����--->����
};


// ע�⣺��̬��Ա����������������г�ʼ��
int Date::_count = 0;

void TestDate()
{
	Date d(2020, 10, 18);
	cout << sizeof(d) << endl;
}

int main()
{
	TestDate();
	return 0;
}