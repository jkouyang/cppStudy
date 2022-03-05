/*deque容器 + deque构造函数
	双端数组，可以对头端进行插入删除操作，deque容器的迭代器也是支持随机访问的
	
deque与vector区别：
	1.vector对于头部的插入删除效率低，数据量越大，效率越低
	2.deque相对而言，对头部的插入删除速度回比vector快
	3.vector访问元素时的速度会比deque快,这和两者内部实现有关

deque内部工作原理:
	1.deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据
	2.中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

deque容器构造函数：
	1.deque<数据类型> deq;//默认构造形式
	2.deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身
	3.deque(n, elem);//构造函数将n个elem拷贝给本身
	4.deque(const deque &deq);//拷贝构造函数
*/

#include<iostream>
#include<deque>
using namespace std;

void myPrintDeque_1(const deque<int> &deq) {//加const让引用传进来的容器只读，对应的迭代器也要改为const_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testDeque_1() {
	//1.默认构造  无参构造
	deque<int> deq1;
	for (int i = 0; i < 10; i++) {
		deq1.push_back(i);
	}
	myPrintDeque_1(deq1);

	//2.构造函数将[beg, end)区间中的元素拷贝给本身
	deque<int> deq2(deq1.begin(), deq1.end());
	myPrintDeque_1(deq2);

	//3.deque(n, elem);//构造函数将n个elem拷贝给本身
	deque<int> deq3(10, 3);
	myPrintDeque_1(deq3);

	//4.deque(const deque &deq);//拷贝构造函数
	deque<int> deq4(deq3);
	myPrintDeque_1(deq4);
}

//void main() {
//	testDeque_1();
//}