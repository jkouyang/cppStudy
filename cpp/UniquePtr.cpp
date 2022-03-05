/*独占智能指针 unique_qtr
* #include <memory>

*unique_qtr初始化
	1.通过构造函数初始化	(new 数据)
	2.通过移动构造初始化	(move(ptr))
	3.make_unique			(数据)//不用new，make_unique自带new
	4.通过reset初始化		(new 数据)

* 操作数据
	获取原指针 ptr 或 get()

*删除器
	unique_ptr 指定删除器和 shared_ptr 指定删除器是有区别的，unique_ptr 指定删除器的时候需要确定删除器的类型
	离开指针的作用域 —— 删除指针指向的堆内存，释放空间
	可用函数指针自定义删除器 —— lambda表达式无捕获列表时返回的就是一个函数指针
	可使用lambda表达式自定义删除器
*/


#include<iostream>
#include<string>
#include<vector>
#include <memory>
#include <array>
using namespace std;

void structUniquePtr() {//unique_ptr构造函数
//1.通过构造函数初始化
	unique_ptr<int> ptr1(new int(10));
	//unique_ptr没有use_count()成员函数，unique_ptr不能拷贝构造
	//cout << "ptr1管理的内存引用计数:" << ptr1.use_count() << endl;//error
	//unique_ptr<int> ptr2 = ptr1;//error,不允许将一个unique_ptr赋值给另一个unique_ptr
	
//2.通过移动构造初始化
	unique_ptr<int> ptr2(move(ptr1));
	if (ptr1 == nullptr) { cout << "移动构造后原指针ptr1为nullptr" << endl; }

//3.make_unique
	unique_ptr<int> ptr3 = make_unique<int>(20);
	
//4.通过reset初始化
	ptr3.reset();//int(20)被释放
	ptr3.reset(new int(15));//ptr3指向new int(15)
	cout << "*ptr3:" << *ptr3 << endl;

//5.操作数据
	//ptr 或 get()
}

class claUniquePtr {
public:
	int a;
	claUniquePtr(int a) :a(a) {
		cout << "claUniquePtr(" << a << ")构造函数" << endl;
	}
	~claUniquePtr() {
		cout << "claUniquePtr(" << a << ")析构函数" << endl;
	}
};

void deleteUniquePtr() {
	//unique_ptr 指定删除器和 shared_ptr 指定删除器是有区别的，unique_ptr 指定删除器的时候需要确定删除器的类型
	using func_ptr = void(*)(claUniquePtr* p);
	unique_ptr<claUniquePtr, func_ptr> ptr1(new claUniquePtr(100), [](claUniquePtr* p)->void {delete p; cout << "删除claUniquePtr(100)" << endl; });
	claUniquePtr* ptr2 = new claUniquePtr(200);
}

void testUniquePtr() {
	structUniquePtr();
	deleteUniquePtr();
	cout << "测试结束" << endl;
}

//void main() {
//	testUniquePtr();
//}