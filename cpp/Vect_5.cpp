/*vector数据存取
	1.at(int idx);//返回索引idx所指的数据的引用
	2.operator[];//返回索引idx所指的数据的引用
	3.front();//返回容器中第一个数据元素的引用
	4.back();//返回容器中最后一个数据元素的引用
注意：这些函数的返回类型都是引用，函数返回类型是值时会产生一个临时变量作为函数返回值的副本，而返回引用时不会产生值的副本
	返回值时对应的原始数据不可修改(修改的只是临时变量)，返回引用时原始数据可以修改
*/

#include<iostream>
#include<vector>
using namespace std;

void testVect_5() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}

	//1.at(int idx);//返回索引idx所指的数据的引用
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//2.operator[];//返回索引idx所指的数据的引用
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	//3.front();//返回容器中第一个数据元素的引用
	auto &a1 = v1.front();
	cout << "返回第一个元素：" << a1 << endl;
	a1 = 11;//修改引用的值，就是修改原数据的值
	cout << "返回第一个元素：" << v1.front() << endl;

	//4.back();//返回容器中最后一个数据元素的引用
	cout << "返回第最后元素：" << v1.back() << endl;
}

//void main() {
//	testVect_5();
//}
