/*string容器
本质：string是C++风格的字符串，而string本质上是一个类

string和char区别：
	1.char是一个指针
	2.string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器。

特点：
	1.string 类内部封装了很多成员方法
		查找find，拷贝copy，删除delete 替换replace，插入insert
	2.string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

string构造函数:
	1.string();         			//默认构造,创建一个空的字符串 例如: string str;
	2.string(const char* s);	    //使用字符串常量初始化
	3.string(const string& str);	//拷贝构造，使用一个string对象初始化另一个string对象
	4.string(int n, char c);		//使用n个字符c初始化

*/

#include<iostream>
#include<string>
using namespace std;

void testStr_1() {
	string str1;//1.默认构造

	string str2("hello");//2.使用字符串s初始化
	cout << "str2: " << str2 << endl;

	string str3(str2);//3.拷贝构造
	cout << "str3: " << str3 << endl;

	string str4(10, 'a');//4.
	cout << "str4: " << str4 << endl;
}

//void main() {
//	testStr_1();
//}


