/*vector互换容器——实现两个容器内元素进行互换,本质是改变指向
	swap(vec);// 将vec与本身的元素互换
*/

#include<iostream>
#include<vector>
using namespace std;
void myPrintVect_6(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}


void testVect_6a() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	
	vector<int> v2;
	for (int i = 20; i > 0; i--) {
		v2.push_back(i);
	}
	//v1.resize(3);
	//v2.resize(5);
	//swap(vec);// 将两个容器的元素互换
	cout << "交换前：" << endl;
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
	cout << "v2的容量：" << v2.capacity() << endl;
	cout << "v2的大小：" << v2.size() << endl;
	myPrintVect_6(v1);
	myPrintVect_6(v2);

	cout << "交换后：" << endl;
	v1.swap(v2);
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的大小：" << v1.size() << endl;
	cout << "v2的容量：" << v2.capacity() << endl;
	cout << "v2的大小：" << v2.size() << endl;
	myPrintVect_6(v1);
	myPrintVect_6(v2);
	//可以看出swap()交换实质就算改变两个容器的指向

}

//巧用swap()可以收缩内存空间
void testVect_6b() {
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i + 1);
	}
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;

	v.resize(3);//容器容量远大于容器存储的数据长度，造成内存浪费
	cout << "未收缩内存空间前：" << endl;
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;

	//巧用swap()收缩内存空间
	vector<int>(v).swap(v);
	//vector<int>(v)，利用拷贝构造函数创建一个匿名对象x，里面存储容器v的元素，x和v互换指向
	//这一行运行完之后x指向的大容量容器被系统回收(匿名对象当前行运行完之后就被回收)
	cout << "swap()收缩内存空间后：" << endl;
	cout << "v的容量：" << v.capacity() << endl;
	cout << "v的大小：" << v.size() << endl;
}

//void main() {
//	testVect_6a();
//	cout << endl << "=========巧用swap()可以收缩内存空间==========" << endl << endl;
//	testVect_6b();
//}