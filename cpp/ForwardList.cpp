/*forward_list	单向链表

	forward_list 使用单向链表进行实现，提供了 O(1) 复杂度的元素插入，
	不支持快速随机访问(这也是链表的特点)，
	标准库容器中唯一一个不提供size()方法的容器
	当不需要双向迭代时，具有比 list 更高的空间利用率
*/

#include<iostream>
#include<string>
#include<vector>
#include<forward_list>
using namespace std;

void testForwardList() {
	forward_list<int> flist{ 1,2,3,4,5,6 };
	forward_list<int> flist1{ 7,8,9,10 };

	flist.push_front(10);
	flist.pop_front();
	//flist.insert_after(++flist.begin(), 99);
	cout << flist.front() << endl;
	for (auto i : flist) {
		cout << i << " ";
	}
	cout << endl;
	flist.splice_after(flist.begin(),flist1);
	for (auto i : flist) {
		cout << i << " ";
	}
}

//void main() {
//	testForwardList();
//}