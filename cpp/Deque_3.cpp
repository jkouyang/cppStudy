/*deque大小操作
	注意：deque没有容量(capacity)的概念，只有大小(size)
			deque容器由于本身特性，扩容时只需要添加一个地址，不需要开辟新的空间，所以没有容量的概念
函数模型：
	1.deque.empty();//判断容器是否为空
	2.deque.size();//返回容器中元素的个数
	3.deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置
						//如果容器变短，则末尾超出容器长度的元素被删除。
	4.deque.resize(num, elem);//重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
							  //如果容器变短，则末尾超出容器长度的元素被删除。
*/


#include<iostream>
#include<deque>
using namespace std;

void myPrintDeque_3(const deque<int>& deq) {//加const让引用传进来的容器只读，对应的迭代器也要改为const_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testDeque_3() {
	deque<int> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(i);
	}
	myPrintDeque_3(deq);
	if (deq.empty()) {//1.deque.empty();//判断容器是否为空
		cout << "deq为空" << endl;
	}
	else {
		cout << "deq不为空" << endl;
		cout << "deq的大小：" << deq.size() << endl;//2.deque.size();//返回容器中元素的个数
	}

	//重新指定长度
	deq.resize(15);//3.deque.resize(num);
	deq.resize(20, 1);//4.deque.resize(num, elem);
}

//void main() {
//	testDeque_3();
//}