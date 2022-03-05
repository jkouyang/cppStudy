/*List �Զ����������͵�����
	ͨ��sort()ʵ��

������
	��Person�Զ����������ͽ�������Person�����������������䡢���
	������򣺰��������������

ʵ�з�����������������"<"�ź�">"�ŵ�����
*/


#include<iostream>
#include<string>
#include<list>
using namespace std;

class PersonList_7 {
public:
	string myName;
	int myAge;
	int myHeight;
	PersonList_7(string name,int age,int height) {
		this->myName = name;
		this->myAge = age;
		this->myHeight = height;
	}
	bool operator<(PersonList_7 per) {//����<�ţ�ʹ��list����ʹ��sort()Ĭ������
		return this->myAge < per.myAge;
	}
	bool operator>(PersonList_7 per) {//����<�ţ�ʹ��list����ʹ��sort()��������
		return this->myAge > per.myAge;
	}
};

void myPrintList_7(const list<PersonList_7>& L) {
	for (list<PersonList_7>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {
		cout << pBegin->myName << "\t" << pBegin->myAge << "\t" << pBegin->myHeight << endl;
	}
}

bool myCompareList_7(PersonList_7 p1, PersonList_7 p2) {//ָ�����򣬴Ӵ�С
	//���򣺾��õ�һ�������ڵڶ�����
	return p1 > p2;
}

void testList_7() {
	PersonList_7 p1("Tom", 17, 178);
	PersonList_7 p2("Mary", 18, 175);
	PersonList_7 p3("Job", 25, 172);
	PersonList_7 p4("Kim", 21, 168);
	PersonList_7 p5("Yang", 17, 188);
	list<PersonList_7> L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	cout << "============ԭʼ����============" << endl;
	myPrintList_7(L);
	cout << "========sortĬ�������==========" << endl;
	L.sort();
	myPrintList_7(L);
	cout << "========sort���������==========" << endl;
	L.sort(myCompareList_7);
	myPrintList_7(L);
}

//void main() {
//	testList_7();
//}