/*string 大小
*
	int size();
	int length();
	bool empty();
	void resize(n);
	int capacity();
	void reserve();
	int max_size()

* 注意：
	length是沿用C语言而保留下来的，引入STL之后，为了兼容又加入了size(兼容STL接口)，其实两者一样
	string类的size()/length()方法返回的是字节数，不管是否有汉字。

*/

#include<iostream>
#include<string>
using namespace std;

void testStr_9() {
	string str = "123abc\0abc";
	cout << "str:" << str << endl;
	cout << "str.size():" << str.size() << endl;//size()，length()两者一样
	cout << "str.length():" << str.length() << endl;
	cout << "sizeof(str):" << sizeof(str) << endl;//string所占的字节
	cout << "str.capacity():" << str.capacity() << endl;//兼容STL，引入capacity()
	bool flag = str.empty();
	str.resize(3);
	cout << "str:" << str << endl;
	str.resize(13,'a');//超过的默认填充'/0'
	cout << "str:" << str << endl;
}

//void main() {
//	testStr_9();
//}