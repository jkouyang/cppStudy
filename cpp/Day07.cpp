/*Day07
内存分区模型
C++程序在执行时，将内存大方向划分为4个区域
	代码区：存放函数体的二进制代码，由操作系统进行管理的
	全局区：存放全局变量和静态变量以及常量(const修饰的常量，包含字符串常量)，该区域的数据在程序结束后由操作系统释放（生命周期长）
	栈	区：由编译器自动分配释放, 存放函数的参数值,局部变量等
	堆	区：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收
分区的意义：不同区域存放的数据，赋予不同的生命周期, 给我们更大的灵活编程

程序运行前：代码区，全局区		程序运行后：栈区，堆区

*/

#include <iostream>
#include <string>

using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;


//void main() {
//
//	//创建局部变量,函数内部定义的变量(存放栈区)
//	int a = 10;
//	int b = 10;
//
//	cout << "局部变量a地址为： \t" << (int)&a << endl;
//	cout << "局部变量b地址为： \t" << (int)&b << endl;
//
//	//局部常量(存放栈区)
//	const int c_l_a = 10;
//	const int c_l_b = 10;
//	
//	cout << "局部常量c_l_a地址为： \t" << (int)&c_l_a << endl;
//	cout << "局部常量c_l_b地址为： \t" << (int)&c_l_b << endl;
//
//	//全局变量(存放全局区)
//	cout << "全局变量g_a地址为： \t" << (int)&g_a << endl;
//	cout << "全局变量g_b地址为： \t" << (int)&g_b << endl;
//
//	//静态变量(存放全局区)
//	static int s_a = 10;
//	static int s_b = 10;
//	
//	cout << "静态变量s_a地址为： \t" << (int)&s_a << endl;
//	cout << "静态变量s_b地址为： \t" << (int)&s_b << endl;
//
//	//字符串常量(存放全局区)
//	cout << "字符串常量地址为： \t" << (int)&"hello world" << endl;
//	cout << "字符串常量地址为： \t" << (int)&"你好世界" << endl;
//
//	//全局常量(存放全局区)
//	cout << "全局常量c_g_a地址为： \t" << (int)&c_g_a << endl;
//	cout << "全局常量c_g_b地址为： \t" << (int)&c_g_b << endl;
//
//}