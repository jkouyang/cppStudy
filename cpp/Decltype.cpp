/*decltype
	为解决auto只能对变量进行类型推导的缺陷，decltype可对表达式进行推导

语法：decltype (表达式)
	1.表达式为普通变量或者普通表达式或者类表达式，在这种情况下，使用 decltype 推导出的类型和表达式的类型是一致的
	2.表达式是函数调用，使用 decltype 推导出的类型和函数返回值一致。
	3.表达式是左值，或者被()包围，decltype推导出的是表达式类型的引用(如果有 const、volatile限定符不能忽略)

应用：decltype 的应用多出现在泛型编程中

*/

#include<iostream>
#include<vector>
using namespace std;

double testDecltypeFunc() { return 0.1; }

void testDecltype() {
	int a = 10;
	//1.普通变量或者普通表达式或者类表达式，推导出的类型和表达式的类型是一致的
	decltype(a) b;
	//2.表达式是函数调用，使用 decltype 推导出的类型和函数返回值一致
	decltype(testDecltypeFunc()) c;
	//3.表达式是左值，或者被()包围，decltype推导出的是表达式类型的引用(如果有 const、volatile限定符不能忽略)
	decltype((a)) d = a;//()包围
	int m;
	decltype(m = a + b) e = a;//左值
}

//返回类型后置，C++14后可以直接使用auto作为返回值类型
template <typename T, typename U>
//auto add(T t, U u) -> decltype(t + u)  //C++11
auto add(T t, U u)//C++14
{
	return t + u;
}


//void main() {
//	testDecltype();
//}


