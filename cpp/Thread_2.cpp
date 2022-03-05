/*互斥变量——上锁		mutex m;实例化mmutex对象

* 利用Sleep(int m);模仿io的时间
	其中m为毫秒，1000ms=1s;另外需要导入#include <windows.h>

* 锁
	mutex m;实例化mmutex对象
	m.lock();//m对象上锁
	m.unlock();//m对象解锁
	//如果资源数不等于1，可以定义一个全局变量flag，没调用一次falg-1，当flag=0时上锁
*/

#include <iostream>
#include <windows.h>
#include <thread>
#include<mutex>
#include<stdlib.h>
#include <time.h>
using namespace std;

mutex wThread_2;//写(临界资源),实例化mutex对象，wThread_2是一个mutex类型的对象，可调用其内部成员函数lock();unlock();
mutex cpuThread_2;//cpu(临界资源),实例化mutex对象

static int aThread_2 = 10;
static int bThread_2 = 20;

int readThread_2(int& p) {
	return p;
}

void writeThread_2(int temp, int& b) {
	string str;
	if (b == aThread_2) { str = "A"; }
	else { str = "B"; }
	wThread_2.lock();//写上锁
	cout << str + "正在写入..." << endl;
	Sleep(rand() % 1000 + 500);//休眠，模仿磁盘写入
	b = temp;
	cout << str + "写入完成！" << endl;
	wThread_2.unlock();//写解锁
}

int calTheread_2(int a) {
	string str;
	if (a == aThread_2) { str = "A"; }
	else { str = "B"; }
	cpuThread_2.lock();//cpu上锁
	cout << str + "正在计算..." << endl;
	Sleep(rand() % 1000 + 500);//休眠，模仿cpu计算
	cout << str + "计算完成！" << endl;
	cpuThread_2.unlock();//cpu解锁
	return a*a;
}

void func1Thread_2() {
	srand((unsigned)time(NULL));
	int& p = aThread_2;//磁盘地址
	int a = readThread_2(p);//读取磁盘数据
	int temp = calTheread_2(a);//计算
	writeThread_2(temp, p);//存入
}

void func2Thread_2() {
	int& p = bThread_2;//磁盘地址
	int b = readThread_2(p);//读取磁盘数据
	int temp = calTheread_2(b);//计算
	writeThread_2(temp, p);//存入
}

//假设cpu只有一个核(同时只能计算一个)，磁盘读是共享，磁盘写是互斥的
//如果资源数不等于1，可以定义一个全局变量flag，没调用一次falg-1，当flag=0时上锁
void testThread() {
	cout << "A = " << aThread_2 << endl;
	cout << "B = " << bThread_2 << endl;
	thread thr1(func1Thread_2);//线程1
	thread thr2(func2Thread_2);//线程2
	//线程1、2和主线程main其实是同步的，也就是说上面的线程1、2可以还没完成，main就会接着往下走
	cout << "A = " << aThread_2 << endl;//线程1、2可以还没完成，这时值并未变
	cout << "B = " << bThread_2 << endl;
	thr1.join();
	thr2.join();
	cout << "A = " << aThread_2 << endl;
	cout << "B = " << bThread_2 << endl;
}

//void main() {
//	testThread();
//}