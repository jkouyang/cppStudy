/*Day12
��̬��Ա����̬����

��̬��Ա����
	1.���ж�����ͬһ������
	2.�ڱ���׶η����ڴ�
	3.���������������ʼ��(�ص�)

��̬��Ա����
	1.���ж�����ͬһ������
	2.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����



*/
#include<iostream>
#include<string>
using namespace std;

class Person_12 {
public:
	static int static_12a;
	int nostatic;
	static void fuc_12a() {
		cout << "��̬����fuc_12a(puplic)" << endl;
		//nostatic = 100;//��̬����ֻ�ܷ��ʾ�̬��Ա���Ǿ�̬��Ա�ľ�̬�������ܷ���
	}

private:
	static int static_12b;
	static void fuc_12b() {
		cout << "��̬����fuc_12b(private)" << endl;
	}
};

int Person_12::static_12a = 0;
int Person_12::static_12b = 0;


void test_12() {
	//��̬��Ա�����;�̬��Ա�������ַ��ʷ�ʽ
	//1��ͨ������
	Person_12 person;
	person.static_12a = 100;
	//person.static_12b = 100;//˽�еľ�̬��Ա���ɷ���
	cout << "static_12a = " << person.static_12a << endl;
	person.fuc_12a();
	//2��ͨ������
	cout << "static_12a = " << Person_12::static_12a << endl;
	Person_12::fuc_12a();
	//Person_12::fuc_12b();//˽�еľ�̬�������ɷ���
}

//void main() {
//	test_12();
//}