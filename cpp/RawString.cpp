/*ԭʼ�ַ���
�﷨:	R "xxx(ԭʼ�ַ���)xxx"
	ԭʼ������ R ����ֱ�ӱ�ʾ�ַ�����ʵ�ʺ��壬������Ҫ������ַ�����ת������ӵȲ���
	ԭʼ�ַ�������������()������
	���ŵ�ǰ����Լ������ַ��������ӵ��ַ����ᱻ���ԣ����Ҽӵ��ַ���������ͬ������������ͬʱ����

���ã�
	1.����ת���ַ��ģ���Ҫֱ�ӱ���ַ�������
	2.�ַ����ϳ�����Ҫд���С���ûɶ��
*/

#include<iostream>
#include<string>
using namespace std;

void testRawString() {
	//1.����ת���ַ��ģ���Ҫֱ�ӱ���ַ�������
	string str1 = "D:\\hello\\world\\test.text";
	cout << str1 << endl;
	string str2 = R"(D:\hello\world\test.text)";
	cout << str2 << endl;

	//2.raw string���Կ�Խ���У����еĿհ׺ͻ��з��������ַ�����һ����
	string str3 = "<html>\
					<head>\
					<title>\ ";
	cout << str3 << endl;
	string str4 = R"(
				<html>
				<head>
				<title>)";
	cout << str4 << endl;

}

//void main() {
//	testRawString();
//}