/*类模板对象做函数参数
类模板实例化出的对象，向函数传参的方式
一共有三种传入方式：
	1. 指定传入的类型(常用) --- 直接显示对象的数据类型
	2. 参数模板化			--- 将对象中的参数变为模板进行传递
	3. 整个类模板化			--- 将这个对象类型 模板化进行传递
*/

#include<iostream>
#include<string>
using namespace std;

template<class nameType, class ageType>
class Person_21_8 {
public:
	nameType name;
	ageType age;
	Person_21_8(nameType name, ageType age) {
		this->name = name;
		this->age = age;
	}
	void print() {
		cout << this->name << "  " << this->age << endl;
	}
};

//1、指定传入的类型，通常都用第一种方法
void printPerson_21_8a(Person_21_8<string, int> &p) {
	p.print();
}
//2、参数模板化
template<typename T1, typename T2>
void printPerson_21_8b(Person_21_8<T1, T2>& p) {
	p.print();
	cout << "T1的数据类型为：" << typeid(T1).name() << endl;//获取模板的数据类型
	cout << "T2的数据类型为：" << typeid(T2).name() << endl;
}
//3、整个类模板化
template<class T>
void printPerson_21_8c(T &p) {
	p.print();
	cout << "T的数据类型为：" << typeid(T).name() << endl;
}

void test_21_8() {
	Person_21_8<string, int> p("孙悟空",999);
	//1、指定传入的类型
	printPerson_21_8a(p);
	//2、参数模板化
	printPerson_21_8b(p);
	//3、整个类模板化
	printPerson_21_8c(p);
}

//void main() {
//	test_21_8();
//}