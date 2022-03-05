/*类模板
类模板中成员函数和普通类中成员函数创建时机是有区别的：
	1.普通类中的成员函数一开始就可以创建
	2.类模板中的成员函数在调用时才创建

*/

#include<iostream>
#include<string>
using namespace std;

class Person_21_7a{
public:
	void showPerson1(){
		cout << "Person1 show" << endl;
	}
};

class Person_21_7b{
public:
	void showPerson2(){
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass_21_7{
public:
	T obj;
	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }
};

void test_21_7(){
	MyClass_21_7<Person_21_7a> m;
	m.fun1();
	//m.fun2();//编译会出错，说明函数调用才会去创建成员函数
}

//int main() {
//	test_21_7();
//	system("pause");
//	return 0;
//}


