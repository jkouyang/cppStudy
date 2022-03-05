/*指针函数		函数指针
* 
	指针函数：返回值为指针的函数
	函数指针：指向函数的指针

总结：
	函数名本身就是一个地址，就是一个函数指针
	函数指针可以作为参数进行传递
*/

#include<iostream>
using namespace std;

int* pterDay08_3a(int& val) {//返回指针，指针函数
	val = val + 1;
	return &val;
}

int& pterDay08_3b(int& val) {//返回引用，指针函数
	val = val + 1;
	return val;
}

int pterDay08_3c(int& val) {//普通函数
	val = val + 1;
	return val;
}

void testDay08_3() {
	int value = 1;
	//返回指针，指针函数
	int* p1 = pterDay08_3a(value);
	cout << "value:" << value << "\t\t*p1:" << *p1 << endl;

	//返回引用，指针函数
	int& p2 = pterDay08_3b(value);
	p2++;
	cout << "value:" << value << "\t\tp2:" << p2 << endl;

	//普通函数，来定义成函数指针
	// 直接定义
	int (*func_ptr)(int&);//定义一个指针，指向函数(返回值为int，参数为int&)
	func_ptr = pterDay08_3c;//赋值
	func_ptr(value);
	cout << "value:" << value << endl;

	//typedef
	typedef int(*func_ptr2)(int&);//用typedef给函数指针(返回值为int，参数为int&)别名func_ptr2
	func_ptr2 ptr1 = pterDay08_3c;//定义一个函数指针，并赋值
	ptr1(value);//利用函数指针调用函数
	cout << "value:" << value << endl;

	//using，推荐使用
	using func_ptr3 = int(*)(int&);//用using给函数指针(返回值为int，参数为int&)别名func_ptr3
	func_ptr3 ptr2 = pterDay08_3c;//定义一个函数指针，并赋值
	ptr2(value);//利用函数指针调用函数
	cout << "value:" << value << endl;

}

//void main() {
//	testDay08_3();
//}