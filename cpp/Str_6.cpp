/*
string�ĵ����ַ�����д(�޸�)
	1.ͨ��[]���ʵ����ַ�
	2.ͨ��at(int i)������ʽ���ʵ����ַ�
*/

#include<iostream>
#include<string>
using namespace std;

void testStr_6() {
	string str = "hello";
	//��
	//1.ͨ��[]���ʵ����ַ�
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;

	//2.ͨ��at(int i)������ʽ���ʵ����ַ�
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;

	//д(�޸�)
	//1.ͨ��[]�޸ĵ����ַ�
	str[0] = 'e';

	//2.ͨ��at(int i)������ʽ�޸ĵ����ַ�
	str.at(1) = 'x';

	cout << "str:" << str << endl;

}

//void main() {
//	testStr_6();	
//}