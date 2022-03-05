/*deque容器的存取(读写)
函数原型：
	1.at(int idx);//返回索引idx所指的数据
	2.operator[];//返回索引idx所指的数据
	3.front();//返回容器中第一个数据元素
	4.back();//返回容器中最后一个数据元素
*/

#include<iostream>
#include<deque>
using namespace std;

void myPrintDeque_5(const deque<int>& deq) {//加const让引用传进来的容器只读，对应的迭代器也要改为const_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void tetsDeque_5() {
	deque<int> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(i);
	}
	myPrintDeque_5(deq);

	//1.at(int idx);//返回索引idx所指的数据
	cout << "deq.at(5)=" << deq.at(5) << endl;

	//2.operator[];//返回索引idx所指的数据
	cout << "deq[5]=" << deq[5] << endl;

	//3.front();//返回容器中第一个数据元素
	cout << "deq.front()=" << deq.front() << endl;

	//4.back();//返回容器中最后一个数据元素
	cout << "deq.back()=" << deq.back() << endl;

}

//void main() {
//	tetsDeque_5();
//}