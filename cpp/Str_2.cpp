/*string��ֵ����
*��ֵ������
	1.str1 = "hello";				//char*�����ַ�������ֵ����ǰ���ַ���
	2.str2 = str1;					//���ַ���s������ǰ���ַ���
	3.str3 = 'a';					//�ַ���ֵ����ǰ���ַ���
	4.str4.assign("hello C++");		//���ַ���s������ǰ���ַ���
	5.str5.assign("hello C++",n);	//���ַ���s��ǰn���ַ�������ǰ���ַ���
	6.str6.assign(str4);			//���ַ���s������ǰ�ַ���
	7.str7.assign(n, 'a');			//��n���ַ�c������ǰ�ַ���

*/

#include<iostream>
#include<string>
using namespace std;

void testStr_2() {
	string str1;
	str1 = "hello";//1.�ַ���������ֵ����ǰ�ַ���
	cout << "str1=" << str1 << endl;

	string str2;
	str2 = str1;//2.��һ���ַ�����ֵ��ֵ����һ���ַ���
	cout << "str2=" << str2 << endl;

	string str3;
	str3 = 'a';//3.���ַ�����ֵһ���ַ�
	cout << "str3=" << str3 << endl;

	string str4;
	str4.assign("hello C++");//4.����assign()���������ַ���������ֵ����ǰ�ַ���
	cout << "str4=" << str4 << endl;

	string str5;
	str5.assign("hello C++",5);//5.����assign()���������ַ���������ǰn���ַ���ֵ����ǰ�ַ���
	cout << "str5=" << str5 << endl;

	string str6;
	str6.assign(str4);//6.����assign()��������һ���ַ�����ֵ��ֵ����һ���ַ���
	cout << "str6=" << str6 << endl;

	string str7;
	str7.assign(10, 'a');//7.����assign()���������ַ�����ֵn���������ַ�
	cout << "str7=" << str7 << endl;

}

//void main() {
//	testStr_2();
//}