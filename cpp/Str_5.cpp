/*
�ַ����ıȽϣ��ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
	���ַ������	= ����   0
	ASCII��			> ����   1
	ASCIIС			< ����  -1

�﷨��
	int compare(const string &s) const;  //���ַ���s�Ƚ�
	int compare(const char *s) const;    //���ַ���s�Ƚ�
*/

#include<iostream>
#include<string>
using namespace std;

void testStr_5() {
	string str1 = "hello";
	string str2 = "xello";
	string str3 = {'h','e','l','l','o'};
	char str4[] = "hello";//�����ַ��������ܵ����ַ����ĺ���
	char str5[] = { 'h','e','l','l','o' };//�����ַ��������ܵ����ַ����ĺ���
	cout << "str1.size():" << str1.size() << endl;
	cout << "sizeof(str1):" << sizeof(str1) << endl;
	cout << "sizeof(str2):" << sizeof(str2) << endl;
	cout << "sizeof(str3):" << sizeof(str3) << endl;
	cout << "sizeof(str4):" << sizeof(str4) << endl;
	cout << "sizeof(str5):" << sizeof(str5) << endl;

	//����compare()�Ƚ������ַ�������ȷ���0
	cout << "str1.compare(str2):" << str1.compare(str2) << endl;
	cout << "str1.compare(str3):" << str1.compare(str3) << endl;

}

//void main() {
//	testStr_5();
//}