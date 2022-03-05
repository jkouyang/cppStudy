/*List �Զ����������͵�����
	ͨ��sort()ʵ��

������
	��Person�Զ����������ͽ�������Person�����������������䡢���
	������򣺰���������н���������ͬʱ���������

ʵ�ַ�����������ʵ�֣�ע����List_7.cpp(����ʵ��)�Աȣ�
		���ַ�������ʵ���κ���Ҫ������ʽ
*/


#include<iostream>
#include<string>
#include<list>
using namespace std;

class PersonList_8 {
public:
	string myName;
	int myAge;
	int myHeight;
	PersonList_8(string name, int age, int height) {
		this->myName = name;
		this->myAge = age;
		this->myHeight = height;
	}
};

void myPrintList_8(const list<PersonList_8>& L) {
	for (list<PersonList_8>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {
		cout << pBegin->myName << "\t" << pBegin->myAge << "\t" << pBegin->myHeight << endl;
	}
}

bool myCompareList_8(PersonList_8 p1, PersonList_8 p2) {//ָ���������ַ�������ʵ���κ���Ҫ������ʽ
	if (p1.myAge == p2.myAge) {
		return p1.myHeight < p2.myHeight;//�������ʱ����������򣨵�һ������С�ڵڶ������ݣ�
	}
	else {
		return p1.myAge > p2.myAge;//�Ȱ����併�򣨵�һ�����ݴ��ڵڶ������ݣ�
	}
}

void testList_8() {
	PersonList_8 p1("Tom", 17, 178);
	PersonList_8 p2("Mary", 18, 175);
	PersonList_8 p3("Job", 25, 172);
	PersonList_8 p4("Kim", 21, 168);
	PersonList_8 p5("Yang", 17, 188);
	PersonList_8 p6("Tian", 17, 168);
	PersonList_8 p7("Mei", 17, 175);
	PersonList_8 p8("Zhen", 17, 171);

	list<PersonList_8> L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);
	L.push_back(p8);
	cout << "============ԭʼ����============" << endl;
	myPrintList_8(L);
	//Ĭ������ᱨ����Ϊû����д"<"�ţ��޷��Ա������Զ����������͵Ĵ�С
	/*cout << "========sortĬ�������==========" << endl;
	L.sort();
	myPrintList_8(L);*/
	cout << "===========sort�����===========" << endl;
	L.sort(myCompareList_8);//�Զ������������һ��Ҫ�Լ�ָ���������ֻ�ô������������ü�()������
	myPrintList_8(L);
}

//void main() {
//	testList_8();
//}