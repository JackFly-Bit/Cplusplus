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

//û�з���ֵ��Ҳû�в���
//��C�����У����´������ͨ������
//��C++�����У����´��벻��ͨ������
//C++��������C���Ա������﷨�������ϸ�
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

//��C�����У����º�������ͨ�����룬��Ϊû����ʽд����ֵ����ʱ��C���Ա�����Ĭ�Ϻ�������int
//��C++�У����º�������ͨ������
//C++��������C���Ա������﷨�������ϸ�
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

//ȱʡ�������ڶ��庯��ʱ�����Ը������Ĳ�������һЩĬ��ֵ
//�ڵ��øú���ʱ�����û��ָ��ʵ������ø�Ĭ��ֵ������ʹ��ָ����ʵ��
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
	//���������У�ÿ�ε��ô��ݵĶ���ͬһ��ʵ��
	//���봫�ݣ������øú���ִ�������󣬻������õ�10��20
	TestFunc();
	TestFunc(30, 40);
	TestFunc(300, 400);

	return 0;
}
#endif

#if 0
//���ࣺ
//1.ȫȱʡ������ÿ������������Ĭ��ֵ
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
//2.��ȱʡ���������ֲ�������Ĭ��ֵ
// a	b	c
// 0	1	1	�������ͨ������
// 1	0	1	�������ʧ��
// 1	1	0	�������ʧ��
// 0	0	1	�������ͨ������
//���ۣ�ֻ�ܴ����������θ���
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
//ȱʡ��������������λ�ø�����Ҳ�����ڶ���λ�ø���
//���ǲ�������λ��ͬʱ����
//���ʣ���������λ�ø��ã����Ƕ����λ�ø��ã�

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
//�������أ�
//�������ͬ�������У��������ֱ���Ҫ��ͬ�������б����Ҫ��ͬ(���������ͣ����ʹ���)
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
//�����б�ͬ�����֣�
//1.����������ͬ
//2.�������Ͳ�ͬ
//3.�������͵Ĵ���ͬ
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
//�������صĵ���ԭ��:
//��������һ�����ڱ���׶ξ�����ȷ��Ӧ�õ����ĸ�����
//�������ڱ���׶Σ���Ժ���ʵ�����ͽ������ݣ��������ݵ�ʵ�ʽ��������ƥ��ĺ������е���
//�����������ȫƥ��ĺ�������ֱ�ӽ��е���
//���û��������ȫƥ��ĺ�������������ʽ����ת���������ʽ����ת�����ж�Ӧ�ĺ�������е���
//���û�ж�Ӧ�ĺ���������˵ת��֮���ж����ԣ��򱨴�
int main()
 {
	//�����ӵ���λ������---ֻ������һ��Add
	Add(10, 20);//int, int 
	Add(1.2, 3.4);//double, double --->Add(double, double)
	Add('1', '2');//char, char --->Add(char, char)--->char��int֮����Խ�����ʽ����ת��--->Add(int, int)
	//Add("hello", "world");//char*, char*--->Add(char*, char*)--->char*�Ȳ�����ʽת��Ϊint,Ҳ������ʽת��Ϊdouble

	//����׶Σ����β����ͽ������ݣ�int,double
	//Add(int, double)--->�ú���û���ҵ�
	//���֣�int��double֮����Խ�����ʽ����ת�� int--->double double--->int
	//Add(int, int) || Add(double, double) ת��֮��������������������
	//��������֪������Ӧ�õ�����һ��������
	//���뱨��
	//Add(1, 2.2);
	Add(1, (int)2.2);

	return 0;
}
#endif

//C���Բ�֧�ֺ�������
//C++��������ô֧�ֺ������ص�?��C����Ϊʲô�Ͳ���֧��?
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