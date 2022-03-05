/*heap
	堆并不是STL的组件，但是经常充当着底层实现结构。比如优先级队列（Priority Queue）等等
	堆是一种完全二叉树，因此我们可以用数组(或容器)来存储所有节点

* 函数形式
	1.void make_heap(beg,end)//默认构造大顶堆，_Pred=less<T>
	  void make_heap(beg,end,_Pred)//可自定义_Pred

	2.void push_heap(beg,end)//新元素的加入不满足堆的性质，调整使得其重新满足堆的特点
	  void push_heap(beg,end,_Pred)

	3.void pop_heap(beg,end)//从堆顶弹出一个元素(逻辑上)
	  void pop_heap(beg,end,_Pred)

	4.void sort_heap(beg,end)//堆排序
	  void pop_heap(beg,end,_Pred)
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testHeap() {
	//构建一个容器
	cout << "构建一个容器" << endl;
	vector<int> vect{ 5,7,1,3,6,4,8,2,9 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//将容器构建为堆
	//1.make_heap()
	cout << "将容器构建为堆" << endl;
	make_heap(vect.begin(), vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//向堆(容器)插入一个数据，排在最后面
	cout << "向堆(容器)插入一个数据，排在最后面" << endl;
	vect.push_back(0);
	for (int i : vect) { cout << i << " "; }
	cout << endl;
	
	//新元素的加入不满足堆的性质，调整使得其重新满足堆的特点
	//2.push_heap()
	cout << "调整使得其重新满足堆的特点" << endl;
	push_heap(vect.begin(), vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//3.pop_heap() 从堆顶弹出一个元素
	//只是在堆的逻辑上弹出一个堆顶元素，在容器的物理层上并没有删除，放在了最后面
	//结合resize()可以实现真正的删除
	cout << "从堆顶弹出一个元素(逻辑上)" << endl;
	pop_heap(vect.begin(), vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
	cout << "从堆顶弹出一个元素(物理上)" << endl;
	vect.resize(vect.size() - 1);
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//4.sort_heap()，堆排序
	//执行后，容器中的元素实现排序，对应的堆的要求也满足
	cout << "堆排序" << endl;
	sort_heap(vect.begin(), vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testHeap();
//}