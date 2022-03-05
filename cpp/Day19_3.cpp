/*
纯虚函数和抽象类
纯虚函数：
	在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
	因此可以将虚函数改为**纯虚函数**
	纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0 ;
	当类中有了纯虚函数，这个类也称为==抽象类==

抽象类特点：
	1.无法实例化对象
	2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类

*/



#include<iostream>
#include<string>

using namespace std;

class Base_19_3 {
public:
	virtual void func() = 0;//当类中只要有一个纯虚函数，这个类也称为==抽象类==

};

class Son_19_3 :public Base_19_3 {//子类必须重写抽象类中的纯虚函数，否则也属于抽象类
public:
	virtual void func() {
		cout << "子类必须重写抽象类中的纯虚函数" << endl;
	}

};

void test_19_3() {
	//Base_19_3 a;//抽象类无法实例化对象，报错
	//new Base_19_3;//抽象类无法使用new开辟空间，报错
	Son_19_3 a;
	Base_19_3* p = new Son_19_3;
	p->func();
}

//void main() {
//	test_19_3();
//}
