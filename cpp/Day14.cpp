/*Day14  thisָ��
thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
	thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
	thisָ�벻��Ҫ���壬ֱ��ʹ�ü���

thisָ�����;��
	���βκͳ�Ա����ͬ��ʱ������thisָ��������
	����ķǾ�̬��Ա�����з��ض�������ʹ��return *this

C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����ҲҪע����û���õ�thisָ��
*/

#include<iostream>
using namespace std;

class Person_14
{
public:

	Person_14(int age)
	{
		//1�����βκͳ�Ա����ͬ��ʱ������thisָ�������֣����������ͻ
		this->age = age;
	}

	Person_14& PersonAddPerson(Person_14 p)
	{
		this->age += p.age;
		//2�����ض�����
		return *this;
	}

	void show_14a() {
		cout << "��ָ����ó�Ա����" << endl;
	}
	void show_14b() {
		if (this == NULL) {//���Ӿͻᱨ��
			return;
		}
		cout << "��ָ����ó�Ա���������age:" << age << endl;//ʹ�ó�Ա����ʱϵͳ�Զ�ʹ��thisָ�루age��Чthis->age��
	}
	int age;
};

void test_14a()
{
	Person_14 p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person_14 p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);//��ʽ���˼��
	cout << "p2.age = " << p2.age << endl;
}

void test_14b() {
	Person_14* p = NULL;
	p->show_14a();//��ָ����ó�Ա����
	p->show_14b();
}


//void main() {
//	test_14a();
//	test_14b();
//}
