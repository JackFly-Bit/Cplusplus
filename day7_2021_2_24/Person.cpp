#include "Person.h"

#include <iostream>
using namespace std;

//注意：成员函数如果放在类外来进行定义
//成员函数名之前必须要加：类名:: 表明该含糊是哪个类的成员函数
//如果没有加，就相当于在全局作用域中定义了一个函数
void Person::InitPerson(char name[], char gender[], int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Person::Eat()
{
	cout << "biajibiaji" << endl;
}
void Person::Sleep()
{
	cout << "呼呼呼" << endl;
}
void Person::PrintPersonInfo()
{
	cout << _name << "-" << _gender << "-" << _age << endl;
}