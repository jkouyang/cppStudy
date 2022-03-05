/*Day20:模板——建立通用的模具，大大提高复用性（泛型编程）
	1.C++两种编程思想：面向对象编程、泛型编程
	2.C++提供两种模板机制:函数模板、类模板

函数模板：
	1.语法：template<typename T> 函数模板声明，一定就写在函数上面一行
			template  ---  声明创建模板
			typename  --- 表面其后面的符号是一种数据类型，可以用class代替
			T    ---   通用的数据类型，名称可以替换，通常为大写字母
	2.使用：有两种方式使用函数模板
			2.1自动类型推导
			2.2显示指定类型
	3.注意：
			3.1自动类型推导，必须推导出一致的数据类型T,才可以使用
			3.2模板必须要确定出T的数据类型，才可以使用
*/

#include<iostream>
using namespace std;

//函数模板
//声明一个模板，告诉编译器后面的代码中紧跟着的T不要报错，T是一个通用测数据类型
template<typename T>//一定就写在函数上面一行
void mySwap_21_1(T &a,T &b) {//通用的交换函数，不用再将每种数据类型都定义一个函数
	T temp = a;
	a = b;
	b = temp;
}

template<class T>//这里typename和class区别不大，都可
void func_21_1() {
	cout << "模板必须要确定出T的数据类型，才可以使用" << endl;
}

void test_21_1() {
	int a = 10;
	int b = 20;

	//有两种方式使用函数模板
	//1、自动类型推导
	mySwap_21_1(a, b);

	//2、显示指定类型
	mySwap_21_1<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//func_21_1();//模板必须要确定出T的数据类型，才可以使用，不然报错
	func_21_1<int>();//可以随便给它一个数据类型就可以使用模板函数
}

//void main() {
//	test_21_1();
//	system("pause");
//}