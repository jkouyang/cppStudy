/*函数调用运算符()重载
	函数调用运算符()  也可以重载
	由于重载后使用的方式非常像函数的调用，因此称为仿函数
	仿函数没有固定写法，非常灵活

****类当函数用，伪函数
*/

#include<iostream>
#include<string>
using namespace std;

class class_17_4a {
public:
	void operator()() {
		cout << "函数调用运算符()重载" << endl;
	}
	void showprint() {
		cout << "匿名对象调用普通函数" << endl;
	}
};

class class_17_4b {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

void test_17_4() {
	class_17_4a cla;//先创建对象，然后对象当函数用
	cla();//伪函数的调用
	class_17_4b clb;
	cout << "a+b两数之和：" << clb(10,15) << endl;

	//匿名对象，不实例化对象，直接调用类里面的函数
	class_17_4a().showprint();//匿名对象调用普通函数
	cout << "匿名对象调用伪函数：a+b两数之和：" << class_17_4b()(10, 15) << endl;//匿名对象调用伪函数

}

//void main() {
//	test_17_4();
//}