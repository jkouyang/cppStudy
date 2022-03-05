/*deque赋值操作
	1.deque& operator=(const deque &deq);//重载等号操作符
	2.assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
	3.assign(n, elem);//将n个elem拷贝赋值给本身。
*/


#include<iostream>
#include<deque>
using namespace std;

void myPrintDeque_2(const deque<int>& deq) {//加const让引用传进来的容器只读，对应的迭代器也要改为const_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}


void testDeque_2() {
	deque<int> deq1;
	for (int i = 0; i < 10; i++) {
		deq1.push_back(i);
	}
	myPrintDeque_2(deq1);

	//赋值操作
	//1.deque & operator=(const deque & deq);//重载等号操作符
	deque<int> deq2;
	deq2 = deq1;
	myPrintDeque_2(deq2);

	//2.assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身
	deque<int> deq3;
	deq3.assign(deq1.begin(), deq1.end());
	myPrintDeque_2(deq3);


	//3.assign(n, elem);//将n个elem拷贝赋值给本身。
	deque<int> deq4;
	deq4.assign(10, 3);
	myPrintDeque_2(deq4);
}

//void main() {
//	testDeque_2();
//}