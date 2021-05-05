#include <iostream>
using namespace std;

#include <vector>

#if 0
int main()
{
	vector<int> v;
	v.reserve(10);//底层空间大小是10，但是此时还没有元素
	v[0] = 1;
	return 0;
}
#endif
#if 0
#include "Vector.h"

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	//TestVector5();
	//TestVector6();
	TestVector7();
	return 0;
}
#endif
#if 0
#include<list>

#include <vector>

void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);

	vector<int> v{ 1, 2, 3, 4, 5 };
	list<int> L3(v.begin(), v.end());

	list<int> L4(L3);
	list<int> L5{ 1, 2, 3, 4, 5 };

	for (auto e : L2)
		cout << e << " ";
	cout << endl;

	//list<int>::const_iterator it = L3.begin();
	auto it = L3.begin();
	while (it != L3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

}

void TestList2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);

	cout << L.size() << endl;
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.push_front(0);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.pop_back();
	L.pop_front();
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.insert(find(L.begin(), L.end(), 3), 6);
	L.insert(find(L.begin(), L.end(), 7), 7);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.erase(find(L.begin(), L.end(), 6));
	L.erase(L.begin(), L.end()); // clear()
}

bool isOdd(int data)
{
	return data & 0x01;
}

void TestList3()
{
	list<int> L{ 5, 1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 5, 5 };
	L.remove(5);

	//删除所有的奇数
	L.remove_if(isOdd);
	L.sort();
	L.unique();
	L.reverse();
}

//list的迭代器失效
void TestList4()
{
	list<int> L{ 1, 2, 3, 4, 5 };
	auto it = L.begin();
	while (it != L.end())
	{
		it = L.erase(it);
		//++it;
	}
}

struct A
{
	int a;
	int b;
	int c;
};

int main()
{
	A aa;
	A* pa = &aa;
	aa.a = 10;
	pa->b = 20;

	//TestList1();
	//TestList2();
	//TestList3();
	TestList4();
	return 0;
}
#endif
#if 1
#include "List.h"

int main()
{
	//TestList1();
	TestList2();
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
#if 0
int main()
{
	return 0;
}
#endif