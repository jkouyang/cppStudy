/*Day14  this指针
this指针指向被调用的成员函数所属的对象
	this指针是隐含每一个非静态成员函数内的一种指针
	this指针不需要定义，直接使用即可

this指针的用途：
	当形参和成员变量同名时，可用this指针来区分
	在类的非静态成员函数中返回对象本身，可使用return *this

C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针
*/

#include<iostream>
using namespace std;

class Person_14
{
public:

	Person_14(int age)
	{
		//1、当形参和成员变量同名时，可用this指针来区分，解决命名冲突
		this->age = age;
	}

	Person_14& PersonAddPerson(Person_14 p)
	{
		this->age += p.age;
		//2、返回对象本身
		return *this;
	}

	void show_14a() {
		cout << "空指针调用成员函数" << endl;
	}
	void show_14b() {
		if (this == NULL) {//不加就会报错
			return;
		}
		cout << "空指针调用成员函数，输出age:" << age << endl;//使用成员变量时系统自动使用this指针（age等效this->age）
	}
	int age;
};

void test_14a()
{
	Person_14 p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person_14 p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);//链式编程思想
	cout << "p2.age = " << p2.age << endl;
}

void test_14b() {
	Person_14* p = NULL;
	p->show_14a();//空指针调用成员函数
	p->show_14b();
}


//void main() {
//	test_14a();
//	test_14b();
//}
