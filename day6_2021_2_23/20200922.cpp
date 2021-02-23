#include <iostream>
using namespace std;

#if 0
#define MAX 10
int main()
{
	const int a = 10;
	int b = 20;

	int* pa = (int*)&a; // &a��������� const int* --->�����õ�ַָ��Ŀռ������ݲ������޸�
	*pa = 100;

	//printf("%d\n", *&a);// *&a<==>a
	printf("%d\n", MAX);
	printf("%d\n", a);
	printf("%d\n", b);

	//cout << a << endl;
	cout << *pa << endl;
	return 0;
}
#endif
#if 0
#define MAX 10
int main()
{
	// ����Ԥ����׶λᱻ�����������滻
	int a = 100;
	a = MAX; //���������Ԥ����׶��Ѿ����޸�Ϊ�� a = 10;
	return 0;
}
#endif
#if 0
int main()
{
	const int a = 10;
	int* pa = (int*)&a;

	printf("%d\n", a);
	printf("%d\n", *pa);

	return 0;
}
#endif
#if 0
int main()
{
	const int a = 10;
	int array[a];
	//a = 10;

	return 0;
}
#endif
#if 0
//����滻������Ԥ����׶�--->���Ǻ겻��������ͼ��
//const���εĳ����滻�����ڱ���׶�--->��const���εĳ����������͵ģ���˻�������ͼ��

//�겻��������ͼ�⣬�������Ԥ����׶��Ѿ����滻
#define PI "3.14"

//pi��������double���͵� "3.14"���ַ������� ����׶�֪�����Ͳ�ƥ�������
const double pi = "3.14";

//һ������£���C++�и�����ʹ��const���εĳ�����ȡ��C�����еĺ�
//��Ϊ��const���ε������Ѿ��ǳ����ˣ����һ�������ͼ�⣬�Ⱥ곣��ʹ����������ȫ

int main()
{
	int r = 2;

	double s = PI * r * r;//���滻:s = "3.14" * r * r;

	double s = pi * r * r;
	return 0;
}
#endif
#if 0
#define MAX(a,b) (a > b ? a : b)

int main()
{
	int a = 10;
	int b = 20;

	cout << MAX(++b, a) << endl;//���������Ԥ����׶α��滻Ϊ��cout << (a > b ? a : b) << endl;
	cout << MAX("hello", a) << endl;
	return 0;
}
#endif
#if 0
//ע�⣺��C++�У�һ����ڱȽ϶�С�ĺ���������д����������
inline int Add(int left, int right)
{
	return left + right;
}

inline void TestInline()
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", i);
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", i);
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", i);
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", i);
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", i);
	}
}

inline int Fac(int N)
{
	if (0 == N)
		return 1;

	return Fac(N - 1)*N;
}

int main()
{
	int a = 10;
	int b = 20;

	int c = 0;
	c = Add(a, b);

	//���裺Add������5�д���
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);

	printf("%d\n", c);
	//cout << c << endl;

	//��Release�汾�£�main�����е�5�д���ֱ�ӱ��Ż��ɣ�printf("%d\n",30);
	TestInline();
	Fac(5);
	return 0;
}
#endif
#if 0
#include "Add.h"
int main()
{
	Add(10, 20);
	return 0;
}
#endif
#if 0
inline int Max(int left, int right)
{
	return left > right ? left : right;
}
int main()
{
	int a = 10;
	int b = 20;

	int c = 0;

	c = Max(++b, a);
	cout << c << endl;
	return 0;
}
#endif
#if 0

//C++11�е��﷨��

//auto
int Add(int left, int right)
{
	return left + right;
}
int main()
{
	int a = 10;

	auto b = a;
	auto c = 'c';
	auto d = 12.34;
	auto r = Add(10, 20);

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(r).name() << endl;

	//auto aa;
	return 0;
}
#endif
#if 0
int main()
{
	int a = 10;

	auto* pa1 = &a;
	auto  pa2 = &a;

	//pa1��pa2���մ�ӡ�Ķ���int*
	//auto����ָ�����ͱ���ʱ����*�Ͳ���* û������
	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;

	int b = 10;
	//rb1���¶�����һ�����͵ı���
	auto rb1 = b;

	// rb2��b�ı���
	auto& rb2 = b;

	//ʹ��auto�������������ͱ���ʱ������Ҫ��&�ı��
	cout << typeid(rb1).name() << endl;
	cout << typeid(rb2).name() << endl;

	auto a1 = 10, a2 = 20;

	//auto b1 = 10, b2 = 12.34;
	return 0;
}
#endif
#if 0
//auto������Ϊ�����Ĳ���
//���������еĲ������г�ʼ�����ʽ����˱������޷�����a��ʵ������
//void TestAuto(auto a)
//{
//	printf("%d", a);
//}
int main()
{
	int array1[] = { 1, 2, 3 };

	//auto array2[] = { 3, 4, 5 };

	return 0;
}
#endif
#if 0
#include <map>
#include <string>

int main()
{
	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "orange", "����" } };

	std::map<std::string, std::string>::iterator it1 = m.begin();
	auto it2 = m.begin();
	return 0;
}
#endif
#if 0
//array�ڴ���ʱ��ʵ�ʾ�����Ԫ�صĵ�ַ
void Print(int array[])//void Print(int* array)
{
	//�������ʧ��--->�������޷�֪��array����ķ�Χ
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}
int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	//�������е�ÿ��Ԫ�س�2
	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
		a1[i] *= 2;
	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
		cout << a1[i] << " ";
	cout << endl;

	//��C++11��
	//forѭ����������ôд
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	//��Χforѭ��
	//e�� �Ƕ�������ÿ��Ԫ�ص����ã��޸�eʵ�ʾ������޸������е�ÿ��Ԫ��
	for (auto& e : array)
		e *= 2;

	//e: ������ÿ��Ԫ�ص�һ�ݿ������޸�e��������Ԫ�ز������κε�Ӱ��
	for (auto e : array)
		cout << e << " ";
	cout << endl;
	return 0;
}
#endif
#if 1

//ʲô�ǿ�ֵָ��--->NULL
//��һ��ָ��û�кϷ���ָ��ʱ����ý���ָ����ΪNULL

void TestNullPtr(int a)
{
	cout << "TestNullPtr(int)" << endl;
}

void TestNullPtr(int* a)
{
	cout << "TestNullPtr(int)" << endl;
}

int main()
{
	TestNullPtr(0); // 0 --->���� --->TestNullPtr(int)
	TestNullPtr(NULL);// NULL --->�����ǵ������NULL��ʾ��ֵָ�� --->TestNullPtr(int* a)
					  //NULL ��һ���� #define NULL 0;
	TestNullPtr(nullptr);//���ʹ��nullptr������NULL

	cout << sizeof(nullptr) << endl;
	cout << sizeof((void*)0) << endl;

	//nullptr_t��һ�����ͣ�nullptr��ֵָ������;���nullptr_t
	return 0;
}
#endif