/*��ģ�����Ԫ

	1.ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
	2.ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���

*/
#include<iostream>
#include<string>
using namespace std;

//������
template<class T1, class T2>
class Person_21_11;
//����ģ�庯��
template<class T1, class T2>
void showPerson_21_11b(Person_21_11<T1, T2>& p);

template<class T1,class T2>
class Person_21_11 {
	//1��ȫ�ֺ���(����friend����ȫ�ֺ���)�����Ԫ   ����ʵ��
	friend void showPerson_21_11a(Person_21_11<T1,T2> &p) {
		cout << "Name: " << p.name << "\tAge: " << p.age << endl;
	}
	//2.ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
	friend void showPerson_21_11b<>(Person_21_11<T1, T2>& p);
public:
	Person_21_11(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
private:
	T1 name;
	T2 age;
};

template<class T1, class T2>
void showPerson_21_11b(Person_21_11<T1, T2>& p) {//2.ȫ�ֺ��������Ԫ  ����ʵ��
	cout << "Name: " << p.name << "\tAge: " << p.age << endl;
}

void test_21_11() {
	Person_21_11<string, int> p("Tom", 20);
	showPerson_21_11a(p);
	showPerson_21_11b(p);
}

//void main() {
//	test_21_11();
//	system("pause");
//}