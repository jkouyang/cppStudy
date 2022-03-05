/*内建函数对象——STL内建了一些函数对象
分类:
1.算术仿函数
2.关系仿函数
3.逻辑仿函数

用法：
1.这些仿函数所产生的对象，用法和一般函数完全相同
2.使用内建函数对象，需要引入头文件 #include<functional>
*/

/*算术仿函数
功能描述：
	实现四则运算
	其中negate是一元运算，其他都是二元运算

**仿函数原型：**
	1.template<class T> T plus<T>//加法仿函数
	2.template<class T> T minus<T>//减法仿函数
	3.template<class T> T multiplies<T>//乘法仿函数
	4.template<class T> T divides<T>//除法仿函数
	5.template<class T> T modulus<T>//取模仿函数
	6.template<class T> T negate<T>//取反仿函数

	*其中negate是一元运算，其他都是二元运算
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void testFunobj_3() {
	//+
	plus<int> p1;//因为只能同种数据类型相加，所以传一个参数类型就可以了
	cout << p1(10, 20) << endl;
	//-
	minus<double> p2;
	cout << p2(10.23, 20) << endl;
	//*
	multiplies<double> p3;
	cout << p3(3.15, 2) << endl;
	//÷
	divides<double> p4;
	cout << p4(10.23, 2) << endl;
	//%
	modulus<int> p5;
	cout << p5(10, 3) << endl;
	//取反
	negate<int> p6;
	cout << p6(10) << endl;

}

//void main() {
//	testFunobj_3();
//}