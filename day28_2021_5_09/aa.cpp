#include "aa.h"

/*
int Add(int left, int right);

template<class T>
T Sub(const T& left, const T& right);
*/

int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Sub(const T& left, const T& right)
{
	return left - right;
}

void Test()
{
	Sub(1, 2);		//int,int--->Sub<int>
	Sub(10.0, 20.0);//double,double--->Sub<double>
}