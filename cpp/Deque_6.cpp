/*deque排序——利用算法实现对deque容器进行排序

	sort(iterator beg, iterator end)//对beg和end区间内元素进行排序

*/

#include<iostream>
#include<deque>
#include<string>
#include<algorithm>//引入算法头文件
using namespace std;

void myPrintDeque_6(const deque<string>& deq) {//加const让引用传进来的容器只读，对应的迭代器也要改为const_iterator
	for (deque<string>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}


void tetsDeque_6() {
	deque<string> deq;
	deq.push_back(to_string(3));
	deq.push_back(to_string(9));
	deq.push_back(to_string(812));
	deq.push_back(to_string(5));
	deq.push_front(to_string(123));
	deq.push_front(to_string(785));
	deq.push_front(to_string(6));
	deq.push_front(to_string(7));
	myPrintDeque_6(deq);

	//对于支持随机访问的容器都可以使用sort()进行排序；
	//数子和字符串都可以利用sort()排序，字符串按ASSCI码排序
	sort(deq.begin(), deq.end());//自定义排序规则时，只用传函数名，不用加()带参数
	myPrintDeque_6(deq);
}
//void main() {
//	tetsDeque_6();
//}
