/*
拷贝构造函数的调用时机：
	1.使用一个已经创建完毕的对象来初始化一个新对象
	2.值传递的方式给函数参数传值
	3.以值方式返回局部对象
*/
#include<iostream>
using namespace std;

class Person_11_2 {
public:
	Person_11_2() {
		cout << "无参构造函数!" << endl;
		this->age = 0;
	}
	Person_11_2(int age) {
		cout << "有参构造函数!" << endl;
		this->age = age;
	}
	Person_11_2(const Person_11_2& p) {
		cout << "拷贝构造函数!" << endl;
		this->age = p.age;
	}
	//析构函数在释放内存之前调用
	~Person_11_2() {
		cout << "析构函数!" << endl;
	}
public:
	int age;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test_11_2a() {
	cout << "*****1.使用一个已经创建完毕的对象来初始化一个新对象" << endl;
	Person_11_2 man(100); //p对象已经创建完毕
	Person_11_2 newman(man); //调用拷贝构造函数
	Person_11_2 newman2 = man; //拷贝构造

	//Person newman3;
	//newman3 = man; //不是调用拷贝构造函数，赋值操作
}

//2. 值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person_11_2 p1) {}
void test_11_2b() {
	cout << endl << "*****2.值传递的方式给函数参数传值" << endl;
	Person_11_2 p; //无参构造函数
	doWork(p);
}

//3. 以值方式返回局部对象
Person_11_2 doWork2()
{
	Person_11_2 p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test_11_2c()
{
	cout << endl << "*****3.以值方式返回局部对象" << endl;
	Person_11_2 p = doWork2();
	cout << (int*)&p << endl;
}


//void main() {
//	test_11_2a();
//	test_11_2b;
//	test_11_2c();
//}