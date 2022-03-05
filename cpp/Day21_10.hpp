/*
类模板中成员函数和普通类中成员函数创建时机是有区别的：
	1.普通类中的成员函数一开始就可以创建
	2.类模板中的成员函数在调用时才创建

导致的问题；如果还像之前在头文件.h中写类的声明(包括类的成员和函数)
			在源文件.cpp中写类的定义(类的成员和函数的实现)
			调用时只写#include<xxxx.h>
			这样由于类模板中的成员函数在调用时才创建，所以不会创建类模板函数，报错
解决办法：
		方法1：直接包含.cpp源文件，调时写#include<xxxx.cpp>，先调cpp文件，cpp文件再调用.h文件
		方法2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
		常用方法2
*/


#pragma once
#include<iostream>
#include<string>
using namespace std;

//方法2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

//声明类
template<class T1,class T2>
class Person_21_10 {
public:
	T1 name;
	T2 age;
	Person_21_10(T1 name, T2 age);
	void showPerson();
};


//构造函数 类外实现
template<class T1, class T2>
Person_21_10<T1,T2>::Person_21_10(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

//成员函数 类外实现
template<class T1, class T2>
void Person_21_10<T1, T2>::showPerson() {
	cout << "Name: " << this->name << "\tAge: " << this->age << endl;
}


