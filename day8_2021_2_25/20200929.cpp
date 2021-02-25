#include <iostream>
using namespace std;

#if 0
//��μ���һ����/����Ĵ�С��
//�������֪�������ж�������Щ����
class Student
{
public:
	//��Ա����
	char _name[20];
	char _gender[3];
	int _age;

public:
	//��Ա����
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	//ע�⣺��Ա�������������ڲ������ж��壬��Ա�������ܻᱻ���������������������Դ�
	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		_age = age;
	}
};
int main()
{
	Student s1,s2,s3;
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	
	cout << sizeof(s1) << endl;
	return 0;
}
#endif
#if 0
class A
{
public:
	void SetA(int a)
	{
		_a = a;
	}
private:
	int _a;
};
class B
{
public:
	void TestB()
	{}
};

class C
{};

struct AA
{
	int a;
	char b;
	double c;
	char d;
};
#pragma pack(8)
#pragma pack()
//�յĽṹ���Ƕ����أ�
//��������C++�У���struct��������Ľṹ�������
//����
struct D
{};
int main()
{
	//���ۣ���һ����Ĵ�С--->ֻ��Ҫ�����С���Ա��������������ע���ڴ����
	cout << sizeof(A) << endl;//4	//4
	cout << sizeof(B) << endl;//0	//1
	cout << sizeof(C) << endl;//0	//1

	cout << sizeof(D) << endl;//0	//1

	//���裺����Ĵ�СΪ0
	//C���ǿ��࣬Ȼ����C�ඨ������������
	C c1, c2, c3;

	//int a, b, c;
	//���󣺸���һ���ṹ��AA��Ȼ���ٸ�AA�е�һ����Ա
	//��Ҫ֪����AA�ṹ���е�c��Ա����ڽṹ����ʼλ�õ�ƫ�����Ƕ��٣�
	cout << offsetof(AA, c) << endl;

	return 0;
}
#endif
#if 0
class Student
{
public:
	//��Ա����
	char _name[20];
	char _gender[3];
	int _age;

public:
	//��Ա����
	//�������ú���������������ʵ������4������
	//����һ�������ǣ����ص�thisָ��
	//��д�����ڼ䣬�û�������ʾ����thisָ�룬�������ڱ������ʱ�����Զ�����thisָ��Ĳ���
	void InitStudent(char name[], char gender[], int age);
	//{
	//	//���ܸ�thisָ�������и�ֵ----Student* const this
	//	//							  ������* const
	//	//this = nullptr;

	//	cout << this << endl;

	//	//����thisָ�룬��Ա������֪���������ڲ����ĸ�����
	//	//ע�⣺�Գ�Ա�����Ĳ�������ͨ��thisָ������е�
	//	strcpy(this->_name, name);
	//	strcpy(this->_gender, gender);
	//	this->_age = age;
	//}

	//ע�⣺��Ա�������������ڲ������ж��壬��Ա�������ܻᱻ���������������������Դ�
	void PrintStudent()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	void SetAge(int age)
	{
		cout << this << endl;
		_age = age;
	}
	void TestFunc(...);
	//{}
};
int main()
{
	//cout << this << endl;
	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << sizeof(s1) << endl;

	s1.TestFunc(1);
	s2.TestFunc(1, 2);
	s3.TestFunc(1, 2, 3);
	return 0;
}
#endif
#if 0
//�ع鵽C������
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

//����Ҫʵ��һЩ�����ṹ�����ͱ����ķ���
void InitStudent(Student* this, char* name, char* gender, int age)
{


	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
}

//��ӡ�ĸ�ѧ������Ϣ�����뽫��ѧ�����͵Ľṹ�����͵ı���������
void PrintStudent(Student* this)
{
	printf("%s-%s-%d\n", this->_name, this->_gender, this->_age);
}
int main()
{
	struct Student s1, s2, s3;
	InitStudent(&s1, "Peter", "��", 18);
	InitStudent(&s2, "David", "��", 20);
	InitStudent(&s3, "Lily", "Ů", 19);

	PrintStudent(&s1);
	PrintStudent(&s2);
	PrintStudent(&s3);
	return 0;
}
#endif
#if 1
//��Ա�����ں󣬳�Ա������ʹ����ǰ����������ô�������أ�
//��Ϊ�����������������������ࣺ

/*
1.��ʶ������
2.����ʶ�����еĳ�Ա����
3.���ʶ�����еĳ�Ա���������Գ�Ա���������޸�---��Ҫ������thisָ��
*/
class Student
{
public:
	/*
	void InitStudent(Student* const this, char name[], char gender[], int age)
	{
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	*/
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	/*
	void PrintStudent(Student* const this)
	{
		printf("%s\n", this->_name);
		printf("%s\n", this->_gender);
		printf("%d\n", this->_age);
	}
	*/
	void PrintStudent()
	{
		printf("%s\n", _name);
		printf("%s\n", _gender);
		printf("%d\n", _age);
	}

	//��Ա�����������������λ�������ж��壬���ҿ����ڡ������Ա��������ʹ��
	//���൱�ڣ���Ա�����������ڳ�Ա������ȫ�ֱ���
private:
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 18);
	s2.InitStudent("David", "��", 19);
	s3.InitStudent("Lily", "Ů", 18);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << sizeof(s1) << endl;

	g_a = 10;
	return 0;
}

void TestFunc()
{
	g_a = 10;
}

//ȫ�ֱ�����ʹ��֮ǰ�����ȶ���
int g_a = 10;
#endif
#if 0
int main()
{
	return 0;
}
#endif