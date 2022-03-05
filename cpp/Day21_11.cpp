/*类模板和友元

	1.全局函数类内实现 - 直接在类内声明友元即可
	2.全局函数类外实现 - 需要提前让编译器知道全局函数的存在

*/
#include<iostream>
#include<string>
using namespace std;

//声明类
template<class T1, class T2>
class Person_21_11;
//声明模板函数
template<class T1, class T2>
void showPerson_21_11b(Person_21_11<T1, T2>& p);

template<class T1,class T2>
class Person_21_11 {
	//1、全局函数(加了friend就是全局函数)配合友元   类内实现
	friend void showPerson_21_11a(Person_21_11<T1,T2> &p) {
		cout << "Name: " << p.name << "\tAge: " << p.age << endl;
	}
	//2.全局函数类外实现 - 需要提前让编译器知道全局函数的存在
	friend void showPerson_21_11b<>(Person_21_11<T1, T2>& p);
public:
	Person_21_11(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
private:
	T1 name;
	T2 age;
};

template<class T1, class T2>
void showPerson_21_11b(Person_21_11<T1, T2>& p) {//2.全局函数配合友元  类外实现
	cout << "Name: " << p.name << "\tAge: " << p.age << endl;
}

void test_21_11() {
	Person_21_11<string, int> p("Tom", 20);
	showPerson_21_11a(p);
	showPerson_21_11b(p);
}

//void main() {
//	test_21_11();
//	system("pause");
//}