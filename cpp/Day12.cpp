/*Day12
静态成员，静态方法

静态成员变量
	1.所有对象共享同一份数据
	2.在编译阶段分配内存
	3.类内声明，类外初始化(重点)

静态成员函数
	1.所有对象共享同一个函数
	2.静态成员函数只能访问静态成员变量



*/
#include<iostream>
#include<string>
using namespace std;

class Person_12 {
public:
	static int static_12a;
	int nostatic;
	static void fuc_12a() {
		cout << "静态方法fuc_12a(puplic)" << endl;
		//nostatic = 100;//静态函数只能访问静态成员，非静态成员的静态函数不能访问
	}

private:
	static int static_12b;
	static void fuc_12b() {
		cout << "静态方法fuc_12b(private)" << endl;
	}
};

int Person_12::static_12a = 0;
int Person_12::static_12b = 0;


void test_12() {
	//静态成员变量和静态成员方法两种访问方式
	//1、通过对象
	Person_12 person;
	person.static_12a = 100;
	//person.static_12b = 100;//私有的静态成员不可访问
	cout << "static_12a = " << person.static_12a << endl;
	person.fuc_12a();
	//2、通过类名
	cout << "static_12a = " << Person_12::static_12a << endl;
	Person_12::fuc_12a();
	//Person_12::fuc_12b();//私有的静态方法不可访问
}

//void main() {
//	test_12();
//}