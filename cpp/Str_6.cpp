/*
string的单个字符读和写(修改)
	1.通过[]访问单个字符
	2.通过at(int i)函数方式访问单个字符
*/

#include<iostream>
#include<string>
using namespace std;

void testStr_6() {
	string str = "hello";
	//读
	//1.通过[]访问单个字符
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;

	//2.通过at(int i)函数方式访问单个字符
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;

	//写(修改)
	//1.通过[]修改单个字符
	str[0] = 'e';

	//2.通过at(int i)函数方式修改单个字符
	str.at(1) = 'x';

	cout << "str:" << str << endl;

}

//void main() {
//	testStr_6();	
//}