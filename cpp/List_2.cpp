/*List 赋值和交换

函数原型：
	1.assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身
	2.assign(n, elem);//将n个elem拷贝赋值给本身
	3.list& operator=(const list &lst);//重载等号操作符
	4.swap(lst);//将lst与本身的元素互换
*/


#include<iostream>
#include<list>
using namespace std;

void myPrintList_2(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//常量容器需要常量的迭代器
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testList_2a(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	myPrintList_2(L1);

	//3.list& operator=(const list & lst);//重载等号操作符
	list<int> L2;
	L2 = L1;
	myPrintList_2(L2);
	//1.assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身
	list<int> L3;
	L3.assign(L2.begin(), L2.end());
	myPrintList_2(L3);
	//2.assign(n, elem);//将n个elem拷贝赋值给本身
	list<int> L4;
	L4.assign(10, 100);
	myPrintList_2(L4);
}

void testList_2b(){

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);

	cout << "交换前： " << endl;
	myPrintList_2(L1);
	myPrintList_2(L2);

	L1.swap(L2);
	cout << "交换后： " << endl;
	myPrintList_2(L1);
	myPrintList_2(L2);

}

//void main() {
//	testList_2a();
//	cout<<"=====================================" << endl;
//	testList_2b();
//}