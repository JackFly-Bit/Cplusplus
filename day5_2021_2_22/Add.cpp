#include "Add.h"

//���������������������֮�󣬲�û�����ɶ�Ӧ�ĺ�������
inline int Add(int left, int right)
{
	return left + right;
}

int TestInline()
{
	int a = 10;
	int b = 20;
	Add(a, b);
}