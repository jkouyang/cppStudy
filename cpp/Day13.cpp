/*Day13
C++�����ڵĳ�Ա�����ͳ�Ա�����ֿ��洢

ֻ�зǾ�̬��Ա������������Ķ�����
*/

#include<iostream>
using namespace std;

class Person_13a {};

class Person_13b {
	int a;//�Ǿ�̬��Ա����
};

class Person_13c {
	int a;//�Ǿ�̬��Ա����
	static int static_13c;//��̬��Ա����
};
int Person_13c::static_13c = 0;
class Person_13d {
	int a;//�Ǿ�̬��Ա����
	static int static_13d;//��̬��Ա����
	void func_13() {}
};

void test_13() {
	//����������ն������һ���ֽڿռ䣬Ϊ�����ֿն���ռ�ڴ��λ��
	cout << "����ռ�ֽ�����" << sizeof(Person_13a) << endl;
	//�Ǿ�̬��Ա����  ������Ķ�����
	cout << "(ֻ���Ǿ�̬��Ա����)��ռ�ֽ�����" << sizeof(Person_13b) << endl;
	//��̬��Ա����    ��������Ķ�����
	cout << "(�Ǿ�̬��Ա����+��̬��Ա����)��ռ�ֽ�����" << sizeof(Person_13c) << endl;
	//��Ա����        ��������Ķ�����
	cout << "(�Ǿ�̬��Ա����+��̬��Ա����+����)��ռ�ֽ�����" << sizeof(Person_13d) << endl;
}


//void main() {
//	test_13();
//}