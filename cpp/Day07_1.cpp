/*Day07
栈区：
	栈区由编译器自动分配释放, 存放函数的参数值,局部变量等
	注意事项：**不要返回局部变量的地址，栈区开辟的数据由编译器自动释放**

堆区：
	new可用在堆区开辟数据

利用new操作符在堆区开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete
*/

#include <iostream>
#include <string>

using namespace std;

int* func1(){
	int a = 10;
	return &a;//栈区开辟的数据由编译器自动释放,局部变量的地址不要返回
}

int* func2()
{
	// new可用在堆区开辟数据
	int *a = new int(10);//new返回的是该数据类型的指针
	//指针a是局部变量放在栈区，指针a指向的数据int(10)放在了堆区
	return a;
}

void test1_new() {
	int* p = func2();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete
	delete p;
	//cout << *p << endl;//内存已被释放，再次访问就算非法操作，会报错
}
void test2_new() {
	//创建10整型数组，存放堆区
	int *arr = new int[10];
	for (int i = 0; i < 10; i++) {//赋值
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {//赋值
		cout << arr[i] << endl;
	}
	//释放数组的时候要加[]
	delete[] arr;
}

//void main() {
//
//	int* p1 = func1();
//
//	//*p并不是a的值，func()函数完成后，p指向的空间被释放
//	cout << "栈区开辟的数据由编译器自动释放,局部变量的地址不要返回" << endl;
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//
//	cout << endl << "堆区开辟的数据，由程序员手动开辟，手动释放" << endl;
//	int *p2 = func2();//指针a存放的地址传给了p2，现在指针p2指向的数据int(10)放在了堆区
//	cout << *p2 << endl;
//	cout << *p2 << endl;
//	cout << *p2 << endl;
//	cout << *p2 << endl;
//
//	cout << endl << "测试new和delete" << endl;
//	test1_new();
//	cout << endl << "测试new创建数组" << endl;
//	test2_new();
//
//	system("pause");
//
//}