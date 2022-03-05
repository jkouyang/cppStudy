/*弱引用智能指针 weak_ptr	只是监测资源，并不管理资源
* #include <memory>
	智能指针weak_ptr可看做shared_ptr的助手
	weak_ptr没有重载操作符 * 和 ->，因为它不共享指针，不能操作资源，
	它的构造不会增加引用计数，析构也不会减少引用计数，
	它的主要作用就是作为一个旁观者监视 shared_ptr 中管理的资源是否存在

* 初始化
	默认构造函数
	拷贝构造
	通过shared_ptr对象构造

* weak_ptr内的方法
	use_count();
	reset();
	expired();来判断观测的资源是否已经被释放，释放返回true
	lock();返回weak_ptr所监测资源的 shared_ptr 对象

* weak_ptr应用
	解决返回this的shared_ptr(本质是堆区数据的原始地址重复初始化智能指针)
	解决循环引用的问题
*/

#include<iostream>
#include<string>
#include<vector>
#include <memory>
#include <array>
using namespace std;

void structWeakPtr() {
	shared_ptr<int> sptr1(new int(10));

//默认构造函数
	weak_ptr<int> wptr1;

//拷贝构造
	weak_ptr<int> wptr2(wptr1);

//通过shared_ptr对象构造
	weak_ptr<int> wptr3(sptr1);
	weak_ptr<int> wptr4 = sptr1;

//use_count();
	cout << "wptr1.use_count(): " << wptr1.use_count() << endl;
	cout << "wptr2.use_count(): " << wptr2.use_count() << endl;
	cout << "wptr3.use_count(): " << wptr3.use_count() << endl;
	cout << "wprt4.use_count(): " << wptr4.use_count() << endl;
	cout << "=====================" << endl;

//reset();
	wptr3.reset();

//expired();来判断观测的资源是否已经被释放，未初始化，或者指向为空都视为已经释放
	cout << "wptr1.expired(): " << wptr1.expired() << endl;
	cout << "wptr2.expired(): " << wptr2.expired() << endl;
	cout << "wptr3.expired(): " << wptr3.expired() << endl;
	cout << "wprt4.expired(): " << wptr4.expired() << endl;
	cout << "=====================" << endl;

//lock();返回weak_ptr所监测资源的 shared_ptr 对象
	shared_ptr<int>	sptr2 = wptr4.lock();
	cout << "wptr1.use_count(): " << wptr1.use_count() << endl;
	cout << "wptr2.use_count(): " << wptr2.use_count() << endl;
	cout << "wptr3.use_count(): " << wptr3.use_count() << endl;
	cout << "wprt4.use_count(): " << wptr4.use_count() << endl;
	cout << "=====================" << endl;
}


//=====================解决返回this的shared_ptr(本质是堆区数据的原始地址重复初始化智能指针)
//class getThisWeakPtr{
class getThisWeakPtr:public enable_shared_from_this<getThisWeakPtr> {//调用模板类
//解决返回this的shared_ptr(本质是堆区数据的原始地址重复初始化智能指针)
public:
	shared_ptr<getThisWeakPtr> getThis() {
		//return shared_ptr<proWeakPtr>(this);
		return shared_from_this();//调用模板类的函数
	}
	~getThisWeakPtr() {
		cout << "getThisWeakPtr析构函数" << endl;
	}
};

void thisWeakPtr() {//weak_ptr解决返回this的shared_ptr
	shared_ptr<getThisWeakPtr> sptr1(new getThisWeakPtr());
	shared_ptr<getThisWeakPtr> sptr2(sptr1->getThis());
	cout << "sptr1.use_count():" << sptr1.use_count() << endl;
	cout << "sptr2.use_count():" << sptr2.use_count() << endl;
}


//=====================解决循环引用的问题
class AWeakPtr;//声明类
class BWeakPtr;//声明类
class AWeakPtr {
public:
	//shared_ptr<BWeakPtr> Asptr;
	weak_ptr<BWeakPtr> Asptr;
	~AWeakPtr() { cout << "AWeakPtr的析构" << endl; }
};

class BWeakPtr {
public:
	shared_ptr<AWeakPtr> Bsptr;
	~BWeakPtr() { cout << "BWeakPtr的析构" << endl; }
};

void loopWeakPtr() {//weak_ptr解决循环引用的问题
	cout << "=====================" << endl;
	shared_ptr<AWeakPtr> sptr1(new AWeakPtr());
	shared_ptr<BWeakPtr> sptr2(new BWeakPtr());
	cout << "sptr1.use_count():" << sptr1.use_count() << endl;
	cout << "sptr2.use_count():" << sptr2.use_count() << endl;

	sptr1->Asptr = sptr2;
	sptr2->Bsptr = sptr1;
	cout << "sptr1.use_count():" << sptr1.use_count() << endl;
	cout << "sptr2.use_count():" << sptr2.use_count() << endl;

}


//void main() {
//	structWeakPtr();
//	thisWeakPtr();//weak_ptr解决返回this的shared_ptr(本质是堆区数据的原始地址重复初始化智能指针)
//	loopWeakPtr();//weak_ptr解决循环引用的问题
//}