/*
string���Ӵ�
	string substr(int pos = 0, int n = npos) const;   //������pos��ʼ��n���ַ���ɵ��ַ���
*/

#include<iostream>
#include<string>
using namespace std;


void testStr_8() {
	string str = "0123456789";
	string substr = str.substr(1, 5);
	cout << "substr:" << substr << endl;

	//ʵ�ò���--�������н�ȡ�û���
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
