#include <iostream>
using namespace std;


#include <string>

void TestString1()
{
	string s("hello world");

	// size��length�������ַ�����Ч����
	cout << s.length() << endl;
	cout << s.size() << endl;

	// �ײ�ռ��ܵĴ�С
	cout << s.capacity() << endl;

	if (!s.empty()) // �����ַ����Ƿ�Ϊ��(���ַ���)
	{
		cout << "not empty!!!" << endl;
	}
	else
	{
		cout << "empty!!!" << endl;
	}

	// ��s����Ч�ַ����
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	if (!s.empty()) // �����ַ����Ƿ�Ϊ��(���ַ���)
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

	// resizeֻ�ǽ���ЧԪ�ظ���������n��
	// ע�⣺�ײ�����û�з����仯
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

// �ж��е���
// ���ʺ͵���֮��ʹ�ÿո����������֪�����һ�е��ʵĳ���
// hello world bite 

void TestString9()
{
#if 0
	char str[100];
	gets(str);
#endif

	string s;
	// ѭ������һ���ַ���
	while (getline(cin, s))
	{
		//cin >> s;
		cout << s.substr(s.rfind(' ') + 1).size() << endl;
	}
}

// ���û������ĵ������
void TestString10()
{
	string s;
	// һ�ν���һ��
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

// ���⣺Ϊʲô��ѡ���Թ̶��������������ݣ�----������
//      vs:1.5   linux: 2��
//      Ϊʲôvsѡ��1.5�����ݣ�linuxѡ��2����ʽ���ݣ�
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