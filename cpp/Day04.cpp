/*Day04
数组：
	放在一块连续的内存空间中
	数组中每个元素都是相同的数据类型
	初始话时要定义数组长度，未赋值的数组元素为0
	通过sizeof(数组名)可以统计数组占的内存，通过数组名查看数组的首地址
	数组名是数组的首地址

函数：
	返回类型  函数名称（参数列表）{
		执行语句；
		return 表达式；
	}
	函数声明：viod xxx();  函数声明后，可以把函数定义写在main函数后面，函数声明可以写多次，函数定义只能写一次
	函数的分文件编写：创建同名的xxx.h和xxx.cpp，在xxx.h中写函数声明，在xxx.cpp中写函数定义
*/

#include <iostream>
#include <string>
using namespace std;

void Day04()
{
	int arr1[5] = { 1,2,3,4,5 };
	cout << "一维数组空间" << sizeof(arr1) << endl;
	cout << "一维数组首地址" << arr1 << endl;
	cout << "一维数组首个元素地址" << &arr1[0] << endl;
	cout << "一维数组第2个元素地址" << &arr1[1] << endl;

	int arr2[5][4];//二维数组按行先存
	cout << "二维数组行数" << sizeof(arr2)/sizeof(arr2[0]) << endl;
	cout << "二维数组列数" << sizeof(arr2[0])/sizeof(arr2[0][0]) << endl;

	cout << "二维数组空间" << sizeof(arr2) << endl;
	cout << "二维数组首地址" << arr2 << endl;
	cout << "二维数组第一行首地址" << &arr2[0] << endl;
	cout << "二维数组第二行首地址" << &arr2[1] << endl;

}


//void main(){
//	Day04();
//}