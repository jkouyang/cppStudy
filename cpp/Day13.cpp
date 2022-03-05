/*Day13
C++中类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上
*/

#include<iostream>
using namespace std;

class Person_13a {};

class Person_13b {
	int a;//非静态成员变量
};

class Person_13c {
	int a;//非静态成员变量
	static int static_13c;//静态成员变量
};
int Person_13c::static_13c = 0;
class Person_13d {
	int a;//非静态成员变量
	static int static_13d;//静态成员变量
	void func_13() {}
};

void test_13() {
	//编译器会给空对象分配一个字节空间，为了区分空对象占内存的位置
	cout << "空类占字节数：" << sizeof(Person_13a) << endl;
	//非静态成员变量  属于类的对象上
	cout << "(只含非静态成员变量)类占字节数：" << sizeof(Person_13b) << endl;
	//静态成员变量    不属于类的对象上
	cout << "(非静态成员变量+静态成员变量)类占字节数：" << sizeof(Person_13c) << endl;
	//成员函数        不属于类的对象上
	cout << "(非静态成员变量+静态成员变量+函数)类占字节数：" << sizeof(Person_13d) << endl;
}


//void main() {
//	test_13();
//}