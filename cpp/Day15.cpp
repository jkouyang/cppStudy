/*Day15 const���κ����Ͷ���

��������
	��Ա�������const�����ǳ�Ϊ�������Ϊ**������**
	�������ڲ������޸ĳ�Ա����
	��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�

������
	��������ǰ��const�Ƹö���Ϊ������
	������ֻ�ܵ��ó�����

*/

#include<iostream>
using namespace std;

class Person_15 {
public:
public:
	int m_A;
	mutable int m_B; //���޸� �ɱ��

	Person_15() {
		m_A = 0;
		m_B = 0;
	}

	//thisָ��ı�����һ��ָ�볣����ָ���ָ�򲻿��޸�
	//�������ָ��ָ���ֵҲ�������޸ģ���Ҫ����������
	void ShowPerson() const {
		//const Type* const pointer;
		//this = NULL; //�����޸�ָ���ָ�� Person* const this;
		//this->mA = 100; //����thisָ��ָ��Ķ���������ǿ����޸ĵ�

		//const���γ�Ա��������ʾָ��ָ����ڴ�ռ�����ݲ����޸ģ�����mutable���εı���
		this->m_B = 100;
		cout << "������" << endl;
	}

	void MyFunc() {
		//mA = 10000;
		cout << "��ͨ����"<< endl;
	}
	//const���ζ���  ������
};
void test_15() {

		const Person_15 person; //��������  
		cout << person.m_A << endl;
		//person.mA = 100; //���������޸ĳ�Ա������ֵ,���ǿ��Է���
		person.m_B = 100; //���ǳ���������޸�mutable���γ�Ա����

		person.ShowPerson();//������ֻ�ܵ��ó�����

		//��������ʳ�Ա����
		//person.MyFunc(); //�������ܵ�����ͨ����
		Person_15 person11;
}
//void main() {
//	test_15();
//}