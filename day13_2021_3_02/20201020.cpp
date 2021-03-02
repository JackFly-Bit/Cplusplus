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
		//, _count(0)
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

public:

	static int _count;  // 静态成员变量--->声明
};


// 注意：静态成员变量必须在类外进行初始化
int Date::_count = 0;

int main()
{
	//Date d0;
	//cout << d0._count << endl;

	cout << Date::_count << endl;

	Date d1, d2;
	cout << sizeof(d1) << endl;
	cout << sizeof(d2) << endl;

	cout << &d1._count << endl;
	cout << &d2._count << endl;

	d1._count = 0;
	Date::_count = 0;
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
		//, _count(0)
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

	// 静态成员函数
	static int GetCount();
	//{
	//	//cout << this << endl;
	//	 //_year = 2021;

	//	//PrintDate();
	//	return _count;
	//}

	void TestFunc();
	//{
	//	cout << this << endl;
	//	PrintDate();

	//	cout << _count << endl;
	//	GetCount();
	//}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	/*
	void PrintDate(Date* const this)
	{
	   cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}
	*/

private:
	int _year;
	int _month;
	int _day;
	static int _count;  // 静态成员变量--->声明
};


// 注意：静态成员变量必须在类外进行初始化
int Date::_count = 0;

int main()
{
	// cout << Date::_count << endl;
	Date d;
	d.GetCount();
	d.TestFunc();
	Date::GetCount();
	d.GetCount();
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
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// 将<<重载成类成员函数
	// 重载完成后，发现调用是反的 d<<cout;
	// 因为该函数第一个参数为隐藏的this
	// 不符常规
	// <<重载约定：第一个参数必须是ostream&
	// 因此：<<重载不能重载成类成员函数
	void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	cout << a << endl;

	Date d1(2020, 10, 20);
	d1.PrintDate();

	// cout << d1 << endl;
	//cout << d1;
	d1 << cout;
	d1.operator<<(cout);
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

	friend void Print();

protected:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
private:
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	int GetDay()const
	{
		return _day;
	}

	int GetMonth()const
	{
		return _month;
	}

	int GetYear()const
	{
		return _year;
	}

private:
//public:
	int _year;
	int _month;

protected:
	int _day;

	friend void Print();
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	//_cout << d.GetYear() << "-" << d.GetMonth() << "-" << d.GetDay();
	return _cout;
}

// 要在该函数中直接操作Date类和Time的私有成员
void Print()
{
	Date d;
	cout << d._year << endl;

	Time t;
	cout << t._hour << endl;
}

int main()
{
	cout << 10 << "    " << 12.34 << endl;
	Date d1(2020, 10, 20);
	cout << d1;
	operator<<(cout, d1);
	cout << d1 << 10;
	operator<<(cout, d1) << 10;
	return 0;
}
#endif


#if 0
class Date
{
	friend class Time;
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << " ";
		cout << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

	void TestFriend()
	{
		Date d;
	}

private:
	int _hour;
	int _minute;
	int _second;
};
#endif

#if 0
class A
{
	friend class B;
private:
	int _a;
};

class B
{
	friend class C;
public:
	void TestFriend()
	{
		A a;
		a._a = 10;
	}
private:
	int _b;
};

class C
{
public:
	void TestFriend()
	{
		B b;
		b._b = 10;

		A a;
		a._a = 100;
	}
private:
	int _c;
};

#endif

// 内部类

#if 0
class List
{
public:
	struct ListNode
	{
	public:
		ListNode(int data)
			: next(nullptr)
			, prev(nullptr)
			, _data(data)
		{}

		void TestList()
		{
			// 
			List L;
			L._head = nullptr;
			List::_a = 10;
		}
	private:
		ListNode* next;
		ListNode* prev;
		int _data;
	};

public:
	List()
		:_head(nullptr)
	{}

	void PushBack(int data)
	{
		// 完成链表的尾插操作
		ListNode n(10);
		//n.prev = nullptr;
	}

private:
	ListNode* _head;

	static int _a;
};

int List::_a = 0;


int main()
{
	List::ListNode n(10);
	cout << sizeof(List) << endl;
	return 0;
}
#endif

class List
{
	struct ListNode
	{
		ListNode(int data)
			: _next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}

		ListNode* _next;
		ListNode* _prev;
		int _data;
	};

public:
	List()
		: _head(nullptr)
	{}

	void PushBack(int data)
	{
		ListNode* newNode = new ListNode(data);
		newNode->_next = nullptr;
	}
private:
	ListNode* _head;
	ListNode node;
};


int main()
{
	return 0;
}