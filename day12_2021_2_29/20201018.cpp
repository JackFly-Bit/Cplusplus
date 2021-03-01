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
		// 构造函数体中是赋值
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
	// 带有三个参数的构造函数
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

	// 如果用户定义了任何构造函数，则编译器不会再生无参的构造函数了
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
	// 注意：构造函数都有初始化列表
	// 即使用户没有写，编译器会补上，仍旧会执行初始化列表的部分
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

	// 注意：成员变量的初始化次序不是根据成员在初始化列表中出现的先后次序有关
	// 而是与成员变量在类中的声明次序相关
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

	// 注意：单参构造函数具有类型转换的作用
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


// 需求：一个类创建了多少个对象----计数int
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
// 不包含在对象中---只有一份

int _count = 0;

// 采用全局变量可以实现，缺陷是：任意位置都可以修改
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

	static int _count;  // 静态成员变量--->声明
};


// 注意：静态成员变量必须在类外进行初始化
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