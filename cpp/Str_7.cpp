/*
string�����ɾ��
	1.string& insert(int pos, const char* s);		//�����ַ���
	2.string& insert(int pos, const string& str);	//�����ַ���
	3.string& insert(int pos, int n, char c);		//��ָ��λ�ò���n���ַ�c
	4.string& erase(int pos, int n = npos);			//ɾ����Pos��ʼ��n���ַ� 
*/

#include<iostream>
#include<string>
using namespace std;


void testStr_7() {
	string str = "hello";
	cout << "str:" << str << endl;
	str.insert(1, "123");//2.�����ַ���
	cout << "str:" << str << endl;
	str = "hello";
	str.insert(1, 3, '5');//3.����n���ַ�
	cout << "str:" << str << endl;
	str.erase(1, 3);//4.ɾ����Pos��ʼ��n���ַ� 
	cout << "str:" << str << endl;
}

//void main() {
//	testStr_7();
//}






