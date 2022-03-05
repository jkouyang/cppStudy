/*Set容器的大小和交换

函数原型：
	1.size();//返回容器中元素的数目
	2.empty();//判断容器是否为空
	3.swap(st);//交换两个集合容器
*/

#include<iostream>
#include<set>
using namespace std;

void myPrintSet_2(const set<int>& s) {
	for (set<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testSet_2a() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	if (s1.empty()){
		cout << "s1为空" << endl; //2.empty();//判断容器是否为空
	}
	else{
		cout << "s1不为空" << endl;
		cout << "s1的大小为： " << s1.size() << endl;//1.size();//返回容器中元素的数目
	}
}

void testSet_2b() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交换前" << endl;
	myPrintSet_2(s1);
	myPrintSet_2(s2);
	cout << endl;

	cout << "交换后" << endl;
	s1.swap(s2);
	myPrintSet_2(s1);
	myPrintSet_2(s2);
}

//void main() {
//	testSet_2a();
//	cout << "================================" << endl;
//	testSet_2b();
//}