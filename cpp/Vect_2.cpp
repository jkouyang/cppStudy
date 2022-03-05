/*vector赋值操作
	1.vector& operator=(const vector &vec);	//重载等号操作符
	2.assign(beg, end);						//将[beg, end)区间中的数据拷贝赋值给本身。
	3.assign(n, elem);						//将n个elem拷贝赋值给本身。

*/


#include<iostream>
#include<vector>
using namespace std;

void myPrintVect_2(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testVect_2() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	myPrintVect_2(v);

	//赋值操作
	//1.重载 = 操作符
	vector<int> v1;
	v1=v;
	myPrintVect_2(v1);

	//2.assign(v.begin(), v.end())
	vector<int> v2;
	v2.assign(v.begin(), v.end());
	myPrintVect_2(v2);

	//2.assign(n, elem)
	vector<int> v3;
	v3.assign(10, 5);
	myPrintVect_2(v3);

}

//void main() {
//	testVect_2();
//}