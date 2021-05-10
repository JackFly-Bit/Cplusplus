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
	//N: �����͵�ģ�����
	//N: ����ģ������һ������
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
//ģ����ػ�
//ģ�����͵Ĵ���--->�����ĳ��������Դ���
//���Ƕ���ĳЩ���룬���𳡾������ˣ����ߴ������һ������

//����ģ����ػ�---ע�⣺һ������£�����Ҫ�Ժ���ģ������ػ�
template<class T>
const T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

//Max����ģ������ַ���char* �������һ������
const char* Max(const char* left, const char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

//��ģ����ػ�
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

//����������ģ������ػ�
//ǰ�᣺����ģ�����Ҫ�ȴ��� & ���ֳ���

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

//����������ģ������ػ�
//ǰ�᣺����ģ�����Ҫ�ȴ��� & ���ֳ���

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
//��ģ���ػ���
//1.ȫ�ػ�--->��ģ������б������е����Ͳ������廯
//����ڶ�Data����ʵ����ʱ����һ������int,�ڶ���������doubleʱ������ִ��ȫ�ػ��İ汾
//����ִ����ģ��
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
//2.ƫ�ػ�
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

//a.���ֲ������廯
//��ʵ�����ڼ䣬ֻҪ�ڶ���������int���͵ģ�������ƫ�ػ��汾
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

//b.��ģ����������Ƹ����ϸ�
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
	Data<int, int> d1;		//�����ػ�
	Data<int, double> d2;
	Data<double, double> d3;
	Data<double, int> d3;	//�����ػ�

	//ֻҪ������������ָ������,ִ�в������ϸ��ƫ�ػ��汾
	Data<int*, int*> d5;
	Data<int*, double*> d6;
	Data<double*, double*> d7;
	Data<double*, int*> d8;
	return 0;
}
#endif
#if 0
//ʵ��һ��ͨ�õĿ�������
template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	//�ŵ㣺Ч�ʸߣ��ǰ����ֽڵķ�ʽ������
	//ȱ�ݣ�ǳ���������ܻ�������ڴ�й¶
	//memcpy(dst, src, size*sizeof(T));

	//ȱ�ݣ�Ч�ʵ�
	//�ŵ㣺һ���������
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

	//ע��:��������漰����Դ����ʱ���������캯��&��ֵ���������&������������ͬʱ�ṩ
	//�������캯��&��ֵ���������&��������---three big
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	//��ֵ���������:�������س���ĳ�Ա����
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

	//����String���ʹ����������⣺ǳ���� + �ڴ�й¶
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
// plain old data ---->��������
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
		//�ŵ㣺Ч�ʸߣ��ǰ����ֽڵķ�ʽ������
		//ȱ�ݣ�ǳ���������ܻ�������ڴ�й¶
		//��������
		memcpy(dst, src, size*sizeof(T));
	}
	else
	{
		//ȱ�ݣ�Ч�ʵ�
		//�ŵ㣺һ���������
		//�Զ�������
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
//������ȡ����ģ���ػ���Ӧ�ã�
//��Ӧ��������
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

//��Ӧ�Զ�������
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

//��ģ���ػ�
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
	//�ŵ㣺Ч�ʸߣ��ǰ����ֽڵķ�ʽ������
	//ȱ�ݣ�ǳ���������ܻ�������ڴ�й¶
	//��������
	memcpy(dst, src, size*sizeof(T));
}

template<class T>
void Copy(T* dst, const T* src, size_t size, FalseType)
{
	//ȱ�ݣ�Ч�ʵ�
	//�ŵ㣺һ���������
	//�Զ�������
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
		//�ŵ㣺Ч�ʸߣ��ǰ����ֽڵķ�ʽ������
		//ȱ�ݣ�ǳ���������ܻ�������ڴ�й¶
		//��������
		memcpy(dst, src, size*sizeof(T));
	}
	else
	{
		//ȱ�ݣ�Ч�ʵ�
		//�ŵ㣺һ���������
		//�Զ�������
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

	//ע��:��������漰����Դ����ʱ���������캯��&��ֵ���������&������������ͬʱ�ṩ
	//�������캯��&��ֵ���������&��������---three big
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	//��ֵ���������:�������س���ĳ�Ա����
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

	//����String���ʹ����������⣺ǳ���� + �ڴ�й¶
	Copy(s2, s1, 3);
	return 0;
}
#endif
#if 1
//�������

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