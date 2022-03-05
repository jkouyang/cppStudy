/* 异步线程	async	future

* async与future：
	async是一个函数模板，用来启动一个异步线程，它返回一个future类模板对象，
	future对象起到了占位的作用，刚创建实例化时的future是没有储存值的，
	但在调用future对象的get()成员函数时，主线程会被阻塞直到异步线程执行结束，并把返回结果传递给future，即通过FutureObject.get()获取函数返回值

* 语法：future<T> obj = async(funcPtr, 参数1, 参数2, ...);
	T为函数指针指向函数的返回值类型，参数1、2...为函数对应的参数
	最终函数的返回值存储再obj中，可用obj.get()调用，但只能调用一次

*shared_future ——	解决obj.get()只能调用一次的问题
	future的get()成员函数是转移数据所有权;shared_future的get()成员函数是复制数据。
	future对象的get()只能调用一次；无法实现多个线程等待同一个异步线程，一旦其中一个线程获取了异步线程的返回值，其他线程就无法再次获取
	shared_future对象的get()可以调用多次；可以实现多个线程等待同一个异步线程，每个线程都可以获取异步线程的返回值

*/

#include<iostream>
#include<thread>
#include <windows.h>
#include<future>
using namespace std;

double futureThread_4(double a,double b) {
	Sleep(3000);
	return a + b;
}

void testThread_4() {
	future<double> fu = async(futureThread_4, 3.14, 6.28);//创建异步线程线程，并将线程的执行结果用fu占位；
	shared_future<double> sharedfu = async(futureThread_4, 3.14, 6.28);//创建异步线程线程，并将线程的执行结果用fu占位；
	//主线程可以继续往下走，直到调用get()时阻塞
	cout << "先干点别的事情！" << endl;
	cout << "先干点别的事情！" << endl;
	cout << "先干点别的事情！" << endl;
	cout << "先干点别的事情！" << endl;

	cout << "等待返回结果fu.get()：" << fu.get() << endl;//阻塞在这里等待结果
	cout << "等待返回结果sharedfu.get()：" << sharedfu.get() << endl;//阻塞在这里等待结果
	try {cout << "再一次返回结果：" << fu.get() << endl;}
	catch(...){cout << "future.get()不能调用两次" << endl; }//future.get()不能调用两次

	cout << "再次返回结果sharedfu.get()：" << sharedfu.get() << endl;//sharedfu.get()可以多次调用
	cout << "再次返回结果sharedfu.get()：" << sharedfu.get() << endl;

}

//void main() {
//	testThread_4();
//}
