#include <iostream>
using namespace std;

#include <queue>

#include <functional>

#if 1
void Testpriority_queue1()
{
	priority_queue<int>p;
	p.push(5);
	p.push(4);
	p.push(6);
	p.push(1);
	p.push(2);
	p.push(3);

	cout << p.top() << endl;
}

void Testpriority_queue2()
{
	priority_queue<int, vector<int>, greater<int>>p;
	p.push(5);
	p.push(4);
	p.push(6);
	p.push(1);
	p.push(2);
	p.push(3);

	cout << p.top() << endl;
}

//1.����ָ��
bool Greater(int left, int right)
{
	return left > right;
}

//PF��һ������ָ�����
//PF:����ָ���κξ����������β����Լ�����bool���ͷ���ֵ�ĺ���
//bool (*PF)(int left, int right);

//bool(*)(int, int)--->�ı���--->PF
typedef bool(*PF)(int left, int right);

void Testpriority_queue3()
{
	priority_queue<int, vector<int>, PF> p(Greater);
	p.push(5);
	p.push(4);
	p.push(6);
	p.push(1);
	p.push(2);
	p.push(3);

	cout << p.top() << endl;
}

//2.�÷º���/��������
//������������һ��ʹ�õĶ���

bool fLess(int left, int right)
{
	return left < right;
}

class Less
{
public:
	bool operator()(int left, int right)
	{
		return left < right;
	}
};

void Testpriority_queue4()
{
	fLess(10, 5);

	Less FLess;
	FLess(10, 5); FLess.operator()(10, 5);

	priority_queue<int, vector<int>, Less> p;
	p.push(5);
	p.push(4);
	p.push(6);
	p.push(1);
	p.push(2);
	p.push(3);

	cout << p.top() << endl;
}

//3.lambda

int main()
{
	//Testpriority_queue1();
	//Testpriority_queue2();
	//Testpriority_queue3();
	Testpriority_queue4();
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