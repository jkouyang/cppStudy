/*string����
���ʣ�string��C++�����ַ�������string��������һ����

string��char����
	1.char��һ��ָ��
	2.string��һ���࣬���ڲ���װ��char*����������ַ�������һ��char*�͵�������

�ص㣺
	1.string ���ڲ���װ�˺ܶ��Ա����
		����find������copy��ɾ��delete �滻replace������insert
	2.string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ����и���

string���캯��:
	1.string();         			//Ĭ�Ϲ���,����һ���յ��ַ��� ����: string str;
	2.string(const char* s);	    //ʹ���ַ���������ʼ��
	3.string(const string& str);	//�������죬ʹ��һ��string�����ʼ����һ��string����
	4.string(int n, char c);		//ʹ��n���ַ�c��ʼ��

*/

#include<iostream>
#include<string>
using namespace std;

void testStr_1() {
	string str1;//1.Ĭ�Ϲ���

	string str2("hello");//2.ʹ���ַ���s��ʼ��
	cout << "str2: " << str2 << endl;

	string str3(str2);//3.��������
	cout << "str3: " << str3 << endl;

	string str4(10, 'a');//4.
	cout << "str4: " << str4 << endl;
}

//void main() {
//	testStr_1();
//}


