/*
vector�д���Զ����������ͣ�����ӡ���

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Person_22_3 {
public:
	string myName;
	int myAge;
	Person_22_3(string name,int age) {
		this->myName = name;
		this->myAge = age;
	}
};

void test_22_3a() {//�����Ķ���
	vector<Person_22_3> v1;
	Person_22_3 p1("��ɮ",25);
	Person_22_3 p2("�����", 999);
	Person_22_3 p3("��˽�", 798);
	Person_22_3 p4("ɳɮ", 654);
	Person_22_3 p5("������", 425);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
	for (vector<Person_22_3>::iterator pBegin = v1.begin(); pBegin != v1.end(); pBegin++) {
		//pBegin��һ��ָ�룬ָ�����������Ϊvector�����ŵ����ݽṹ
		cout << pBegin->myName << " \t" << pBegin->myAge << endl;
		//cout << (*pBegin).myName << " \t" << (*pBegin).myAge << endl;
		//��������д��������
	}
	//cout << endl;
}

void test_22_3b() {
	vector<Person_22_3*> v2;
	Person_22_3 p1("��ɮ", 25);
	Person_22_3 p2("�����", 999);
	Person_22_3 p3("��˽�", 798);
	Person_22_3 p4("ɳɮ", 654);
	Person_22_3 p5("������", 425);
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);
	v2.push_back(&p4);
	v2.push_back(&p5);
	for (vector<Person_22_3*>::iterator pBegin = v2.begin(); pBegin != v2.end(); pBegin++) {
		cout << (*pBegin)->myName << " \t" << (*pBegin)->myAge << endl;
	}
}

//void main() {
//	test_22_3a();
//	cout << "=============================================" << endl;
//	test_22_3b();
//}