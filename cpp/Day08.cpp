/*Day08
����
	���ã���������һ������
	�﷨���������� &����=ԭ����

	(1)����һ��Ҫ��ʼ��
		int &c;//����Ҫ��b��ʼ������ָ��a
	(2)���ó�ʼ���󣬲��ܸ���
		int &c=a;
		int &c=b;//���󣬲��ܸ������õ�ָ��
	(3)��Ҫ���ؾֲ����������ã�ֵ��ı�
	(4)�����ķ���ֵΪ���õ�ʱ�򣬺������ÿ�����Ϊ��ֵ����ʽ��ߣ�
	(5)���ñ��ʣ�ָ�볣����ָ�򲻿����޸ģ�ָ���ֵ�����޸�
		int &ref = a;//�Զ�ת�� int* const ref = & a;//ָ�볣��
		ref = 20;//�ڲ�����ref�����ã��Զ�ת��Ϊ*ref = 20;
	(6)�������� const int& ref =10;
****C++�Ƽ�ʹ�����ã���Ϊ�﷨���㣬���ñ�����ָ�볣�����������е�ָ�����������������������
*/

#include <iostream>
#include <string>

using namespace std;

//��������
int g08_a = 10;
int g08_b = 10;
int& c = g08_a;
//int& c = g_b;///���󣬲��ܸ������õ�ָ��

void swap(int &a, int &b) {//���ô��ݣ��βλ�����ʵ��
	int temp = b;
	b = a;
	a = temp;
}

int& test01() {//��Ҫ���ؾֲ�����������
	int l_a = 10;
	return l_a;
}

int& test02() {//��Ҫ���ؾֲ�����������
	static int static_b = 10;
	return static_b;
}

void showValue(const int& ref) {//ʹ�ó������ã��ñ���ֻ�ܱ����ʣ������޸�
	//ref += 10;//ֻ�ܱ����ʣ������޸�
	cout << "��ӡg08_a="<< ref << endl;
}

//void main() {
//
//	cout << "ԭʼa,b��ֵ" << endl;
//	cout << "g_a=" << g08_a << endl;
//	cout << "g_b=" << g08_b << endl;
//	c = 20;
//	cout << endl << "�޸�����c��c����a����g_a,g_b��ֵ" << endl;
//	cout << "g_a=" << g08_a << endl;
//	cout << "g_b=" << g08_b << endl;
//
//	swap(g08_a, g08_b);//���ô��ݣ��βλ�����ʵ��
//	cout << endl << "���ô��ݺ�swap(int &a, int &b)����g_a,g_b��ֵ" << endl;
//	cout << "g_a=" << g08_a << endl;
//	cout << "g_b=" << g08_b << endl;
//
//	cout << endl << "��Ҫ���ؾֲ����������ã�ֵ��ı䣬��Ϊ���ݴ����ջ��" << endl;
//	int &return_l_a = test01();
//	cout << "l_a=" << return_l_a << endl;
//	cout << "l_a=" << return_l_a << endl;
//	cout << "l_a=" << return_l_a << endl;
//
//	int& return_l_b = test02();
//	cout << endl << "ȫ�ֱ��������ã�ֵ�᲻��䣬��Ϊ���ݴ����ȫ����" << endl;
//	cout << "static_b=" << return_l_b << endl;
//	cout << "static_b=" << return_l_b << endl;
//	cout << "static_b=" << return_l_b << endl;
//
//	test02() = 123;//�����ķ���ֵΪ���õ�ʱ�򣬺������ÿ�����Ϊ��ֵ����ʽ��ߣ����޸�static_b=1123��
//	cout << endl << "����������Ϊ��ֵ����ʽ��ߣ����޸�static_b" << endl;
//	cout << "static_b=" << return_l_b << endl;
//
//	//int& ref = 10;  ���ñ�����Ҫһ���Ϸ����ڴ�ռ䣬������д���
//	//����const�Ϳ����ˣ��������Ż����룬int temp = 10; const int& ref = temp;
//	const int& ref = 10;
//
//	//ref = 100;  //����const�󲻿����޸ı���
//	cout << endl << "��������ref="<< ref << endl;
//
//	showValue(g08_a);
//}