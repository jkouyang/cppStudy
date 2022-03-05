/*常量指针，指针常量
* 语法：
	常量指针：const int* p = &a;
	指针常量：int* const p = &a;
	常量指针常量：const int* const p = &a;

总结：
	常量指针：本质指针，指向的对象是常量，不能通过指针来修改指向对象，但是其本身是一个变量，因此可以被重新赋值
	指针常量：本质常量，常量的值是一个指针，指向不能变，指向的内容可变
	常量指针常量：常量指针+指针常量
*/

#include<iostream>
using namespace std;


void testDay08_2() {
	int a = 100;
	int b = 200;

	const int* p1 = &a;
	int* const p2 = &a;
	const int* const p3 = &a;

	//1.常量指针
	//*p = 200;//错误，不能通过指针来修改指向对象
	p1 = &b;//但是其本身是一个变量，因此可以被重新赋值
	cout << *p1 << endl;

	//2.指针常量
	//p2 = &b; //错误，指向不能变，指向的内容可变
	*p2 = 150;
	cout << *p2 << endl;
	cout << a << endl;

	//3.常量指针常量：常量指针 + 指针常量
	//*p3 = 200;//错误，指向的内容不能变
	//p3 = &b;//错误，指向不能变
}

//void main() {
//	testDay08_2();
//}