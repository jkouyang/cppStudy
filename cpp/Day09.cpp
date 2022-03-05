/*Day09
函数高级
	(1)函数默认参数  返回值类型 函数名(参数= 默认值){}
		//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
		//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数(函数声明和实现只能有一个有默认参数)
			int func(int a=10; int b=10);//函数声明
			int func(int a=10; int b=10){return a+b;}//函数实现
			//上述例子错误，函数声明和实现只能有一个有默认参数
			int func(int a; int b);//函数声明
			int func(int a=10; int b=10){return a+b;}//函数实现
		//3. 有传入的参数就用传入的参数，没有就要用默认值
	(2)函数占位参数  返回值类型 函数名 (数据类型){}  void func(int a, int) {}
		//1. C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
		//2. 函数占位参数 ，占位参数也可以有默认参数  void func(int a, int = 10) {}
		//3. 在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术
	(3)函数重载  函数名可以相同，提高复用性
		//1. 满足条件：同一个作用域下；函数名称相同；函数参数类型不同或者个数不同或者顺序不同；
		//2. 函数返回值不可以作为函数重载条件
		//3. 注意：	* 引用作为重载条件
					* 函数重载碰到函数默认参数
*/

#include <iostream>
#include <string>

using namespace std;

//函数默认参数
int sum_3(int a, int b = 10, int c = 10) {//求三数之和
	return a + b + c;
}

//函数占位参数
void placeholder(int a, int) {
	cout << "This is placeholder func." << endl;
}

//引用作为重载条件
void ref_overloading(int& a)
{
	cout << "ref_overloading (int &a) 调用 " << endl;
}
void ref_overloading(const int& a)
{
	cout << "ref_overloading (const int &a) 调用 " << endl;
}

//默认参数碰到函数重载
void def_overloading(int a,int b = 10) {
	cout << "def_overloading (int a; int b = 10) 调用 " << endl;
}
void def_overloading(int a) {
	cout << "def_overloading (int a) 调用 " << endl;
}

//void main() {
//	//调用有默认参数的函数时，默认的参数位置可以传值也可不传
//	cout << "默认参数" << endl;
//	cout << "sum_3 = " << sum_3(20, 20) << endl;
//	cout << "sum_3 = " << sum_3(100) << endl;
//	
//	//调用有占位参数(非默认)的函数时，占位参数必须填补，占位参数为默认参数时可填补可不填补
//	cout << endl << "占位参数" << endl;
//	placeholder(10, 10); //占位参数必须填补
//
//	//引用作为重载条件,根据传入的类型调用，指针常量(调用无const)，常量指针常量(调用const)
//	int a = 10;
//	const int b = 10;
//	cout << endl << "引用作为重载条件" << endl;
//	ref_overloading(a); //a为变量，调用无const
//	ref_overloading(b); //b为常量，调用const
//	ref_overloading(10);//int &a = 10 不合法，const int &a = 10 合法；所以调用有const
//
//	//默认参数碰到函数重载
//	cout << endl << "默认参数碰到函数重载" << endl;
//	//def_overloading(10);//报错，不知道调用哪个
//	def_overloading(10, 10);
//}
