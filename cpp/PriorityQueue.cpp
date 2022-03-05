/*priority_queue	优先队列
堆实现：
	less<>对应大顶堆
	greater<>对应小顶堆

与和队列基本操作相同:
	top() 访问队头元素
	empty() 队列是否为空
	size() 返回队列内元素个数
	push() 插入元素到队尾 (并排序)
	emplace() 原地构造一个元素并插入队列
	pop() 弹出队头元素
	swap() 交换内容

定义：
	priority_queue<Type, Container, Functional>
		Type 就是数据类型，Container 就是容器类型，Functional就是比较的方式(默认大顶堆，降序排列)

*/

#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;
typedef pair<int, int> pii;

void testPriorityQueue() {
	//默认大顶堆，降序排列
	priority_queue<int> pq;
	pq.push(10);
	pq.push(7);
	pq.push(11);
	cout << pq.top() << " "; pq.pop();
	cout << pq.top() << " ";pq.pop();
	cout << pq.top() << endl;pq.pop();
	cout << endl;

	//greater<>小顶堆
	priority_queue<pii, vector<pii>, greater<pii>> store;
	store.push(make_pair(10, 1));
	store.push(make_pair(7, 1));
	store.push(make_pair(11, 1));
	cout << store.top().first << " " << store.top().second << endl; store.pop();
	cout << store.top().first << " " << store.top().second << endl; store.pop();
	cout << store.top().first << " " << store.top().second << endl; store.pop();
	cout << endl;

	//自定义排序
	function<bool(pii, pii)> mycomp = [](pii a, pii b) {return a.first > b.first; };
	priority_queue<pii, vector<pii>, function<bool(pii, pii)>> fque(mycomp);//自定义排序
	/*	或者利用auto, decltype来类型推导
	auto mycomp = [](pii a, pii b) {return a.first > b.first; };
	priority_queue<pii, vector<pii>, decltype(mycomp)> fque(mycomp);//自定义排序
	*/
	fque.push(make_pair(10, 1));
	fque.push(make_pair(7, 1));
	fque.push(make_pair(11, 1));
	cout << fque.top().first << " " << fque.top().second << endl; fque.pop();
	cout << fque.top().first << " " << fque.top().second << endl; fque.pop();
	cout << fque.top().first << " " << fque.top().second << endl; fque.pop();
	
	//自定义数据类型，重载"<"，">"，或者自定义排序规则
}

//int main() {
//	testPriorityQueue();
//	return 0;
//}