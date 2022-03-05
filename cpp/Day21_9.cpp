/*类模板与继承

当类模板碰到继承时，需要注意一下几点：
	1.当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
	2.如果不指定，编译器无法给子类分配内存
	3.如果想灵活指定出父类中T的类型，子类也需变为类模板

类模板中成员函数类外实现时，需要加上模板参数列表
*/

#include<iostream>
using namespace std;

template<class T>
class Base_21_9 {
public:
	T age;
	Base_21_9() {
		cout << "父类T的数据类型：" << typeid(T).name() << endl;
	}
};

//class Son_21_9 :public Base_21_9//错误，如果不指定，编译器无法给子类分配内存
class Son_21_9a :public Base_21_9<int> {//1.必须要知道父类中的T类型，才能继承给子类
public:
	Son_21_9a() {
		cout << "1.必须要知道父类中的T类型，才能继承给子类" << endl;
	}
};

//3.如果想灵活指定出父类中T的类型，子类也需变为类模板
template<class T1, class T2>
class Son_21_9b :public Base_21_9<T1> {//1.必须要知道父类中的T类型，才能继承给子类
public:
	T2 var;
	Son_21_9b();
	void sayChar(T1 a);	
};

template<class T1, class T2>//类模板构造函数的类外实现，需要加上模板全部参数列表
Son_21_9b<T1,T2>::Son_21_9b(){
	cout << "3.如果想灵活指定出父类中T的类型，子类也需变为类模板" << endl;
	cout << "子类T1的数据类型：" << typeid(T1).name() << endl;
	cout << "子类T2的数据类型：" << typeid(T2).name() << endl;
}

template<class T1, class T2>//类模板普通成员函数的类外实现，需要加上模板全部参数列表
void Son_21_9b<T1, T2>::sayChar(T1 a) {
	cout << "类模板成员函数类外定义，sayChar：" << a << endl;
}

void test_21_9() {
	Son_21_9a obj1;
	Son_21_9b<char, int> obj2;
	obj2.sayChar('a');
}

//void main() {
//	test_21_9();
//	system("pause");
//}