#include<iostream>
using namespace std;

#if 0
int main()
{
	//cout << "hello world" << endl;
	std::cout << "hello world" << std:: endl;
	return 0;
}
#endif

//没有返回值，也没有参数
//在C语言中：以下代码可以通过编译
//在C++语言中：以下代码不能通过编译
//C++编译器比C语言编译器语法检测更加严格
#if 0
void TestFunc()
{

}
int main()
{
	TestFunc();
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10, 20, 30);
	return 0;
}
#endif

#if 0
#include <stdio.h>

//在C语言中：以下函数可以通过编译，因为没有显式写返回值类型时，C语言编译器默认函数返回int
//在C++中：以下函数不能通过编译
//C++编译器比C语言编译器语法检测更加严格
TestFunc(void)
{}

int main()
{
	int ret = TestFunc();
	printf("%d\n", ret);
	return 0;
}
#endif

#if 0
#include <stdio.h>

//缺省参数：在定义函数时，可以给函数的参数带上一些默认值
//在调用该函数时，如果没有指定实参则采用该默认值，否则使用指定的实参
void TestFunc(int a=10, int b=20)
{
	printf("%d %d\n", a, b);
}

int main()
{
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	TestFunc(10, 20);
	//上述调用中，每次调用传递的都是同一组实参
	//不想传递，但是让该函数执行起来后，还可以拿到10，20
	TestFunc();
	TestFunc(30, 40);
	TestFunc(300, 400);

	return 0;
}
#endif

#if 0
//分类：
//1.全缺省参数：每个参数都带有默认值
void TestFunc(int a = 1, int b = 2, int c = 3)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
int main()
{
	TestFunc();//1 2 3 
	TestFunc(10);//10 2 3
	TestFunc(10, 20);// 10 20 3
	TestFunc(10, 20, 30);//10 20 30
	return 0;
}
#endif

#if 0
//2.半缺省参数：部分参数带有默认值
// a	b	c
// 0	1	1	代码可以通过编译
// 1	0	1	代码编译失败
// 1	1	0	代码编译失败
// 0	0	1	代码可以通过编译
//结论：只能从右往左依次给出
void TestFunc(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}
int main()
{
	TestFunc(10);//10 2 3
	TestFunc(10, 20);// 10 20 3
	TestFunc(10, 20, 30);//10 20 30
	return 0;
}
#endif

#if 0
//缺省参数可以在声明位置给出，也可以在定义位置给出
//但是不能两个位置同时给出
//疑问：在声明的位置给好？还是定义的位置给好？

int g_a = 10;

void TestFunc(int a = g_a);

void TestFunc(int a = 10)
{
	cout << a << endl;
}
int main()
{

	return 0;
}
#endif

#if 0
//函数重载：
//概念：在相同作用域中，函数名字必须要相同，参数列表必须要不同(个数，类型，类型次序)
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
//参数列表不同的体现：
//1.参数个数不同
//2.参数类型不同
//3.参数类型的次序不同
void TestFunc()
{}
//int TestFunc()
//{
//	return 0;
//}
void TestFunc(int a)
{}
void TestFunc(char c)
{}
void TestFunc(int a, char b)
{}
void TestFunc(char b, int a)
{}
int main()
{
	Add(10, 20);//int 
	Add(1.2, 3.4);//double
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
//函数重载的调用原理:
//函数重载一定是在编译阶段具体来确定应该调用哪个函数
//编译器在编译阶段，会对函数实参类型进行推演，根据推演的实际结果找类似匹配的函数进行调用
//如果有类型完全匹配的函数，则直接进行调用
//如果没有类型完全匹配的函数，则会进行隐式类型转换，如果隐式类型转换后有对应的函数则进行调用
//如果没有对应的函数，或者说转换之后有二义性，则报错
int main()
 {
	//单纯从调用位置来看---只看到了一个Add
	Add(10, 20);//int, int 
	Add(1.2, 3.4);//double, double --->Add(double, double)
	Add('1', '2');//char, char --->Add(char, char)--->char和int之间可以进行隐式类型转换--->Add(int, int)
	//Add("hello", "world");//char*, char*--->Add(char*, char*)--->char*既不能隐式转换为int,也不能隐式转换为double

	//编译阶段，对形参类型进行推演：int,double
	//Add(int, double)--->该函数没有找到
	//发现：int和double之间可以进行隐式类型转换 int--->double double--->int
	//Add(int, int) || Add(double, double) 转换之后发现有两个函数都可以
	//编译器不知道到底应该调用哪一个方法了
	//编译报错
	//Add(1, 2.2);
	Add(1, (int)2.2);

	return 0;
}
#endif

//C语言不支持函数重载
//C++到底是怎么支持函数重载的?而C语言为什么就不能支持?
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
int main()
{

	return 0;
}