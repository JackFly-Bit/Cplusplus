#include <iostream>
using namespace std;

#if 0
//《程序员的自我修养》---讲编译过程的
//vs是一个集成开发环境，当点击生成或者重新生成时：预处理-->编译-->汇编-->连接-->生成可执行程序
//C/C++编译器对这些源文件是单独进行百编译的
int Add(int left, int right);//
//{
//	return left + right;
//}
//double Add(double left, double right);//
//{
//	return left + right;
//}
int main()
{
	Add(10, 30);
	//Add(1.2, 3.4);
	return 0;
}
#endif
#if 0
//int Add(int left, int right);//?Add@@YAHHH@Z
//{
//	return left + right;
//}
//double Add(double left, double right);//?Add@@YANNN@Z
//{
//	return left + right;
//}

double Add(int left, double right);//?Add@@YANHN@Z
int main()
{
	//Add(10, 30);
	//Add(1.2, 3.4);
	Add(1, 3.4);
	return 0;
}
#endif
#if 0
int add(int left, int right)//?add@@yahhh@z
{
	return left + right;
}
double Add(double left, double right)//?Add@@YANNN@Z
{
	return left + right;
}

int main()
{
	Add(10, 30);
	Add(1.2, 3.4);
	return 0;
}
#endif
#if 0
extern "C" int Add(int left, int right);//?add@@yahhh@z
//{
//	return left + right;
//}
#endif
#if 0
//如果C++和C语言混合起来编程，可以采用条件编译处理
extern "C"{
	int Add(int left, int right);
	int Add2(int left, int right);
	int Add3(int left, int right);
	int Add4(int left, int right);
}

void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc()
{
	cout << "void TestFunc(int)" << endl;
}

int main()
{
	TestFunc(10);
	//TestFunc();
	//Add(10, 30);
	//Add(1.2, 3.4);
	return 0;
}
#endif
#if 0
int _Add(int left, int right);
int main()
{
	_Add(10, 30);//__Add
	return 0;
}
#endif
#if 0
//传值：不能通过形参改变外部的实参，因为形参时实参的一份拷贝
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
//传地址：如果想要通过形参改变外部的实参
//问题：指针可能不安全---每次使用时必须要对指针判空
//		代码的可读性比较差
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
//大佬想：能不能够继续按照值的方式来传参，在函数实现中也按照值的方式来操作，但是也想达到指针类似的效果
/*
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
如果left和right能够是实参的别名就好了
别名：另外一个名字
*/
int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);
	Swap(&a, &b);
	return 0;
}
#endif
#if 0
int main()
{
	int a = 10;
	//要给a取别名，称为ra
	//&出现在类型之后，表示引用的标记
	int& ra = a;
	ra = 100;
	return 0;
}
#endif

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	//ra就是a的别名
//	ra = 100;
//	//引用类型必须与其实体是同种类型的
//	//实体是int类型的，别名也必须是int类型的
//	double& rra = a;
//	return 0;
//}
#if 0
int main()
{
	int a = 10;
	//int& ra; 编译失败：引用类型变量在定义时必须要初始化---否则编译器就不知道ra到底时谁的别名
	int& ra = a;

	//一个变量可以有多个引用--->一个实体可以有多个别名
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = a;
	int& ra4 = ra;//ra就是a

	ra = 100;
	ra1 = 200;
	ra2 = 300;
	ra3 = 400;

	//引用一旦引用一个实体后，再不能引用其他的实体了
	int b = 10;

	int& rb = b;

	//rb已经时b的别名了，让rb变成a的别名，能不能做到？
	rb = a;//并不是让rb成为a的别名，而是用a给rb赋值

	// &rb = a; 编译报错， &rb--->对rb取地址int* = int
	return 0;
}
#endif
#if 0
int main()
{
	//引用一旦引用一个实体，再不能引用其他实体
	//该引用在其生命周期内，只能和一个实体结合

	//问题：引用和其引用的实体的生命周期是一样的吗？

	int a = 10;
	int& ra = a;

	if (true)
	{
		int& rra = a;
		rra = 100;
	}

	// rra = 1000；
	return 0;
}
#endif
#if 0
// 常引用
int main()
{
	// a是一个常量， a不能够被修改的
	const int a = 10;
	//a = 100;

	//如果ra可以引用a,那么我们就可以通过ra来修改a
	//int& ra = a;//编译失败
	const int& ra = a;
	//ra = 200;

	//////////////////////////////
	const int& b = 10;
	return 0;
}
#endif
#if 0
int main()
{
	int a = 10;
	const int& ra = a;
	a = 100;

	//思考下？
	double d = 12.34;
	const int& rd = d;//rd已经是d的别名了 -- rd是int类型的，应该rd将d中的整型部分拿到了
	d = 34.56;
	cout << rd << endl;
	return 0;
}
#endif

//想一想：r在main函数中，没有进行任何修改，为什么第二次，第三次Add调用结束后，r的值都会改变？
int& Add(int left, int right)
{
	int ret = 0;
	ret = left + right;
	return ret;
}

int main()
{
	int& r = Add(1, 2);
	Add(3, 4);
	Add(5, 6);
	return 0;
}