/*ģ��ľ�����
ģ���ͨ���Բ��������ܵģ���Щ�ض����������ͣ���Ҫ�þ��廯�������������ʵ��

ģ�庯�����ض����������͵����ֽ��������	
	1.���������(ǰ��ѧ��������Ͳ�д��)
	2.���þ��廯��Person�汾��ʵ��ģ�庯�����أ����廯���ȵ���

�ܽ᣺
	���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
	ѧϰģ�岢����Ϊ��дģ�壬������STL�ܹ�����ϵͳ�ṩ��ģ��
*/

#include<iostream>
using namespace std;

class Person_21_5 {//����һ��������ģ��
public:
	string name;
	int age;
	Person_21_5(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

//�Ա����������Ƿ����
template<typename T>
bool isEqual_21_5(T &a, T &b) {//ģ�庯��
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//2.���þ��廯��Person�汾��ʵ��ģ�庯�����أ����廯���ȵ���
template<> bool isEqual_21_5(Person_21_5& a, Person_21_5& b) {
	if (a.age == b.age && a.name == b.name) {
		return true;
	}
	else {
		return false;
	}
}

void test_21_5a() {//�Ƚ�����int�����Ƿ����
	int a = 10;
	int b = 10;
	bool set = isEqual_21_5(a, b);
	if (set) {
		cout << "a��b���" << endl;
	}
	else {
		cout << "a��b�����" << endl;
	}
}

void test_21_5b() {//�Ƚ�����Person�����Ƿ����
	/*���ַ���  1.���������(ǰ��ѧ��������Ͳ�д��)
				2.���þ��廯��Person�汾��ʵ��ģ�庯�����أ����廯���ȵ���
	*/
	Person_21_5 p1 = Person_21_5("Tom", 25);
	Person_21_5 p2 = Person_21_5("Tom", 25);
	bool set = isEqual_21_5(p1, p2);
	if (set) {
		cout << "p1��p2���" << endl;
	}
	else {
		cout << "p1��p2�����" << endl;
	}
}
//void main() {
//	test_21_5a();
//	test_21_5b();
//}