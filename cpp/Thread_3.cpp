/*lock_guard()	unique_guard()	手动上锁自动解锁

* lock_guard():
	其原理是：声明一个局部的lock_guard对象lock_guard<mutex> g1(mutex)，在其构造函数中进行加锁，在其析构函数中进行解锁。
	最终的结果就是：创建即加锁，作用域结束自动解锁。从而使用lock_guard()就可以替代lock()与unlock()
	通过设定作用域，使得lock_guard在合适的地方被析构，通过使用{}来调整作用域范围，可使得互斥量m在合适的地方被解锁
    lock_gurad也可以传入两个参数，第二个参数为adopt_lock标识时，表示不再构造函数中不再进行互斥量锁定，因此此时需要提前手动锁定

* unique_lock() —— 比lock_guard()功能更加强大的加锁机制
    首先支持lock_guard()的原有功能
    可以提供弹性加锁服务：即用户指定加锁的地方，也可以指定解锁的地方，还可以将锁的所有权进行转让
    unique_lock的第二个参数可为：adopt_lock，try_to_lock(尝试去锁定)，defer_lock(初始化了一个没有加锁的mutex);
    try_to_lock: 尝试去锁定，得保证锁处于unlock的状态,然后尝试现在能不能获得锁；尝试用mutx的lock()去锁定这个mutex，但如果没有锁定成功，会立即返回，不会阻塞在那里
    defer_lock: 初始化了一个没有加锁的mutex;

*/


#include <iostream>
#include <windows.h>
#include <thread>
#include<mutex>
#include<stdlib.h>
#include <time.h>
using namespace std;

mutex m_lockguard;
mutex m_uniquelock;

void LockGuardThread_3a(int& a)
{
    lock_guard<mutex> g1(m_lockguard);//用此语句替换了m.lock()；lock_guard传入一个参数时，该参数为互斥量，此时调用了lock_guard的构造函数，申请锁定m
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    Sleep(1000);
    a = a + 2;
    cout << "现在a为" << a << endl;
}//此时不需要写m.unlock(),g1出了作用域被释放，自动调用析构函数，于是m被解锁

void LockGuardThread_3b(int& a){
    {
        //lock_gurad也可以传入两个参数，第二个参数为adopt_lock标识时，表示不再构造函数中不再进行互斥量锁定，因此此时需要提前手动锁定。
        m_lockguard.lock();
        lock_guard<mutex> g2(m_lockguard, adopt_lock);//感觉没啥用
        cout << "proc2函数正在改写a" << endl;
        cout << "原始a为" << a << endl;
        Sleep(1000);
        a = a + 1;
        cout << "现在a为" << a << endl;
    }//通过使用{}来调整作用域范围，可使得m在合适的地方被解锁
    cout << "作用域外的内容3" << endl;
    cout << "作用域外的内容4" << endl;
    cout << "作用域外的内容5" << endl;
}

void UniqueLockThread_3a() {
    unique_lock<mutex> g1(m_uniquelock,defer_lock);//初始化了一个没有加锁的mutex
    g1.lock();//手动加锁，注意，不是m.lock();注意，不是m.lock();注意，不是m.lock()
    cout << "上锁111111" << endl;
    g1.unlock();
    Sleep(1000);
    g1.lock();
}//可自动解锁


void UniqueLockThread_3b() {
    unique_lock<mutex> g2(m_uniquelock, try_to_lock);//尝试加锁，但如果没有锁定成功，会立即返回，不会阻塞在那里；
    unique_lock<mutex> g3(move(g2));//所有权转移，此时由g3来管理互斥量m
    cout << "上锁222222" << endl;
    Sleep(1000);
    g3.unlock();
}//可自动解锁

void testThread_3() {
    int a = 0;
    //线程不要和函数重名
    thread thr1(LockGuardThread_3a, ref(a));//测试lock_guard
    thread thr2(LockGuardThread_3b, ref(a));

    thr1.join();//线程1、2没运行完，main()会阻塞在这里，不会向下运行
    thr2.join();

    thread thr3(UniqueLockThread_3a);//测试lock_guard
    thread thr4(UniqueLockThread_3b);
    thr3.join();
    thr4.join();
}

//void main(){
//    testThread_3();
//}