#include <iostream>
using namespace std;


#include <string>

void TestString1()
{
	string s("hello world");

	// size和length都是求字符串有效长度
	cout << s.length() << endl;
	cout << s.size() << endl;

	// 底层空间总的大小
	cout << s.capacity() << endl;

	if (!s.empty()) // 检测该字符串是否为空(的字符串)
	{
		cout << "not empty!!!" << endl;
	}
	else
	{
		cout << "empty!!!" << endl;
	}

	// 将s中有效字符清空
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	if (!s.empty()) // 检测该字符串是否为空(的字符串)
	{
		cout << "not empty!!!" << endl;
	}
	else
	{
		cout << "empty!!!" << endl;
	}
}


void TestString2()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '!');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(14, '$');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '*');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(34);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// resize只是将有效元素个数缩减到n个
	// 注意：底层容量没有发生变化
	s.resize(30);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(24);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(16);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}


void TestString3()
{
	cout << sizeof(string) << endl;

	string s("hello");
	//new string("hello");

	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(18);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(30);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(40);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(35);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(16);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//s.reserve(15);
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;

	s.reserve(10);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	string ss("hello,world bite");  // strtok
	char* p = (char*)ss.c_str();
}

void TestString4()
{
	string s1;
	string s2("hello");
	s1 += s2;
	s1 += ' ';
	s1 += "world";
	s1.push_back('!');
}

void TestString5()
{
	string s("hello");

	size_t pos = s.find('o');
	if (pos != string::npos)
	{
		s.insert(pos, "world");
	}

	s.insert(s.begin(), 3, '#');

	s.erase(s.begin());
	s.erase(s.begin(), s.begin() + 3);
	s.erase();
}

void TestString6()
{
	string s1("hello");
	string s2("world");
	swap(s1, s2);
	s1.swap(s2);
}

void TestString7()
{
	string s("1234");
	int value = atoi(s.c_str());
	cout << value << endl;
}

// http://www.baidu.com

void TestString8()
{
	string s("http://www.baidu.com");
	size_t pos = s.find("www");
	if (pos != string::npos)
	{
		string ret = s.substr(pos);
		cout << ret << endl;
	}
}

// 有多行单词
// 单词和单词之间使用空格隔开，需求：知道最后一行单词的长度
// hello world bite 

void TestString9()
{
#if 0
	char str[100];
	gets(str);
#endif

	string s;
	// 循环接收一行字符串
	while (getline(cin, s))
	{
		//cin >> s;
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}
}

// 将用户所给的单词输出
void TestString10()
{
	string s;
	// 一次接收一个
	while (cin >> s)
	{
		cout << s << endl;
	}
}

void TestString11()
{
	string s1("hello");
	string s2("world");
	if (s1 > s2)
	{
		cout << s1 << endl;
	}
	else
	{
		cout << s2 << endl;
	}
}

void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

// 问题：为什么不选择以固定不长来进行扩容？----网上有
//      vs:1.5   linux: 2倍
//      为什么vs选择1.5倍扩容，linux选择2倍方式扩容？
int main()
{
	// TestString1();
	// TestString2();
	// TestString3();
	// TestString4();
	// TestString5();
	// TestString6();
	// TestString7();
	// TestString8();
	// TestString9();
	// TestString10();
	// TestString11();
	TestPushBack();
	return 0;
}