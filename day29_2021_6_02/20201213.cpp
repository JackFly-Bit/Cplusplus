#include <iostream>
using namespace std;

#if 0
int main()
{
	char str[10] = { 0 };
	gets(str);

	int a = 0;
	scanf("%d", a);
	printf("%d %s %f", 123);

	cout << "hello" << 123 << 12.34 << endl;
	return 0;
}
#endif
#if 0
#include<fstream>

// 使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // 端口
};
struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		// 这里注意使用二进制方式打开写
		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		// 这里注意使用二进制方式打开读
		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteText(const ServerInfo& info)
	{
		// 这里会发现IO流写整形比C语言那套就简单多了，
		// C 语言得先把整形itoa再写
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
		// 这里会发现IO流读整形比C语言那套就简单多了，
		// C 语言得先读字符串，再atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // 配置文件
};

int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// 二进制读写
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// 文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}
#endif
#if 0
#include <sstream>

int main()
{
	int a = 123456;

	stringstream ss;
	ss << a;

	string s;
	ss >> s;

	//将stringstream内部管理的string对象清空
	ss.str("");

	//清空stringstream内部的状态
	//下一次转换之前必须要将其内部的状态清空，否则不会进行转化
	//只是清空状态，并不会将stringstream内部管理的string对象清空
	ss.clear();

	double d = 12.34;
	ss << d;
	ss >> s;

	string value = ss.str();
	cout << value << endl;
	return 0;
}
#endif
#if 0
#include <sstream>
int main()
{
	stringstream ss;
	ss << "hello";
	ss << "	   ";
	ss << "world";
	ss << "!!!";

	string s = ss.str();
	cout << s << endl;
	return 0;
}
#endif
#if 0
//基类、父类
class Person
{
public:
	void Eat()
	{
		cout << "Eat()" << endl;
	}

	void Sleep()
	{
		cout << "Sleep()" << endl;
	}

private:
	string _name;
	string _gender;
	int _age;
};

//派生类、子类
//想要采用继承的方式复用Person中的属性以及代码
//Student已经将Person类中的成员继承到其内部了
class Student : public Person
{
public:
	void Study()
	{
		cout << "Study()" << endl;
	}

	void Exam()
	{
		cout << "Exam()" << endl;
	}

private:
	int _stuId;
};

int main()
{
	cout << sizeof(Student) << endl;

	Student s;
	s.Eat();
	s.Sleep();
	return 0;
}
#endif
#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void Print()const
	{
		cout << _pri << " " << _pro << " " << _pub << " " << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

//子类已经将基类中的属性和方法全部继承到子类中了
//public继承方式：
//1.基类中被public修饰的成员再子类中的权限也是public
//2.基类中被protected修饰的成员在子类中可以被访问，而且权限也是protected
//3.基类中被private修饰的成员函数在子类中不可见(不能直接被访问)
//	注意：基类中被private修饰的成员已经继承到子类中了
class Derived : public Base
{
public:
	void SetDerived(int d)
	{
		//_pri = d;
		_pro = d;
		_d = d;
	}
public:
	int _d;
};

class D :public Derived
{
public:
	void Test()
	{
		_pro = 0;
	}
};

int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	d._pub = 1;
	//d._pro = 2;
	//d._pri = 3;
	return 0;
}
#endif
#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void Print()const
	{
		cout << _pri << " " << _pro << " " << _pub << " " << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

//子类已经将基类中的属性和方法全部继承到子类中了
//protected继承方式：
//1.基类中被public修饰的成员再子类中的权限变成protected
//2.基类中被protected修饰的成员在子类中可以被访问，而且权限也是protected
//3.基类中被private修饰的成员函数在子类中不可见(不能直接被访问)
//	注意：基类中被private修饰的成员已经继承到子类中了
class Derived : protected Base
{
public:
	void SetDerived(int d)
	{
		//_pri = d;
		_pro = d;
		_d = d;
	}
public:
	int _d;
};

class D :public Derived
{
public:
	void Test()
	{
		_pro = 0;
		_pub = 1;
	}
};

int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pub = 1;
	//d._pro = 2;
	//d._pri = 3;
	return 0;
}
#endif
#if 1
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}

	void Print()const
	{
		cout << _pri << " " << _pro << " " << _pub << " " << endl;
	}

private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};

//子类已经将基类中的属性和方法全部继承到子类中了
//private继承方式：
//1.基类中被public修饰的成员再子类中的权限变成private
//2.基类中被protected修饰的成员在子类中可以被访问，而且权限也是private
//3.基类中被private修饰的成员函数在子类中不可见(不能直接被访问)
//	注意：基类中被private修饰的成员已经继承到子类中了
class Derived : private Base
{
public:
	void SetDerived(int d)
	{
		//_pri = d;
		_pro = d;
		_d = d;
	}
public:
	int _d;
};

class D :public Derived
{
public:
	void Test()
	{
		//_pro = 0;
		//_pub = 1;
	}
};

int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pub = 1;
	//d._pro = 2;
	//d._pri = 3;
	return 0;
}
#endif