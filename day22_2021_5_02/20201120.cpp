#include <iostream>
using namespace std;

#include <vector>

#if 0
class Date
{
public:
	//Date()
	//{}

	Date(int year = 1900, int month = 1, int day = 1)
	{ }

private:
	int _year;
	int _month;
	int _day;
};
void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(10);
	vector<Date> v4(10);

	int array[] = { 1, 2, 3, 4, 5 };
	vector<int> v5(array, array+sizeof(array)/sizeof(array[0]));

	vector<int> v6(v5);

	//C++11新增加
	vector<int> v7{ 1, 2, 3, 4, 5 };

	//遍历方式
	for (size_t i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	//C++11
	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	vector<int>::iterator it = v7.begin();
	while (it != v7.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	TestVector1();
	return 0;
}
#endif
#if 1

void TestVector1()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(20, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(30);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void TestVector2()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	cout << v[0] << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;

	v[0] = 100;
	v.front() = 10;
	v.back() = 20;

	v[5] = 10;
	v.at(5) = 20;
}

//push_back
//1.vector的扩容机制:
//			vs:1.5倍
//		 linux:2倍
//2.尽量避免一边插入一边扩容
//	注意:一般如果大概知道要向vector中存储多少个元素---reserve提前将空间设置好
void TestVector3()
{
	vector<int> v;
	v.reserve(100);
	size_t capacity = v.capacity();
	for (size_t i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (capacity != v.capacity())
		{
			cout << capacity << endl;
			capacity = v.capacity();
		}
	}
}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int, int, int):" << this << endl;
	}

	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestPushBack()
{
	Date d(2020, 11, 20);
	vector<Date> v;

	//注意：push_back不是直接将d尾插到vector中了
	//实际插入的是d的一份拷贝
	v.push_back(d);
	cout << &v[0] << endl;
}

void TestVector4()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	v.insert(v.begin(), 0);

	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
		v.insert(pos, 4, 6);

	v.insert(v.begin() + 1, v.begin(), v.end());

	v.erase(v.begin());
	v.erase(v.begin(), v.begin() + 5);
	//v.erase(v.begin(), v.end());
	v.clear();
}

//////////////////////////
//验证迭代器失效:扩容导致的失效
void TestVector5()
{
	vector<int> v{ 1, 2, 3 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	auto it = v.begin();
	v.assign(10, 5);

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestVector6()
{
	vector<int> v{ 1, 2, 3, 4, 5 };

	auto it = v.begin();
	v.erase(it);
	cout << *it << endl;
}

void TestVector7()
{
	vector<int> v1{ 1, 2, 3 };
	vector<int> v2{ 1, 2, 3, 4, 5 };

	auto it1 = v1.begin();
	auto it2 = v2.begin();

	v1.swap(v2);

	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

//需求:让使用迭代器将vector中的所有元素删除掉
void TestVector8()
{
	vector<int>v{ 1, 2, 3, 4, 5 };
	auto it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it);
		//++it;
	}

	//v.erase(v.begin(), v.end())--->v.clear()
}

//构造矩阵
void TestVector9()
{
	//5*6
	vector<vector<int>> vv;
	vv.resize(5);
	for (size_t i = 0; i < vv.size(); ++i)
		vv[i].resize(6);

	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			vv[i][j] = j + 1;
		}
	}
}

void TestVector10()
{
	//5*6
	vector<vector<int>> vv(5, vector<int>(6));

	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			vv[i][j] = j + 1;
		}
	}
}

void TestVector11()
{
	//5*6
	vector<vector<int>> vv(5, vector<int>{1, 2, 3, 4, 5, 6});
}

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestPushBack();
	//TestVector4();
	//TestVector5();
	//TestVector6();
	//TestVector7();
	//TestVector8();
	//TestVector9();
	//TestVector10();
	TestVector11()
	return 0;
}
#endif
#if 0
int main()
{
	return 0;
}
#endif
