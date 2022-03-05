/*共享智能指针	shared_ptr
* #include <memory>
 
* 智能指针：
	存储指向动态分配（堆）对象指针的类，用于生存期的控制
	能够确保在离开指针所在作用域时，自动地销毁动态分配的对象，防止内存泄露
	智能指针的核心实现技术是引用计数，每使用它一次，内部引用计数加1，每析构一次内部的引用计数减1
	减为0时，删除所指向的堆内存

* 共享智能指针shared_ptr：
	指多个智能指针可以同时管理同一块有效的内存，共享智能指针 shared_ptr 是一个模板类，
	如果要进行初始化有三种方式：通过构造函数、std::make_shared 辅助函数以及 reset 方法。
	共享智能指针对象初始化完毕之后就指向要管理的那块堆内存，
	如果想要查看当前有多少个智能指针同时管理着这块内存可以使用共享智能指针提供的一个成员函数 use_count

* shared_ptr初始化：
	默认构造函数	(new 数据)
	拷贝构造		(ptr)
	移动构造		(move(ptr))
	make_shared		(数据)//不用new，make_shared自带new
	reset			(new 数据)
		注意：如果想用同一个堆区域数据，不要用数据的原始地址去重复初始化智能指针，
			  请用一个智能指针去初始化另一个智能指针
			int* p = new int(0);
			shared_ptr<int> sptr1(p);
			shared_ptr<int> sptr2(p);
			shared_ptr<int> sptr3(p);
		上面的代码在析构时后报错，sptr123的计数都是1，会重复析构

* shared_ptr操作数据
	直接利用智能指针完成数据的读写
	调用共享智能指针类提供的get()方法得到原始地址T* get() const noexcept;再利用原始地址操作

* 删除器(智能指针的释放内存)
	离开指针的作用域(指针计数为0) —— 删除指针指向的堆内存，释放空间
	可用函数指针自定义删除器 —— lambda表达式无捕获列表时返回的就是一个函数指针
	可使用lambda表达式自定义删除器
*/

#include<iostream>
#include<string>
#include<vector>
#include <memory>
#include <array>
using namespace std;

class claSharedPtr {
public:
	int a;
	claSharedPtr(int a) :a(a) {
		cout << "claSharedPtr("<< a << ")构造函数" << endl;
	}
	~claSharedPtr() {
		cout << "claSharedPtr(" << a << ")析构函数" << endl;
	}
};

//构造智能指针shared_ptr并操作数据
void structSharedPtr() {
//1.默认构造函数
	cout << "1.调用默认构造函数===========" << endl;
	//shared_ptr<int> ptr1 = new int(10);//报错，等号两边不相等，左边智能指针，右边普通指针
	shared_ptr<int> ptr1(new int(10));
	//最好用array和vector代替数组，早期版本不支持动态数组，且要自己重新定义析构函数
	//自定义析构函数：[](int* p) {delete[] p; }	或	default_delete<int[]>()		主要是delete和delete[]的区别
	shared_ptr<int[]> ptrArry(new int[10](), [](int* p) {delete[] p; });
	cout << "ptr1管理的内存引用计数:" << ptr1.use_count() << endl;
	//智能指针没有被初始化或者被初始化为 nullptr 空指针，引用计数不会 + 1

//2.拷贝构造
	cout << endl << "2.调用拷贝构造===============" << endl;
	shared_ptr<int> ptr2 = ptr1;
	//shared_ptr<int> ptr2(ptr1);//两种拷贝构造的写法都可以
	cout << "ptr1管理的内存引用计数:" << ptr1.use_count() << endl;
	cout << "ptr2管理的内存引用计数:" << ptr2.use_count() << endl;

//3.移动构造
	cout << endl << "3.调用移动构造===============" << endl;
	shared_ptr<int> ptr3 = move(ptr1);
	cout << "ptr1管理的内存引用计数:" << ptr1.use_count() << endl;
	cout << "ptr2管理的内存引用计数:" << ptr2.use_count() << endl;
	cout << "ptr3管理的内存引用计数:" << ptr3.use_count() << endl;

//4.通过make_shared初始化
	cout << endl << "4.通过make_shared初始化======" << endl;
	shared_ptr<array<int, 10>> ptr4 = make_shared<array<int, 10>>(array<int, 10>{0});//构建内置数据类型
	
	shared_ptr<claSharedPtr> ptr5 = make_shared<claSharedPtr>(claSharedPtr(10));
	//构建类，上面这种写法其实是先零时构造一个匿名对象，再智能指针指向匿名对象(不推荐这种写法)
	//可简写(建议这种写法)，不会产生匿名对象
	cout << "ptr4管理的内存引用计数:" << ptr4.use_count() << endl;
	cout << "ptr4管理的内存引用计数:" << ptr4.use_count() << endl;
	shared_ptr<claSharedPtr> ptr6 = make_shared<claSharedPtr>(20);
	cout << "ptr4管理的内存引用计数:" << ptr4.use_count() << endl;
	cout << "ptr5管理的内存引用计数:" << ptr5.use_count() << endl;
	cout << "ptr6管理的内存引用计数:" << ptr6.use_count() << endl;

//5.使用reset释放和重新初始化
	cout << endl << "5.使用reset释放==============" << endl;
	ptr2.reset();
	cout << "ptr1管理的内存引用计数:" << ptr1.use_count() << endl;
	cout << "ptr2管理的内存引用计数:" << ptr2.use_count() << endl;
	cout << "ptr3管理的内存引用计数:" << ptr3.use_count() << endl;

	cout << endl << "5.使用reset初始化============" << endl;
	ptr1.reset(new int[10](), [](int* p) {delete[] p;});//不建议使用数组，要重新定义析构函数，且C++17前不支持
	cout << "ptr1管理的内存引用计数:" << ptr1.use_count() << endl;
	cout << "ptr2管理的内存引用计数:" << ptr2.use_count() << endl;
	cout << "ptr3管理的内存引用计数:" << ptr3.use_count() << endl;

//6.shared_ptr操作数据
	cout << endl << "6.shared_ptr操作数据=========" << endl;
	//对内置数据类型的操作，可以像普通指针一样的使用智能指针调用数据
		//目前ptr3指向int，ptr4指向array<int,10>
		cout << *ptr3 << endl;
		(*ptr4)[3] = 10;
		ptr4->at(4) = 5;//直接通过智能指针操作
		array<int, 10>* aa = ptr4.get();//通过智能指针的get()获取数据对应的地址
		aa->at(5) = 2;
		for (auto&& it : *ptr4) { cout << it << " "; }; cout << endl;
	//对对象的操作
		//目前ptr5，ptr6指向claSharedPtr类型的对象
		cout << "ptr5->a:" << ptr5->a << "\tptr6->a:" << ptr6->a << endl;//直接通过智能指针操作
		claSharedPtr* bb = ptr5.get();
		bb->a = 5; //通过智能指针的get()获取数据对应的地址
		cout << "ptr5->a:" << ptr5->a << "\tptr6->a:" << ptr6->a << endl;//通过get()操作数据
}

//智能指针shared_ptr释放内存的时机
void delteSharedPtr() {
	shared_ptr<claSharedPtr> ptr1(new claSharedPtr(100), [](claSharedPtr* p) {delete p; cout << "删除claSharedPtr(100)" << endl; });
	claSharedPtr* ptr2 = new claSharedPtr(200);//未删除，内存泄露
}

void testSharedPtr() {
	structSharedPtr();
	cout << endl << "7.智能指针shared_ptr释放内存的时机" << endl;
	delteSharedPtr();
	cout << "测试结束" << endl;
}

//void main() {
//	testSharedPtr();
//}
