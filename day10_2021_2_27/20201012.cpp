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

	//��Ա��������Ҫͨ�����������е��ã��ڸó�Ա��������֮ǰ��
	//��������Ҫ����ǰ����ĵ�ַͨ��ecx�Ĵ������ݸ���Ա����
	//

	A* pa = &a1;
	pa->TestFunc(); //call A::TestFunc(pa);

	pa = &a2;
	pa->TestFunc(); //call A::TestFunc(pa);

	//ע�⣺pa��A*���͵�ָ�룬Ҳ����˵pa��������ָ��A���͵Ķ���
	//		���paָ��û�кϷ�ָ��ʱ��һ�㶼�ǽ���ָ����Ϊnullptr
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

	//��������ʱ���������Զ����ù��캯��������������һЩ��ʼֵ
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
//�������û����ʽ���幹�캯������C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯����
//һ���û���ʽ�������������������

//�û�û����ʾ�����κι��캯��---��ʾ���û��Լ���û��д
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
	//�Ӹ��
	//Ŀǰ��������û����ʾ���幹�캯�������Ǹ����Ծɿ��Դ������󣬵���������ʱ����������Ҫ�Զ����ù��캯��
	//�ù��캯���������ģ����Ǳ��������ɵ�Ĭ���޲ι��캯��
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
	//�û���ʽ�����˴��в����Ĺ��캯��
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
	//Date�����Ѿ���ʾ�����˴������������Ĺ��캯��
	//��֤�����������᲻�������޲εĹ��캯���أ�

	//����������ͨ����������������������޲εĹ��캯����
	//����������ʧ����û������

	//���뱨��error C2512: "Date" : û�к��ʵ�Ĭ�Ϲ��캯������
	//��������ʾ�����˹��캯��ʱ�������������������޲ε�Ĭ�Ϲ��캯����
	Date d; //����d�����ڼ䣬��������Ҫ�����޲εĹ��캯��
	return 0;
}
#endif
#if 0
//�޲εĹ��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ��
class Date
{
public:
	//�޲ι��캯��
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	//ȫȱʡ���캯��
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

	//���֣��ȿ��Ե����޲ι��캯��������d2;
	//		Ҳ���Ե���ȫȱʡ�Ĺ��캯��������d2
	//�����˶����ԣ��������ͱ�����
	Date d2;
	return 0;
}
#endif
#if 0
/*
1.���û�û����ʾ���幹�캯��ʱ��������������һ���޲ε�Ĭ�Ϲ��캯��
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

	//��������
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
	//��Ա����������ʵ�֣����������ܻὫ�䵱����������������
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//�������캯��
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
//ע�⣺��������漰����Դ����ʱ���������Ҫ��ʽ��������������
//		�����������н��������Դ�ͷŵ�
//		������Դ��й¶��

//ע�⣺���������ɵ�Ĭ�Ͽ������캯���ǰ���ǳ������ʽʵ�ֵ�
//ǳ��������һ�������е�����ԭ�ⲻ���Ŀ�������һ��������
//��������������ͬһ����Դ�������ڶ�������ʱ�÷���Դ���ͷŶ�ζ�����������

//Date��Ŀ������캯���Ƿ�ʵ��û���κ�Ӱ��
//����String�Ŀ������캯����ʵ�ֲ�����---��Ϊ���������ɵ�Ĭ�Ͽ������캯��ʱ����ǳ�����ķ�ʽʵ�ֵ�

//ע�⣺һ����������漰����Դ����ʱ���������캯���Ǳ���Ҫʵ�ֵ�
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	//String��û��ʵ���Լ��Ŀ������캯�����������������һ��
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
	//��Ա����������ʵ�֣����������ܻὫ�䵱����������������
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//�������캯��
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

	//���ø�ֵ��������غ���
	//���һ����û����ʽʵ�ָ�ֵ��������غ������������������һ��Ĭ�ϵ�
	//��ɶ���֮��ĸ�ֵ����

	d1 = d3;

	int a = 10;
	int b = 20;
	a = b;

	return 0;
}
#endif
#if 0
//��������漰����Դ����ʱ����ֵ��������غ�������Ҫ��ʽʵ�ֳ���
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

	//String��û��ʵ���Լ��Ŀ������캯�����������������һ��
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

	//���ÿ������죬����һ���¶���s3
	String s3(s2);

	//�������칹��
	String s4 = s3;

	//���������ɵĸ�ֵ��������ذ���ǳ�����ķ�ʽʵ�ֵ�
	//��������漰����Դ����ʱ���ᵼ���������������
	//�����������⣺
	//1.ǳ��������ɵĺ��һ����Դ����ͷ�����������
	//2.s1ԭ���Ŀռ䶪ʧ��---�ڴ�й¶
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
	//��Ա����������ʵ�֣����������ܻὫ�䵱����������������
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//�������캯��
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

	//�����Զ������ͣ���������֪����ν�����Ӧ������Ĳ���
	//�����Ҫ��������������أ��൱�ڸ��߱�������Ը������͵Ķ�����ν��д�������Ĳ���

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

	//ע�⣺�����������������������
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
