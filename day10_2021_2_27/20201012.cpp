#include <iostream>
using namespace std;

#if 0
class A
{
public:
	/*
	void TestFunc(A* const this)
	{
		this->_t = 10;
		cout << this << endl;
	}
	*/

	void Test()
	{
		cout << "A::Test()" << endl;
	}
	void TestFunc()
	{
		//this->_t = 10;

		Test();
		cout << this << endl;
	}

	int _t;
};
int main()
{
	A a1, a2, a3;
	
	a1.TestFunc();//call A::TestFunc(&a1)
	a2.TestFunc();//call A::TestFunc(&a2)
	a3.TestFunc();//call A::TestFunc(&a3)

	//A::TestFunc();

	//成员函数必须要通过对象来进行调用，在该成员函数调用之前，
	//编译器需要将当前对象的地址通过ecx寄存器传递给成员函数
	//

	A* pa = &a1;
	pa->TestFunc(); //call A::TestFunc(pa);

	pa = &a2;
	pa->TestFunc(); //call A::TestFunc(pa);

	//注意：pa是A*类型的指针，也就是说pa将来可以指向A类型的对象
	//		如果pa指针没有合法指向时，一般都是将该指针置为nullptr
	pa = nullptr;
	pa->TestFunc();
	return 0;
}
#endif
#if 0
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	//d._year = 2020;

	d1.SetDate(2020, 10, 11);
	d1.PrintDate();

	Date d2;
	d2.SetDate(2020, 10, 12);
	d2.PrintDate();

	Date d3;
	d3.SetDate(2020, 10, 12);
	d3.PrintDate();

	//Date d4(2020, 10, 13);
	//d4.PrintDate();

	int a;
	a = 10;
	cout << a << endl;

	int b = 10;
	cout << b << endl;

	int c(20);
	cout << c << endl;
	return 0;
}
#endif
#if 0
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;		
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;

		cout << "Date(int, int, int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2020, 10, 11);
	d1.PrintDate();

	//创建对象时，编译器自动调用构造函数，给对象设置一些初始值
	Date d2;
	d2.PrintDate();

	Date d3();
}

int main()
{
	TestDate();
	return 0;
}
#endif
#if 0
//如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，
//一旦用户显式定义编译器将不再生成

//用户没有显示定义任何构造函数---显示：用户自己有没有写
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;

		cout << "Date(int, int, int):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//从概念：
	//目前日期类中没有显示定义构造函数，但是该类仍旧可以创建对象，当创建对象时，编译器需要自动调用构造函数
	//该构造函数哪里来的，就是编译器生成的默认无参构造函数
	Date d;
	return 0;
}
#endif
#if 0
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}

	void PrintTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	//用户显式定义了带有参数的构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

	Time _t;
};

int main()
{
	//Date类中已经显示定义了带有三个参数的构造函数
	//验证：编译器还会不会生成无参的构造函数呢？

	//如果代码可以通过编译则编译器可以生成无参的构造函数了
	//如果代码编译失败则没有生成

	//编译报错：error C2512: "Date" : 没有合适的默认构造函数可用
	//当类中显示定义了构造函数时，编译器不会再生成无参的默认构造函数了
	Date d; //创建d对象期间，编译器需要调用无参的构造函数
	return 0;
}
#endif
#if 0
//无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个
class Date
{
public:
	//无参构造函数
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	//全缺省构造函数
	Date(int year = 1900, int month = 1, int day =1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2020, 10, 11);

	//发现：既可以调用无参构造函数来创建d2;
	//		也可以调用全缺省的构造函数来创建d2
	//产生了二义性，编译器就报错了
	Date d2;
	return 0;
}
#endif
#if 0
/*
1.当用户没有显示定义构造函数时，编译器会生成一个无参的默认构造函数
*/
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
		cout << "Iime(int,int,int)" << endl;
	}

	void PrintTime()
	{
		cout << _hour << ":" << _minute << ":" << _second << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

	Time _t;
};
int main()
{
	Date d;
	return 0;
}
#endif
#if 0
typedef int DataType;

class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);

		_capacity = capacity;
		_size = 0;
	}

	//析构函数
	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}

	}

	void PushBack(DataType data)
	{
		//...
	}

	void PopBack()
	{
		if (!Empty())
		{
			_size--;
		}
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}

	bool Empty()
	{
		return _size == 0;
	}

	// ...
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};

void TestSeqList()
{
	SeqList s;
	s.PushBack(10);
	s.PushBack(10);
	s.PushBack(10);

	s.PopBack();
}

int main()
{
	TestSeqList();
	return 0;
}
#endif
#if 0
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};

class Person
{
private:
	String _name;
	int _age;
};

void TestPerson()
{
	Person p;
}

int main()
{
	TestPerson();

	String s("hello world");
	return 0; 
}
#endif
#if 0
class Date
{
public:
	//成员函数在类内实现，编译器可能会将其当成内联函数来处理
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&) : " << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d0;
	Date d1(2020, 10, 12);
	Date d2(d1);

	int a;
	int b = 10;
	int c = b;
	int d(c);

	return 0;
}
#endif
#if 0
//注意：如果类中涉及到资源管理时，该类必须要显式调用析构函数，
//		在析构函数中将对象的资源释放掉
//		否则：资源就泄露了

//注意：编译器生成的默认拷贝构造函数是按照浅拷贝方式实现的
//浅拷贝：将一个对象中的内容原封不动的拷贝到另一个对象中
//后果：多个对象共享同一份资源，最终在对象销毁时该份资源被释放多次而引起代码崩溃

//Date类的拷贝构造函数是否实现没有任何影响
//但是String的拷贝构造函数不实现不可以---因为编译器生成的默认拷贝构造函数时按照浅拷贝的方式实现的

//注意：一个类中如果涉及到资源管理时，拷贝构造函数是必须要实现的
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	//String类没有实现自己的拷贝构造函数，则编译器会生成一份
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString()
{
	String s1("hello world");
	String s2(s1);
}

int main()
{
	TestString();
	return 0;
}
#endif
#if 0
class Date
{
public:
	//成员函数在类内实现，编译器可能会将其当成内联函数来处理
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&) : " << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d0;
	Date d1(2020, 10, 12);
	Date d2(d1);
	Date d3(2020, 10, 13);

	//调用赋值运算符重载函数
	//如果一个类没有显式实现赋值运算符重载函数，则编译器会生成一份默认的
	//完成对象之间的赋值操作

	d1 = d3;

	int a = 10;
	int b = 20;
	a = b;

	return 0;
}
#endif
#if 0
//如果类中涉及到资源管理时，赋值运算符重载函数必须要显式实现出来
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	String(const String& s)
	{
		cout << "String(const String& s):" << this << endl;
	}

	//String类没有实现自己的拷贝构造函数，则编译器会生成一份
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2("world");

	//调用拷贝构造，构造一个新对象s3
	String s3(s2);

	//拷贝构造构造
	String s4 = s3;

	//编译器生成的赋值运算符重载按照浅拷贝的方式实现的
	//如果类中涉及到资源管理时，会导致以下两个后果：
	//存在两个问题：
	//1.浅拷贝：造成的后果一份资源多次释放引起代码崩溃
	//2.s1原来的空间丢失了---内存泄露
	s1 = s2;
}
int main()
{
	TestString();
	return 0;
}
#endif
#if 1
class Date
{
public:
	//成员函数在类内实现，编译器可能会将其当成内联函数来处理
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&) : " << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool IsLess(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}
		return false;
	}

	//对于自定义类型，编译器不知道如何进行相应运算符的操作
	//因此需要对运算符进行重载，相当于告诉编译器针对该种类型的对象如何进行此运算符的操作

	bool operator<(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}

		return false;
	}

	//==
	bool operator==(/*Date* const this*/const Date& d)
	{
		return _year == d._year &&
			 _month == d._month &&
			 _day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	//注意：不能臆造运算符来进行重载
	//void operator@()
	//{

	//}

	Date operator+(int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
		//_day += days;
		//return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

enum Data
{
	ONE, TWO, THREE
};

//int operator+(Data a, int b)
//{
//	return a + b;
//}

int main()
{
	Date d1(2020, 10, 12);
	Date d2(2020, 10, 13);

	int a = 10;
	int b = 20;
	if (a < b)
	{
		cout << "a < b" << endl;
	}
	else
	{
		cout << "a >= b" << endl;
	}

	if(d1 < d2)
	{
		cout << "d1 < d2" << endl;
	}
	else
	{
		cout << "d1 >= d2" << endl;
	}

	if (d1.IsLess(d2))
	{
		cout << "d1 < d2" << endl;
	}
	else
	{
		cout << "d1 >= d2" << endl;
	}

	if (d1 != d2)
	{
		cout << "d1 != d2" << endl;
	}
	else
	{
		cout << "d1 == d2" << endl;
	}

	a + 10;
	d1 + 10;

	d2 = d1 + 2;
	return 0;
}

#endif
#if 0
int main()
{
	return 0;
}
#endif
