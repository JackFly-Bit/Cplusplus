#include <iostream>
using namespace std;

#if 0
//������Ա������������---��������̵�
//vs��һ�����ɿ�����������������ɻ�����������ʱ��Ԥ����-->����-->���-->����-->���ɿ�ִ�г���
//C/C++����������ЩԴ�ļ��ǵ������аٱ����
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
//���C++��C���Ի��������̣����Բ����������봦��
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
//��ֵ������ͨ���βθı��ⲿ��ʵ�Σ���Ϊ�β�ʱʵ�ε�һ�ݿ���
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
//����ַ�������Ҫͨ���βθı��ⲿ��ʵ��
//���⣺ָ����ܲ���ȫ---ÿ��ʹ��ʱ����Ҫ��ָ���п�
//		����Ŀɶ��ԱȽϲ�
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
//�����룺�ܲ��ܹ���������ֵ�ķ�ʽ�����Σ��ں���ʵ����Ҳ����ֵ�ķ�ʽ������������Ҳ��ﵽָ�����Ƶ�Ч��
/*
void Swap(int left, int right)
{
	int temp = left;
	left = right;
	right = temp;
}
���left��right�ܹ���ʵ�εı����ͺ���
����������һ������
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
	//Ҫ��aȡ��������Ϊra
	//&����������֮�󣬱�ʾ���õı��
	int& ra = a;
	ra = 100;
	return 0;
}
#endif

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	//ra����a�ı���
//	ra = 100;
//	//�������ͱ�������ʵ����ͬ�����͵�
//	//ʵ����int���͵ģ�����Ҳ������int���͵�
//	double& rra = a;
//	return 0;
//}
#if 0
int main()
{
	int a = 10;
	//int& ra; ����ʧ�ܣ��������ͱ����ڶ���ʱ����Ҫ��ʼ��---����������Ͳ�֪��ra����ʱ˭�ı���
	int& ra = a;

	//һ�����������ж������--->һ��ʵ������ж������
	int& ra1 = a;
	int& ra2 = a;
	int& ra3 = a;
	int& ra4 = ra;//ra����a

	ra = 100;
	ra1 = 200;
	ra2 = 300;
	ra3 = 400;

	//����һ������һ��ʵ����ٲ�������������ʵ����
	int b = 10;

	int& rb = b;

	//rb�Ѿ�ʱb�ı����ˣ���rb���a�ı������ܲ���������
	rb = a;//��������rb��Ϊa�ı�����������a��rb��ֵ

	// &rb = a; ���뱨���� &rb--->��rbȡ��ַint* = int
	return 0;
}
#endif
#if 0
int main()
{
	//����һ������һ��ʵ�壬�ٲ�����������ʵ��
	//�������������������ڣ�ֻ�ܺ�һ��ʵ����

	//���⣺���ú������õ�ʵ�������������һ������

	int a = 10;
	int& ra = a;

	if (true)
	{
		int& rra = a;
		rra = 100;
	}

	// rra = 1000��
	return 0;
}
#endif
#if 0
// ������
int main()
{
	// a��һ�������� a���ܹ����޸ĵ�
	const int a = 10;
	//a = 100;

	//���ra��������a,��ô���ǾͿ���ͨ��ra���޸�a
	//int& ra = a;//����ʧ��
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

	//˼���£�
	double d = 12.34;
	const int& rd = d;//rd�Ѿ���d�ı����� -- rd��int���͵ģ�Ӧ��rd��d�е����Ͳ����õ���
	d = 34.56;
	cout << rd << endl;
	return 0;
}
#endif

//��һ�룺r��main�����У�û�н����κ��޸ģ�Ϊʲô�ڶ��Σ�������Add���ý�����r��ֵ����ı䣿
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