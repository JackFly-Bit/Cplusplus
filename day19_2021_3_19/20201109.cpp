#include <iostream>
using namespace std;


#if 0
// 反例---千万不能写
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);

#if 0
		if (nullptr == str)
		{
			_str = new char[1];
			//_str = '\0';  // _str = NULL;
			//str = '0';
			//*_str = '0';
			//*_str = 0;   //
			*_str = '\0';//
		}
		else
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
#endif
	}

	String(const String& s)
		: _str(s._str)
	{}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			_str = s._str;
		}

		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};
#endif



#if 0
// 传统版--
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	// s2 = s5;
	// "hello"  "hello world"
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);

			delete[] _str;
			_str = temp;
		}

		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};
#endif

#if 0
// 现代版
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(nullptr)
	{
		String strTemp(s._str);
		std::swap(_str, strTemp._str);
	}

	// s2 = s5;
	// "hello"  "hello world"
	/*
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String strTemp(s._str);
			std::swap(_str, strTemp._str);
		}

		return *this;
	}
	*/

	String& operator=(String s)
	{
		std::swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};

void TestString1()
{
	String s1("hello");
	String s2(s1);
}

String TestString2()
{
	String s("hello");
	return s;
}

void TestString3()
{
	String s1("hello");
	String s2("world");
	s1 = s2;
}


int main()
{
	//TestString1();
	//TestString2();
	TestString3();
	return 0;
}
#endif


int main()
{
	return 0;
}