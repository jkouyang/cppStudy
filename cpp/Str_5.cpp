/*
字符串的比较：字符串比较是按字符的ASCII码进行对比
	两字符串相等	= 返回   0
	ASCII大			> 返回   1
	ASCII小			< 返回  -1

语法：
	int compare(const string &s) const;  //与字符串s比较
	int compare(const char *s) const;    //与字符串s比较
*/

#include<iostream>
#include<string>
using namespace std;

void testStr_5() {
	string str1 = "hello";
	string str2 = "xello";
	string str3 = {'h','e','l','l','o'};
	char str4[] = "hello";//不是字符串，不能调用字符串的函数
	char str5[] = { 'h','e','l','l','o' };//不是字符串，不能调用字符串的函数
	cout << "str1.size():" << str1.size() << endl;
	cout << "sizeof(str1):" << sizeof(str1) << endl;
	cout << "sizeof(str2):" << sizeof(str2) << endl;
	cout << "sizeof(str3):" << sizeof(str3) << endl;
	cout << "sizeof(str4):" << sizeof(str4) << endl;
	cout << "sizeof(str5):" << sizeof(str5) << endl;

	//利用compare()比较两个字符串，相等返回0
	cout << "str1.compare(str2):" << str1.compare(str2) << endl;
	cout << "str1.compare(str3):" << str1.compare(str3) << endl;

}

//void main() {
//	testStr_5();
//}