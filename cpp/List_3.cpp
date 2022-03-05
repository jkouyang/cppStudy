/*List大小操作
函数原型：
	1.size();//返回容器中元素的个数
	2.empty();//判断容器是否为空
	3.resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
				 //如果容器变短，则末尾超出容器长度的元素被删除。
	4.resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
					   //如果容器变短，则末尾超出容器长度的元素被删除。
*/

#include<iostream>
#include<list>
using namespace std;

void myPrintList_3(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//常量容器需要常量的迭代器
		cout << *pBegin << " ";
	}
	cout << endl;
}


void testList_3(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	myPrintList_3(L1);

	if (L1.empty()){//2.empty();判断容器是否为空
		cout << "L1为空" << endl;
	}
	else{
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;//1.size();返回容器中元素的个数
	}

	L1.resize(2);//3.resize(elem);重新指定大小
	myPrintList_3(L1);

	L1.resize(10, 5);//4.resize(num, elem);重新指定大小
	myPrintList_3(L1);
}

//void main() {
//	testList_3();
//}