/*
�������캯���ĵ���ʱ����
	1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
	2.ֵ���ݵķ�ʽ������������ֵ
	3.��ֵ��ʽ���ؾֲ�����
*/
#include<iostream>
using namespace std;

class Person_11_2 {
public:
	Person_11_2() {
		cout << "�޲ι��캯��!" << endl;
		this->age = 0;
	}
	Person_11_2(int age) {
		cout << "�вι��캯��!" << endl;
		this->age = age;
	}
	Person_11_2(const Person_11_2& p) {
		cout << "�������캯��!" << endl;
		this->age = p.age;
	}
	//�����������ͷ��ڴ�֮ǰ����
	~Person_11_2() {
		cout << "��������!" << endl;
	}
public:
	int age;
};

//1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test_11_2a() {
	cout << "*****1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���" << endl;
	Person_11_2 man(100); //p�����Ѿ��������
	Person_11_2 newman(man); //���ÿ������캯��
	Person_11_2 newman2 = man; //��������

	//Person newman3;
	//newman3 = man; //���ǵ��ÿ������캯������ֵ����
}

//2. ֵ���ݵķ�ʽ������������ֵ
//�൱��Person p1 = p;
void doWork(Person_11_2 p1) {}
void test_11_2b() {
	cout << endl << "*****2.ֵ���ݵķ�ʽ������������ֵ" << endl;
	Person_11_2 p; //�޲ι��캯��
	doWork(p);
}

//3. ��ֵ��ʽ���ؾֲ�����
Person_11_2 doWork2()
{
	Person_11_2 p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test_11_2c()
{
	cout << endl << "*****3.��ֵ��ʽ���ؾֲ�����" << endl;
	Person_11_2 p = doWork2();
	cout << (int*)&p << endl;
}


//void main() {
//	test_11_2a();
//	test_11_2b;
//	test_11_2c();
//}