#include <iostream>
using namespace std;

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

#if 0
/*
int Add<int>(const int& left, const int& right)
{
	return left + right;
}
*/
int main()
{
	Add(1, 2);//int int
	return 0;
}
#endif
#if 0
int g_a = 10;
int g_b = 20;

namespace bite
{
	//N: 非类型的模板参数
	//N: 在类模板中是一个常量
	template<class T, size_t N>
	class array
	{
	public:
		array()
			: _size(0)
		{
			//N = 100;
		}

	private:
		T _array[N];
		size_t _size;
	};
}

int main()
{
	bite::array<int, 10> arr;

	bite::array<int, g_a + g_b> arr1;
	return 0;
}
#endif
#if 0
//模板的特化
//模板类型的代码--->基本的场景都可以处理
//但是对于某些代码，个别场景处理不了，或者处理就是一个错误

//函数模板的特化---注意：一般情况下，不需要对函数模板进行特化
template<class T>
const T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

//Max函数模板对于字符串char* 处理就是一个错误
const char* Max(const char* left, const char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

//类模板的特化
int main()
{
	Max(1, 2);
	Max(1.0, 2.0);

	const char* str1 = "hello";
	const char* str2 = "World";

	//str1[0] = 'H';

	cout << Max(str1, str2) << endl;//const char*	const char*
	return 0;
}
#endif
#if 0
template<class T>
const T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

//对上述函数模板进行特化
//前提：函数模板必须要先存在 & 哪种场景

//char*

template<>
const char* & Max<const char*>(const char*& left, const char*& right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

int main()
{
	const char* str1 = "hello";
	const char* str2 = "World";

	cout << Max(str1, str2) << endl;//const char*	const char*
	return 0;
}
#endif
#if 0
template<class T>
T& Max(T& left, T& right)
{
	return left > right ? left : right;
}

//对上述函数模板进行特化
//前提：函数模板必须要先存在 & 哪种场景

//char*

template<>
char* & Max<char*>(char*& left, char*& right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

int main()
{
	char* str1 = "hello";
	char* str2 = "World";

	cout << Max(str1, str2) << endl;//const char*	const char*
	return 0;
}
#endif
#if 0
template<class T>
void TestPtr(const T p)
{
	*p = 100;
	//p = nullptr;
}
int main()
{
	int a = 10;
	int* pa = &a;

	TestPtr(pa);

	const int b1 = 10;
	int const b2 = 20;

	return 0;
}
#endif
#if 0
//类模板特化：
//1.全特化--->将模板参数列表中所有的类型参数具体化
//如果在对Data进行实例化时，第一个参数int,第二个参数是double时，都会执行全特化的版本
//否则执行类模板
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1, T2>()" << endl;
	}

private:
	T1 _d1;
	T2 _d2;
};

template<>
class Data<int, double>
{
public:
	Data()
	{
		cout << "Data<int, double>()" << endl;
	}

private:
	int _d1;
	double _d2;

};

int main()
{
	Data<int, int> d1;
	Data<int, double> d2;
	Data<double, double> d3;
	return 0;
}
#endif
#if 0
//2.偏特化
template<class T1, class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1, T2>()" << endl;
	}

private:
	T1 _d1;
	T2 _d2;
};

//a.部分参数具体化
//在实例化期间，只要第二个参数是int类型的，都会走偏特化版本
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "Data<T1, int>()" << endl;
	}

private:
	T1 _d1;
	int _d2;
};

//b.让模板参数的限制更加严格
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "Data<T1*, T2*>()" << endl;
	}

private:
	T1* _d1;
	T2* _d2;
};

int main()
{
	Data<int, int> d1;		//部分特化
	Data<int, double> d2;
	Data<double, double> d3;
	Data<double, int> d3;	//部分特化

	//只要两个参数都是指针类型,执行参数更严格的偏特化版本
	Data<int*, int*> d5;
	Data<int*, double*> d6;
	Data<double*, double*> d7;
	Data<double*, int*> d8;
	return 0;
}
#endif
#if 0
//实现一个通用的拷贝函数
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	//优点：效率高，是按照字节的方式拷贝的
	//缺陷：浅拷贝，可能还会造成内存泄露
	//memcpy(dst, src, size*sizeof(T));

	//缺陷：效率低
	//优点：一定不会出粗
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//注意:如果类中涉及到资源管理时，拷贝构造函数&赋值运算符重载&析构函数必须同时提供
	//拷贝构造函数&赋值运算符重载&析构函数---three big
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	//赋值运算符重载:必须重载成类的成员函数
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}

		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		return *this;
	}

private:
	char* _str;
};

int main()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[sizeof(array1) / sizeof(array1[0])];
	Copy(array2, array1, 10);

	String s1[] = { "1111", "2222", "3333" };
	String s2[3];

	//对于String类型存在两个问题：浅拷贝 + 内存泄露
	Copy(s2, s1, 3);
	return 0;
}
#endif
#if 0
int i;
int main()
{
	i--;
	if (i > sizeof(i))
	{
		cout << ">" << endl;
	}
	else
	{
		cout << "<" << endl;
	}
	return 0;
}
#endif
#if 0
// plain old data ---->内置类型
bool isPODType(const string& strtype)
{
	string types[] = { "char", "short", "int", "long", "long long" };
	for (auto e : types)
	{
		if (e == strtype)
			return true;
	}

	return false;
}

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	cout << typeid(T).name() << endl;

	if (isPODType(typeid(T).name()))
	{
		//优点：效率高，是按照字节的方式拷贝的
		//缺陷：浅拷贝，可能还会造成内存泄露
		//内置类型
		memcpy(dst, src, size*sizeof(T));
	}
	else
	{
		//缺陷：效率低
		//优点：一定不会出粗
		//自定义类型
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}

int main()
{
	return 0;
}
#endif
#if 0
//类型萃取（类模板特化的应用）
//对应内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

//对应自定义类型
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;
};

//类模板特化
template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType PODTYPE;
};

//...

template<class T>
void Copy(T* dst, const T* src, size_t size, TrueType)
{
	//优点：效率高，是按照字节的方式拷贝的
	//缺陷：浅拷贝，可能还会造成内存泄露
	//内置类型
	memcpy(dst, src, size*sizeof(T));
}

template<class T>
void Copy(T* dst, const T* src, size_t size, FalseType)
{
	//缺陷：效率低
	//优点：一定不会出粗
	//自定义类型
	for (size_t i = 0; i < size; ++i)
		dst[i] = src[i];
}

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::PODTYPE)
}

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::PODTYPE::Get())
	{
		//优点：效率高，是按照字节的方式拷贝的
		//缺陷：浅拷贝，可能还会造成内存泄露
		//内置类型
		memcpy(dst, src, size*sizeof(T));
	}
	else
	{
		//缺陷：效率低
		//优点：一定不会出粗
		//自定义类型
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//注意:如果类中涉及到资源管理时，拷贝构造函数&赋值运算符重载&析构函数必须同时提供
	//拷贝构造函数&赋值运算符重载&析构函数---three big
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	//赋值运算符重载:必须重载成类的成员函数
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}

		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		return *this;
	}

private:
	char* _str;
};

int main()
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int array2[sizeof(array1) / sizeof(array1[0])];
	Copy(array2, array1, 10);

	String s1[] = { "1111", "2222", "3333" };
	String s2[3];

	//对于String类型存在两个问题：浅拷贝 + 内存泄露
	Copy(s2, s1, 3);
	return 0;
}
#endif
#if 1
//分离编译

#include "aa.h"

#include "aa.hpp"

int main()
{
	Add(1, 2);

	Sub(20, 10);	//Sub<int>???
	Sub(2.0, 1.0);	//Sub<int>???
	Sub('2', '1');

	Mul(1, 2);
	Mul(1.0, 2.0);
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif