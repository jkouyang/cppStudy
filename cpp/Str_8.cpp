/*
string求子串
	string substr(int pos = 0, int n = npos) const;   //返回由pos开始的n个字符组成的字符串
*/

#include<iostream>
#include<string>
using namespace std;


void testStr_8() {
	string str = "0123456789";
	string substr = str.substr(1, 5);
	cout << "substr:" << substr << endl;

	//实用操作--重邮箱中截取用户名
	string email_1 = "jkouyang@163.com";
	string email_2 = "ouyjk@mail2.sysu.edu.cn";

	int flag1 = email_1.find('@');
	int flag2 = email_2.find('@');

	string username_1 = email_1.substr(0, flag1);
	string username_2 = email_2.substr(0, flag2);

	cout << "username_1:" << username_1 << endl;
	cout << "username_2:" << username_2 << endl;
}


//void main() {
//	testStr_8();
//}
