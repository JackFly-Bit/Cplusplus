#include <iostream>
using namespace std;

#if 0
#define MAX 10
int main()
{
	const int a = 10;
	int b = 20;

	int* pa = (int*)&a; // &a结果的类型 const int* --->表明该地址指向的空间中内容不允许被修改
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
	// 宏在预处理阶段会被宏体来进行替换
	int a = 100;
	a = MAX; //该条语句在预处理阶段已经被修改为： a = 10;
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
//宏的替换发生在预处理阶段--->但是宏不会参与类型检测
//const修饰的常量替换发生在编译阶段--->而const修饰的常量是有类型的，因此会参与类型检测

//宏不会进行类型检测，因此其在预处理阶段已经被替换
#define PI "3.14"

//pi的类型是double类型的 "3.14"是字符串类型 编译阶段知道类型不匹配而报错
const double pi = "3.14";

//一般情况下：在C++中更建议使用const修饰的常量来取代C语言中的宏
//因为：const修饰的内容已经是常量了，而且会参与类型检测，比宏常量使用起来更安全

int main()
{
	int r = 2;

	double s = PI * r * r;//宏替换:s = "3.14" * r * r;

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

	cout << MAX(++b, a) << endl;//该条语句在预处理阶段被替换为：cout << (a > b ? a : b) << endl;
	cout << MAX("hello", a) << endl;
	return 0;
}
#endif
#if 0
//注意：在C++中，一般对于比较短小的函数，建议写成内联函数
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

	//假设：Add函数中5行代码
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);
	Add(a, b);

	printf("%d\n", c);
	//cout << c << endl;

	//在Release版本下，main函数中的5行代码直接被优化成：printf("%d\n",30);
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

//C++11中的语法糖

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

	//pa1和pa2最终打印的都是int*
	//auto定义指针类型变量时，加*和不加* 没有区别
	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;

	int b = 10;
	//rb1是新定义了一个整型的变量
	auto rb1 = b;

	// rb2是b的别名
	auto& rb2 = b;

	//使用auto来定义引用类型变量时，必须要加&的标记
	cout << typeid(rb1).name() << endl;
	cout << typeid(rb2).name() << endl;

	auto a1 = 10, a2 = 20;

	//auto b1 = 10, b2 = 12.34;
	return 0;
}
#endif
#if 0
//auto不能作为函数的参数
//并不是所有的参数都有初始化表达式，因此编译器无法推演a的实际类型
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
	std::map<std::string, std::string> m{ { "apple", "苹果" }, { "orange", "橙子" } };

	std::map<std::string, std::string>::iterator it1 = m.begin();
	auto it2 = m.begin();
	return 0;
}
#endif
#if 0
//array在传参时，实际就是首元素的地址
void Print(int array[])//void Print(int* array)
{
	//代码编译失败--->编译器无法知道array数组的范围
	for (auto e : array)
		cout << e << " ";
	cout << endl;
}
int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	//给数组中的每个元素乘2
	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
		a1[i] *= 2;
	for (int i = 0; i < sizeof(a1) / sizeof(a1[0]); ++i)
		cout << a1[i] << " ";
	cout << endl;

	//在C++11中
	//for循环还可以这么写
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	//范围for循环
	//e： 是对数组中每个元素的引用，修改e实际就是在修改数组中的每个元素
	for (auto& e : array)
		e *= 2;

	//e: 数组中每个元素的一份拷贝，修改e对数组中元素不会有任何的影响
	for (auto e : array)
		cout << e << " ";
	cout << endl;
	return 0;
}
#endif
#if 1

//什么是空值指针--->NULL
//当一个指针没有合法的指向时，最好将该指针置为NULL

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
	TestNullPtr(0); // 0 --->整型 --->TestNullPtr(int)
	TestNullPtr(NULL);// NULL --->在我们的理解中NULL表示空值指针 --->TestNullPtr(int* a)
					  //NULL 是一个宏 #define NULL 0;
	TestNullPtr(nullptr);//最好使用nullptr来代替NULL

	cout << sizeof(nullptr) << endl;
	cout << sizeof((void*)0) << endl;

	//nullptr_t是一种类型，nullptr空值指针的类型就是nullptr_t
	return 0;
}
#endif