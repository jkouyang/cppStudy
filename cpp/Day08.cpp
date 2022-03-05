/*Day08
引用
	引用：给变量起一个别名
	语法：数据类型 &别名=原名；

	(1)引用一定要初始化
		int &c;//错误，要让b初始化引用指向a
	(2)引用初始化后，不能更改
		int &c=a;
		int &c=b;//错误，不能更改引用的指向
	(3)不要返回局部变量的引用，值会改变
	(4)函数的返回值为引用的时候，函数调用可以作为左值（等式左边）
	(5)引用本质：指针常量；指向不可以修改，指向的值可以修改
		int &ref = a;//自动转换 int* const ref = & a;//指针常量
		ref = 20;//内部发现ref是引用，自动转化为*ref = 20;
	(6)常量引用 const int& ref =10;
****C++推荐使用引用，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了
*/

#include <iostream>
#include <string>

using namespace std;

//创建引用
int g08_a = 10;
int g08_b = 10;
int& c = g08_a;
//int& c = g_b;///错误，不能更改引用的指向

void swap(int &a, int &b) {//引用传递，形参会修饰实参
	int temp = b;
	b = a;
	a = temp;
}

int& test01() {//不要返回局部变量的引用
	int l_a = 10;
	return l_a;
}

int& test02() {//不要返回局部变量的引用
	static int static_b = 10;
	return static_b;
}

void showValue(const int& ref) {//使用常量引用，让变量只能被访问，不能修改
	//ref += 10;//只能被访问，不能修改
	cout << "打印g08_a="<< ref << endl;
}

//void main() {
//
//	cout << "原始a,b的值" << endl;
//	cout << "g_a=" << g08_a << endl;
//	cout << "g_b=" << g08_b << endl;
//	c = 20;
//	cout << endl << "修改引用c后（c引用a），g_a,g_b的值" << endl;
//	cout << "g_a=" << g08_a << endl;
//	cout << "g_b=" << g08_b << endl;
//
//	swap(g08_a, g08_b);//引用传递，形参会修饰实参
//	cout << endl << "引用传递后（swap(int &a, int &b)），g_a,g_b的值" << endl;
//	cout << "g_a=" << g08_a << endl;
//	cout << "g_b=" << g08_b << endl;
//
//	cout << endl << "不要返回局部变量的引用，值会改变，因为数据存放在栈区" << endl;
//	int &return_l_a = test01();
//	cout << "l_a=" << return_l_a << endl;
//	cout << "l_a=" << return_l_a << endl;
//	cout << "l_a=" << return_l_a << endl;
//
//	int& return_l_b = test02();
//	cout << endl << "全局变量的引用，值会不会变，因为数据存放在全局区" << endl;
//	cout << "static_b=" << return_l_b << endl;
//	cout << "static_b=" << return_l_b << endl;
//	cout << "static_b=" << return_l_b << endl;
//
//	test02() = 123;//函数的返回值为引用的时候，函数调用可以作为左值（等式左边），修改static_b=1123；
//	cout << endl << "函数调用作为左值（等式左边），修改static_b" << endl;
//	cout << "static_b=" << return_l_b << endl;
//
//	//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
//	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
//	const int& ref = 10;
//
//	//ref = 100;  //加入const后不可以修改变量
//	cout << endl << "常量引用ref="<< ref << endl;
//
//	showValue(g08_a);
//}