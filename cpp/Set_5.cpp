/*set和multiset区别
区别：
	1.set不可以插入重复数据，而multiset可以
	2.set插入数据的同时会返回两个东西，插入位置的迭代器和插入是否成功(bool型)，成对返回pair
	3.multiset不会检测数据，因此可以插入重复数据，插入时只返回迭代器(指向插入数据的位置)
*/


#include<iostream>
#include<set>
using namespace std;

void myPrintSet_5(const set<int>& s) {
	for (set<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void myPrintMultiset_5(const multiset<int>& s) {
	for (multiset<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testSet_5a() {
	set<int> s;
	pair<set<int>::iterator, bool> ret1 = s.insert(10);//第一次插入10
	pair<set<int>::iterator, bool> ret2 = s.insert(10);//第二次插入10
	if (ret1.second) {
		cout << "第一次插入10插入成功" << endl;
		cout << "*ret1.first=" << *ret1.first << endl;//虽然ret1.first是记录数据插入的位置迭代器
	}
	else {
		cout << "第一次插入10插入失败" << endl;
	}
	if (ret2.second) {
		cout << "第二次插入10插入成功" << endl;
	}
	else {
		cout << "第二次插入10插入失败" << endl;
		cout << "*ret2.first=" << *ret2.first << endl;//虽然*ret2.first仍然记录了的数据，但实质并没有插入
	}
}

void testSet_5b() {
	multiset<int> ms;
	//multiset可以插入重复值
	multiset<int>::iterator ret1 = ms.insert(10);//第一次插入10
	multiset<int>::iterator ret2 = ms.insert(10);//第二次插入10
	myPrintMultiset_5(ms);

	cout << "*ret1=" << *ret1 << endl;
	cout << "*ret2=" << *ret2 << endl;

	if (ret1 == ret2) {
		cout << "ret1等于ret2" << endl;
	}
	else {
		cout << "ret1不等于ret2" << endl;
	}

}

//void main() {
//	testSet_5a();
//	cout << "================================" << endl;
//	testSet_5b();
//}