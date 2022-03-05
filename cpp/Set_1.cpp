/*Set容器——所有元素都会在插入时自动被排序
本质——set/multiset属于**关联式容器**，底层结构是用**二叉树**实现

set和multiset区别：
	set不允许容器中有重复的元素
	multiset允许容器中有重复的元素

构造函数：
	1.set<T> st;//默认构造函数：
	2.set(const set &st);//拷贝构造函数

赋值：
	set& operator=(const set &st);//重载等号操作符

*/

#include<iostream>
#include<set>
using namespace std;

void myPrintSet_1(const set<int>& s) {
	for (set<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void myPrintMultiset_1(const multiset<int>& s) {
	for (multiset<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testSet_1() {
	//1.set<T> st;//默认构造函数：
	set<int> s1;

	//插入数据 只有insert()方式
	s1.insert(4);
	s1.insert(2);
	s1.insert(3);
	s1.insert(5);
	s1.insert(1);
	myPrintSet_1(s1);//所有元素都会在插入时自动被排序
	cout << "set容器的长度：" << s1.size() << endl;

	s1.insert(1);
	s1.insert(1);
	s1.insert(1);
	myPrintSet_1(s1);//set不允许容器中有重复的元素，但插入的时候不会报错，无效插入
	cout << "set容器的长度：" << s1.size() << endl;

	//2.set(const set & st);//拷贝构造函数
	set<int> s2(s1);

	multiset<int> s3;
	s3.insert(3);
	s3.insert(2);
	s3.insert(1);
	s3.insert(1);
	s3.insert(2);
	myPrintMultiset_1(s3);//multiset允许容器中有重复的元素
	cout << "multiset容器的长度：" << s1.size() << endl;

}

//void main() {
//	testSet_1();
//}