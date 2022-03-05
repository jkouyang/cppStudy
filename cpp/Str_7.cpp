/*
string插入和删除
	1.string& insert(int pos, const char* s);		//插入字符串
	2.string& insert(int pos, const string& str);	//插入字符串
	3.string& insert(int pos, int n, char c);		//在指定位置插入n个字符c
	4.string& erase(int pos, int n = npos);			//删除从Pos开始的n个字符 
*/

#include<iostream>
#include<string>
using namespace std;


void testStr_7() {
	string str = "hello";
	cout << "str:" << str << endl;
	str.insert(1, "123");//2.插入字符串
	cout << "str:" << str << endl;
	str = "hello";
	str.insert(1, 3, '5');//3.插入n个字符
	cout << "str:" << str << endl;
	str.erase(1, 3);//4.删除从Pos开始的n个字符 
	cout << "str:" << str << endl;
}

//void main() {
//	testStr_7();
//}






