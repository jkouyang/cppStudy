/*
普通函数与函数模板区别：
	1.普通函数调用时可以发生自动类型转换（隐式类型转换）
	2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
	3.如果利用显示指定类型的方式，可以发生隐式类型转换
*/


#include<iostream>
using namespace std;

//普通函数
int add_21_3a(int a, int b) {
	return a + b;
}

//函数模板
template<typename T>
T add_21_3b(T a, T b) {
	return a + b;
}


void test_21_3() {
	//普通函数
	cout << "97+98=" << add_21_3a(97, 98) << endl;
	cout << "a(97)+b(98)=" << add_21_3a('a', 'b') << endl;//隐式转换
	cout << "97.17+98.68=" << add_21_3a(97.17, 98.68) << endl;//隐式转换
	cout << "97+b=" << add_21_3a(97.17, 'b') << endl;//隐式转换
	cout << endl;

	//模板函数
	//1.利用自动类型推导，不会发生隐式类型转换
	cout << "97+98=" << add_21_3b(97, 98) << endl;
	char a = add_21_3b('a', 'b');
	cout << "\\0(0)+b(98)=" << add_21_3b('\0', 'b') << endl;//返回字符型
	cout << "97.17+98.68=" << add_21_3b(97.17, 98.68) << endl;//返回double型
	//cout << "97+b=" << add_21_3b(97.17, 'b') << endl;//报错，不会隐式转换
	cout << endl;

	//2.利用显示指定类型的方式，可以发生隐式类型转换
	cout << "97+98=" << add_21_3b<int>(97, 98) << endl;
	cout << "a(97)+b(98)=" << add_21_3b<int>('a', 'b') << endl;//隐式转换
	cout << "97.17+98.68=" << add_21_3b<int>(97.17, 98.68) << endl;//隐式转换
	cout << "97+b=" << add_21_3a(97.17, 'b') << endl;//隐式转换

}

//void main() {
//	test_21_3();
//}