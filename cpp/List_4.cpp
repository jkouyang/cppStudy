/*List 插入和删除

函数原型：
	1.push_back(elem);//在容器尾部加入一个元素
	2.pop_back();//删除容器中最后一个元素
	3.push_front(elem);//在容器开头插入一个元素
	4.pop_front();//从容器开头移除第一个元素
	5.insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置
	6.insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值
	7.insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
	8.erase(pos);//删除pos位置的数据，返回下一个数据的位置
	9.erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置
	10.remove(elem);//删除容器中所有与elem值匹配的元素
	11.clear();//移除容器的所有数据
*/

#include<iostream>
#include<list>
using namespace std;

void myPrintList_4(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//常量容器需要常量的迭代器
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testList_4() {
	list<int> L;
	//1.push_back(elem);尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//3.push_front(elem);头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	myPrintList_4(L);

	//2.pop_back();尾删
	L.pop_back();
	myPrintList_4(L);
	//4.pop_front();头删
	L.pop_front();
	myPrintList_4(L);

	//5.insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置
	list<int>::iterator pBegin = L.begin();
	list<int>::iterator p1 = L.insert(++++pBegin, 99);//插入一个数据并返回新数据的位置
	myPrintList_4(L);

	//8.erase(pos);//删除pos位置的数据，返回下一个数据的位置
	list<int>::iterator p2 =L.erase(p1);
	myPrintList_4(L);

	//6.insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值
	L.insert(p2, 5, 77);
	myPrintList_4(L);
	//7.insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值
	L.insert(p2, L.begin(), ++++L.begin());
	myPrintList_4(L);

	//9.erase(beg, end);//删除[beg,end)区间的数据，返回下一个数据的位置
	L.erase(L.begin(), ++++L.begin());
	myPrintList_4(L);

	//10.remove(elem);//删除容器中所有与elem值匹配的元素
	L.remove(77);
	myPrintList_4(L);

	//11.clear();//移除容器的所有数据
	L.clear();
	myPrintList_4(L);
}

//void main() {
//	testList_4();
//}