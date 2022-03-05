/*deque插入和删除
两端插入删除操作：
	1.push_back(elem);//在容器尾部添加一个数据
	2.push_front(elem);//在容器头部插入一个数据
	3.pop_back();//删除容器最后一个数据
	4.pop_front();//删除容器第一个数据

指定位置插入删除操作：
	1.insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置
	2.insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值
	3.insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
	4.erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置
	5.erase(pos); //删除pos位置的数据，返回下一个数据的位置
	6.clear();//清空容器的所有数据
*/


#include<iostream>
#include<deque>
#include<string>
using namespace std;

void myPrintDeque_4(const deque<string>& deq) {//加const让引用传进来的容器只读，对应的迭代器也要改为const_iterator
	for (deque<string>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

//两端插入删除操作
void testDeque_4a() {
	deque<string> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(to_string(i));
	}
	myPrintDeque_4(deq);
	//1.push_back(elem);//在容器尾部添加一个数据
	deq.push_back("尾插");
	myPrintDeque_4(deq);
	//2.push_front(elem);//在容器头部插入一个数据
	deq.push_front("头插");
	myPrintDeque_4(deq);
	//3.pop_back();//删除容器最后一个数据
	deq.pop_back();
	myPrintDeque_4(deq);
	//4.pop_front();//删除容器第一个数据
	deq.pop_front();
	myPrintDeque_4(deq);
}

//指定位置插入删除操作
void testDeque_4b() {
	deque<string> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(to_string(i));
	}
	myPrintDeque_4(deq);

	//1.insert(pos, elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置
	deq.insert(deq.begin()+3, "中间插");//pos为迭代器
	myPrintDeque_4(deq);
	//2.insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值
	deq.insert(deq.begin() + 5, 3,"中间插n个");//pos为迭代器
	myPrintDeque_4(deq);
	//3.insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值
	deq.insert(deq.begin(), deq.begin()+5, deq.begin() + 7);//pos, beg, end都为迭代器
	myPrintDeque_4(deq);
	//4.erase(beg, end);//删除[beg,end)区间的数据，返回下一个数据的位置
	deq.erase(deq.begin(), deq.begin() + 5);//beg, end都为迭代器
	myPrintDeque_4(deq);
	//5.erase(pos); //删除pos位置的数据，返回下一个数据的位置
	deq.erase(deq.begin());//pos都为迭代器
	myPrintDeque_4(deq);
	//6.clear();//清空容器的所有数据
	deq.clear();
	myPrintDeque_4(deq);
}

//void main() {
//	testDeque_4a();
//	cout << "====================================" << endl;
//	testDeque_4b();
//}