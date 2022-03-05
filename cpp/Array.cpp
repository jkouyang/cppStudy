/*array 数组容器
* 
一.为什么要引入 array 而不是直接使用 vector？
	1.与vector不同，array的大小是固定的
	2.vector是自动扩容的，存入大量的数据后，vector的容量变大，
	  这时对容器进行了删除操作，容器并不会自动归还被删除元素相应的内存，
	  需要手动运行 shrink_to_fit() 释放这部分内存。

二.已经有了传统数组，为什么要用 std::array?
	array 能够让代码变得更加“现代化”，封装了一些操作函数
	包装了size()，empty()，data()(返回指针，即&arr[0])等成员函数，同时还能使用标准库中的容器算法，比如sort()

语法：	#include<array>
		array<T,n> arr;//T为数据类型，n为array的size.
注意：array<int,n>要手动初始化，不像vector<int>会自动全0
*/

#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <algorithm>
using namespace std;

void funcArray(int* p, int len) {//要求传入一个数组指针和数组长度
}

void testArray() {
	array<int, 10> arr{5,2,8,1,3,9,6,4,0,7};
	//int* p = arr;//错误，array与数组不同，不会自动退化成 T*
	int aa[10];
	int* p = aa;
	cout << "arr.empty():" << arr.empty() << endl;
	cout << "arr.size():" << arr.size() << endl;

	cout << "sort()排序：";
	sort(arr.begin(), arr.end(), [](int a, int b)->bool{return a > b;});//使用lambda表达式排序
	for (auto&& i : arr) { cout << i << " "; }

	//array与数组的接口，要求传入一个数组指针和数组长度
	//funcArray(arr, arr.size());// 非法, 无法隐式转换
	funcArray(&arr[0], arr.size());
	funcArray(arr.data(), arr.size());
}

//void main() {
//	testArray();
//}