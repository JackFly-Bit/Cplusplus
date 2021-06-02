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

// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // �˿�
};
struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ��д
		ofstream ofs(_configfile, ifstream::in | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
		ifstream ifs(_configfile, ifstream::out | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteText(const ServerInfo& info)
	{
		// ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
		// C ���Ե��Ȱ�����itoa��д
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
		// ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
		// C ���Ե��ȶ��ַ�������atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // �����ļ�
};

int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// �����ƶ�д
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// �ı���д
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

	//��stringstream�ڲ������string�������
	ss.str("");

	//���stringstream�ڲ���״̬
	//��һ��ת��֮ǰ����Ҫ�����ڲ���״̬��գ����򲻻����ת��
	//ֻ�����״̬�������Ὣstringstream�ڲ������string�������
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
//���ࡢ����
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

//�����ࡢ����
//��Ҫ���ü̳еķ�ʽ����Person�е������Լ�����
//Student�Ѿ���Person���еĳ�Ա�̳е����ڲ���
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

//�����Ѿ��������е����Ժͷ���ȫ���̳е���������
//public�̳з�ʽ��
//1.�����б�public���εĳ�Ա�������е�Ȩ��Ҳ��public
//2.�����б�protected���εĳ�Ա�������п��Ա����ʣ�����Ȩ��Ҳ��protected
//3.�����б�private���εĳ�Ա�����������в��ɼ�(����ֱ�ӱ�����)
//	ע�⣺�����б�private���εĳ�Ա�Ѿ��̳е���������
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

//�����Ѿ��������е����Ժͷ���ȫ���̳е���������
//protected�̳з�ʽ��
//1.�����б�public���εĳ�Ա�������е�Ȩ�ޱ��protected
//2.�����б�protected���εĳ�Ա�������п��Ա����ʣ�����Ȩ��Ҳ��protected
//3.�����б�private���εĳ�Ա�����������в��ɼ�(����ֱ�ӱ�����)
//	ע�⣺�����б�private���εĳ�Ա�Ѿ��̳е���������
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

//�����Ѿ��������е����Ժͷ���ȫ���̳е���������
//private�̳з�ʽ��
//1.�����б�public���εĳ�Ա�������е�Ȩ�ޱ��private
//2.�����б�protected���εĳ�Ա�������п��Ա����ʣ�����Ȩ��Ҳ��private
//3.�����б�private���εĳ�Ա�����������в��ɼ�(����ֱ�ӱ�����)
//	ע�⣺�����б�private���εĳ�Ա�Ѿ��̳е���������
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