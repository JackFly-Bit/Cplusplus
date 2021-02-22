#include "Add.h"

//对于内联函数，编译完成之后，并没有生成对应的函数代码
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