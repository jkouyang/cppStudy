/*Map大小和交换
函数原型：
	1.size();//返回容器中元素的数目
	2.empty();//判断容器是否为空
	3.swap(st);//交换两个集合容器

*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

void myPrintMap_2(map<int, int>& m) {
	for (map<int, int>::iterator pBegin = m.begin(); pBegin != m.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
}

void testMap_2a() {
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty()){//2.empty();//判断容器是否为空
		cout << "m为空" << endl;
	}
	else{
		cout << "m不为空" << endl;//1.size();//返回容器中元素的数目
		cout << "m的大小为： " << m.size() << endl;
	}
}

void testMap_2b() {
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));

	cout << "交换前" << endl;
	myPrintMap_2(m1);
	myPrintMap_2(m2);

	cout << "交换后" << endl;
	m1.swap(m2);//3.swap(st);//交换两个集合容器
	myPrintMap_2(m1);
	myPrintMap_2(m2);
}

//void main() {
//	testMap_2a();
//	cout << "=========================" << endl;
//	testMap_2b();
//}