/*queue队列
	一种**先进先出**(First In First Out,FIFO)的数据结构，它有两个出口

构造函数：
	queue<T> que;//queue采用模板类实现，queue对象的默认构造形式
	queue(const queue &que);//拷贝构造函数

赋值操作：
	queue& operator=(const queue &que);//重载等号操作符

数据存取：
	void push(elem);//往队尾添加元素
	void pop();//从队头移除第一个元素
	T back();//访问队尾元素
	T front();//访问队头元素

大小操作：
	bool empty();//判断堆栈是否为空
	int size();//返回栈的大小

注意：1.队列不支持随机访问，只能访问队头和队尾元素
	  2.容器适配器——队列queue没有成员begin和end（因为栈和队列不支持迭代器，不能对任意元素进行访问）；

这些插入操作会涉及到两次构造，首先是对象的初始化构造，接着在插入的时候会复制一次，会触发拷贝构造。
但是很多时候我们并不需要两次构造带来效率的浪费，如果可以在插入的时候直接构造，就只需要构造一次就够了。
C++11标准已经有这样的语法可以直接使用了，那就是emplace()
*/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

void testQueue() {
	queue<string> que;
	//入队
	que.push("唐僧");
	que.push("孙悟空");
	que.push("猪八戒");
	que.push("沙僧");
	que.push("白龙马");
	que.emplace("白骨精");
	

	while (!que.empty()) {
		cout << "队列的长度：" << que.size();
		cout << "\t队头的元素：" << que.front();//访问队头元素
		cout << "\t队尾的元素：" << que.back();//访问队尾元素
		que.pop();//出队
		cout << "\t出队后队列的长度：" << que.size() << endl;//队列的长度
	}

	queue<string> que1(que);//拷贝构造
	que1 = que;//赋值，"="号重载
}


//void main() {
//	testQueue();
//}