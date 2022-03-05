/*vector的容量和大小

	1.empty();//判断容器是否为空
	2.capacity();//容器的容量
	3.size();//返回容器中元素的个数
	4.max_size();//返回容器可以存储的最大长度(好大好大)
	5.resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
		//如果容器变短，则末尾超出容器长度的元素被删除。
	6.resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
		//如果容器变短，则末尾超出容器长度的元素被删除

*/



#include<iostream>
#include<vector>
using namespace std;

void myPrintVect_3(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testVect_3() {
	vector<int> v1;
	for(int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	myPrintVect_3(v1);

	if (v1.empty()) {//1.empty();//判断容器是否为空
		cout << "v1为空!" << endl;
	}
	else {
		cout << "v1不为空!" << endl;
		cout << "v1的容量：" << v1.capacity() << endl;//2.capacity();容器的容量
		cout << "v1的长度：" << v1.size() << endl;//3.size();返回容器中元素的个数
		cout << "v1的max长度：" << v1.max_size() << endl;//4.max_size();返回容器可以存储的最大长度(好大好大)
	}

	v1.resize(15);//5.resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
	myPrintVect_3(v1);
	v1.resize(8);//5.resize(int num);//如果容器变短，则末尾超出容器长度的元素被删除
	myPrintVect_3(v1);

	v1.resize(15, 5);//6.resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置
	myPrintVect_3(v1);
	v1.resize(5, 5);//6.resize(int num, elem)//如果容器变短，则末尾超出容器长度的元素被删除
	myPrintVect_3(v1);
}

//void main() {
//	testVect_3();
//}