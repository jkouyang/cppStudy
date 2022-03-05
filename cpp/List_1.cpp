/*List容器——将数据进行链式存储
	链表(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
	链表的组成：链表由一系列**结点**组成
	结点的组成：一个是存储数据元素的**数据域**，另一个是存储下一个结点地址的**指针域**
	STL中的链表是一个双向循环链表
	由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于**双向迭代器**

list的优点：
	1.采用动态存储分配，不会造成内存浪费和溢出
	2.链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

list的缺点：
	1.链表灵活，但是空间(指针域) 和 时间（遍历）额外耗费较大
	2.List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。

总结：STL中**List和vector是两个最常被使用的容器**，各有优缺点

构造函数：
	1.list<T> lst;//默认构造
	2.list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身
	3.list(n,elem);//构造函数将n个elem拷贝给本身
	4.list(const list &lst);//拷贝构造
*/

#include<iostream>
#include<list>
using namespace std;

void myPrintList_1(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//常量容器需要常量的迭代器
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testList_1() {
	//1.list<T> lst;//默认构造
	list<int> L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	myPrintList_1(L1);

	//2.list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身
	list<int> L2(L1.begin(),L1.end());
	myPrintList_1(L2);

	//3.list(n,elem);//构造函数将n个elem拷贝给本身
	list<int> L3(10, 3);
	myPrintList_1(L3);

	//4.list(const list &lst);//拷贝构造
	list<int> L4(L3);
	myPrintList_1(L4);

	//int a = L4[3];//报错，不支持随机访问(没有重写[]函数)，也没有at()函数
	list<int>::iterator pBegin = ++L1.begin();
	cout << *pBegin << endl;
	//报错，不支持随机访问(list迭代器没有重写"+"号函数)，只能有pBegin++(list迭代器重写"++"函数)这种依次逐个访问
	//cout << *(pBegin+1) << endl;
}

//void main() {
//	testList_1();
//}