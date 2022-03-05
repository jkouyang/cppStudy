/*stack栈
	一种*先进后出**(First In Last Out,FILO)的数据结构，它只有一个出口

构造函数：
	stack<T> stk;//stack采用模板类实现， stack对象的默认构造形式
	stack(const stack &stk);//拷贝构造函数

赋值操作：
	stack& operator=(const stack &stk);//重载等号操作符

数据存取：
	void push(elem);//向栈顶添加元素
	void pop();//从栈顶移除第一个元素
	T top();//返回栈顶元素

大小操作：
	bool empty();//判断堆栈是否为空
	int size();//返回栈的大小

注意：1.队列不支持随机访问，只能访问队头和队尾元素
	  2.容器适配器——stack没有成员begin和end（因为栈和队列不支持迭代器，不能对任意元素进行访问）；
*/


#include<iostream>
#include<stack>

using namespace std;


void testStack() {
	stack<int> sta;//默认构造创建栈
	//入栈
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);
	sta.push(5);
	while (!sta.empty()) {//判断栈是否为空
		cout << "栈的长度：" << sta.size();//栈的长度size()
		cout << "\t栈顶元素为:" << sta.top();//访问栈顶元素
		sta.pop();//弹出栈顶元素
		cout << "\t访问并弹出后栈的长度：" << sta.size() << endl;
	}

	stack<int> sta1(sta);//拷贝构造
	sta1 = sta;//赋值，"="号重载

}

//void main() {
//	testStack();
//}