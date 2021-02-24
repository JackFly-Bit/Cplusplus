#include <iostream>
using namespace std;

#if 0

//在C++中，struct定义出来的类型就可以看成是一个类了
//C语言中的结构体，在C++中 摇身一变 变成--->定义了一个类
struct Student
{
	//结构体中的变量
	char _name[20];
	char _gender[3];
	int _age;

	//结构体中的函数
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

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
	//在C语言中的方式
	struct Student s1;
	s1._age = 10;

	//在C++中
	Student s2;
	s2.InitStudent("Peter", "男", 18);
	s2.SetAge(10);
	return 0;
}
#endif
#if 0
//只不过，在C++中，如果要定义类，我们更喜欢使用class的关键字
//定义一个类
//方式一：将成员函数在类内来进行定义
class Student
{
private:
	//成员变量
	char _name[20];
	char _gender[3];
protected:
	int _age;

public:
	//成员函数
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	//注意：成员函数如果在类的内部来进行定义，成员函数可能会被编译器当成内联函数来对待
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
	//Student是类名，可以将其看成是学生的一个群体
	// s是用Student类定义出来的对象

	Student s;

	//编译报错：因为Student不是一个具体的学生们，我们不能将名字、性别、年龄放到Student中
	//Student.InitStudent("Peter", "男", 18);

	//s是一个具体存在的学生，我们才可以将名字，性别，年龄放到具体的学生对象中
	//报错：无法访问private的成员
	s.InitStudent("Peter", "男", 18);
	s.PrintStudent();

	//s._age = 10;
	return 0;
}
#endif
#if 1
//只不过，在C++中，如果要定义类，我们更喜欢使用class的关键字
//定义一个类
//方式一：将成员函数在类内来进行定义
class Student
{
private:
	//成员变量
	char _name[20];
	char _gender[3];
	int _age;

public:
	//成员函数
	void InitStudent(char name[], char gender[], int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	//注意：成员函数如果在类的内部来进行定义，成员函数可能会被编译器当成内联函数来对待
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
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 18);
	s2.InitStudent("David", "男", 20);
	s3.InitStudent("Lucy", "女", 19);
	
	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif
