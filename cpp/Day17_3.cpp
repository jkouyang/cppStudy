/*
��ϵ��������أ�== �� !=
	���ع�ϵ������������������Զ������Ͷ�����жԱȲ���
*/
#include<iostream>
#include<string>
using namespace std;

class Person_17_3 {
public:
	int age;
	Person_17_3(int age) {
		this->age = age;
	}

	bool operator==(Person_17_3 &p) {
		if (this->age == p.age) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(Person_17_3& p) {
		if (this->age == p.age) {
			return false;
		}
		else {
			return true;
		}
	}
};

void test_17_3() {
	Person_17_3 p1(23);
	Person_17_3 p2(24);
	Person_17_3 p3(23);

	if (p1 == p2) {
		cout << "p1��p2������ͬ" << endl;
	}
	else {
		cout << "p1��p2���䲻��ͬ" << endl;
	}

	if (p1 != p2) {
		cout << "p1��p2���䲻��ͬ" << endl;
	}
	else {
		cout << "p1��p2������ͬ" << endl;
	}

	if (p1 == p3) {
		cout << "p1��p3������ͬ" << endl;
	}
	else {
		cout << "p1��p3���䲻��ͬ" << endl;
	}

	if (p1 != p3) {
		cout << "p1��p3���䲻��ͬ" << endl;
	}
	else {
		cout << "p1��p3������ͬ" << endl;
	}
}

//void main() {
//	test_17_3();
//}