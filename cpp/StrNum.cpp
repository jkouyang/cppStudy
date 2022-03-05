/*C++11 ���ṩ��ר�ŵ�����ת�����������Էǳ������ʹ�����ǽ�����ֵ���ͺ��ַ�������֮���ת��

*�����͡��ַ���
	to_string();

*�ַ�����������
	int stoi();
	float stof();
	double stod();
	long stol();

* �ܽ᣺
	����ַ����������ַ�������ֵ���ͣ������ַ����ᱻת��Ϊ��Ӧ����ֵ����ͨ������ֵ����
	����ַ�����ǰ�벿���ַ�����ֵ���ͣ���벿���ǣ���ôǰ�벿�ֻᱻת��Ϊ��Ӧ����ֵ����ͨ������ֵ����
	����ַ���һ���ַ�������ֵ����ת��ʧ��
*/

#include<iostream>
#include<string>
using namespace std;

void testStrNum() {
//1.�����͡��ַ���	to_string();
	int int_a = 5;
	string str_a = to_string(int_a);
	cout << "str_a: " << str_a << endl;
	cout << "====================" << endl;

//2.�ַ�����������
	string str1 = "45";
	string str2 = "3.1415926546545654654654645678687987987978978978978935898";
	string str3 = "9527 with words";
	string str4 = "words and 2";

	int myint1 = std::stoi(str1);
	float myfloat = std::stof(str2);
	double mydouble = stod(str2);
	int myint2 = std::stoi(str3);
	// ���� 'std::invalid_argument'
	// int myint4 = std::stoi(str4);

	cout.precision(100);
	cout << "myint1: " << myint1 << endl;
	cout << "myflate: " << myfloat << endl;
	cout << "mydouble: " << mydouble << endl;
	cout << "myint2: " << myint2 << endl;

}

//void main() {
//	testStrNum();
//}