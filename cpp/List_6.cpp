/*List 反转和排序
	1.reverse();//反转链表
	2.sort();//链表排序，默认的排序规则从小到大
注意：sort()会根据数据量的大小采取不同的排序算法
*/

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void myPrintList_6(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//常量容器需要常量的迭代器
		cout << *pBegin << " ";
	}
	cout << endl;
}

bool myCompareList_6(int a,int b) {//指定规则，从大到小
	//降序：就让第一个数大于第二个数
	return a>b;
}

void testList_6() {
	list<int> L;
	L.push_back(4);
	L.push_back(3);
	L.push_back(1);
	L.push_back(5); 
	L.push_back(2);
	myPrintList_6(L);

	//1.reverse();//反转链表
	L.reverse();
	myPrintList_6(L);

	//sort(L.begin(), L.end());//所有不支持随街访问迭代器的容器，都不能sort()标准算法
								//不支持随街访问迭代器的容器，内部会提供一些对应的算法(成员函数)
	//2.sort();//链表排序
	L.sort();//默认的排序规则，从小到大
	myPrintList_6(L);

	L.sort(myCompareList_6);//指定规则，从大到小
	myPrintList_6(L);
}

//void main() {
//	testList_6();
//}