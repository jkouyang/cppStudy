/*函数对象
概念：
	重载函数调用操作符()的类，其对象常称为**函数对象**
	函数对象使用重载的()时，行为类似函数调用，也叫**仿函数**

本质：
	函数对象(仿函数)是一个**类**，不是一个函数

函数对象使用
特点：
	1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
	2.函数对象超出普通函数的概念，函数对象可以有自己的状态
	3.函数对象可以作为参数传递

*/

#include<iostream>
#include<string>
using namespace std;

//1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class myAddFunobj_1 {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

void testFunobj_1a() {
	myAddFunobj_1 myadd;
	cout << myadd(10, 10) << endl;//先创建对象再调用
	cout << myAddFunobj_1()(10, 10) << endl;//用匿名对象调用

}

//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class myPrintFunobj_1 {
public:
	int count;//记录状态
	myPrintFunobj_1() {
		count = 0;
	}
	void operator()(string str) {
		cout << str << endl;
		count++;//统计使用的次数
	}

};

void testFunobj_1b() {
	myPrintFunobj_1 myprint;
	myprint("Hello!");//先创建对象再调用
	myprint("Hello!");//先创建对象再调用
	myprint("Hello!");//先创建对象再调用
	myprint("Hello!");//先创建对象再调用
	myPrintFunobj_1()("Hello!");//用匿名对象调用
	//匿名对象每次调用完之后都会被销毁，不计次数
	cout << "myprint()调用的次数：" << myprint.count << endl;
	cout << "匿名对象myprint()调用的次数：" << myPrintFunobj_1().count << endl;
}


//3.函数对象可以作为参数传递，（普通对象也可以进行参数传递呀，不知道这一点有什么区别）
void  doPrintFunobj_1(myPrintFunobj_1& myprint, string str) {
	myprint(str);
}
void testFunobj_1c() {
	myPrintFunobj_1 myprint;
	doPrintFunobj_1(myprint, "你好！");
}


//void main() {
//	//testFunobj_1a();
//	//testFunobj_1b();
//	testFunobj_1c();
//}