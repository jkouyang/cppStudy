/*List 数据存取
函数原型：
	1.front();//返回第一个元素的引用
	2.back();//返回最后一个元素的引用

注意：list容器中不可以通过[]或者at方式访问数据
*/

#include<iostream>
#include<list>
using namespace std;

void myPrintList_5(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//常量容器需要常量的迭代器
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testList_5() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//cout << L1.at(0) << endl;//错误 不支持at访问数据
	//cout << L1[0] << endl; //错误  不支持[]方式访问数据
	
	//1.front();//返回第一个元素的引用
	int& a = L1.front();
	cout << "第一个元素为： " << a << endl;
	a = 17;
	cout << "第一个元素为： " << L1.front() << endl;//因为返回的是引用(指针)，所以可以被修改

	//2.back();//返回最后一个元素的引用
	cout << "最后一个元素为： " << L1.back() << endl;

	//list容器的迭代器是双向迭代器，不支持随机访问
	list<int>::iterator pBegin = L1.begin();
	//pBegin = pBegin + 1;//错误，不可以跳跃访问，即使是+1
	//pBegin++;//正确，++符号函数重载了
}

//void main() {
//	testList_5();
//}