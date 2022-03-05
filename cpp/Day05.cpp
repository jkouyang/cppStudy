/*Day05
指针：
	定义 数据类型 *p；
	声明  p=地址，p为地址，*p为地址对应的值
	定义并声明 数据内心 *p=地址；

	空指针：指针变量指向内存中编号为0的空间，用于初始化指针变量，空指针指向的内存是不可以访问的
			int *p = NULL;

	野指针：指针变量指向非法的内存空间，程序中避免用野指针

	常量指针：const int *p = &a; //指针的指向可以改，但不能通过该指针来修改指向内存的值

	指针常量：int * const p = &a; //指针的指向不能改，但指针指向的内存的值可以改

	const int * const p = &a; //指针的指向和指针指向内存的值都不改

注意：指针的p++,不是地址的地址(p值)单纯的+1，是加一个指针指向数据类型的长度，即下移一位元素

指针与数组：可以用指针表示数组中的元素

指针与函数：地址传递
			void xxx(int *p1, int *p2){}
			xxx(&a,&b)
*/

#include <iostream>
#include <string>
using namespace std;

void Day05()
{
	int num = 10;//数
	double arr1[5] = { 1,2,3,4,5 };//一维
	int arr2[5][4] = { { 1,2,3,4 }, {6,7,8,9} };//二维
	
	int *p= &num;
	double *p1 = arr1;
	int *p2 = arr2[0];
	cout << arr2 << endl;
	cout << &arr2[0] << endl;

	cout << "p:" << p << endl ;
	cout << "*p:" << *p << endl;
	cout << "&num:" << &num << endl;
	cout << "num:" << num << endl << endl;
	

	cout << "p1:" << p1 << endl;
	cout << "++p1:" << ++p1 << endl;
	cout << "*p1:" << *p1 << endl;
	cout << "arr1:" << arr1 << endl;
	cout << "arr1[0]:" << arr1[0] << endl << endl;

	cout << "p2:" << p2 << endl;
	cout << "*p2:" << *p2 << endl;
	cout << "arr2:" << arr2 << endl;
	cout << "arr2[0]:" << arr2[0] << endl;
	cout << "arr2[0][0]:" << arr2[0][0]<< endl << endl;


	//32位下(x86)指针都是占4B，64位(x64)指针都是占8B
	cout << "int*所占空间:" << sizeof(int*) << endl;
	cout << "double*所占空间:" << sizeof(double*) << endl;
	cout << "char*所占空间:" << sizeof(char*) << endl;
	cout << "string*所占空间:" << sizeof(string*) << endl;
	

}


//void main(){
//	Day05();
//}