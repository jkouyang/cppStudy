/*set��������
**ʾ����**   set����Զ�����������

ע�⣺
	1.set����Ĭ���������Ϊ��С����������θı��������
	2.���÷º��������Ըı��������
	3.�����Զ����������ͣ�set����ָ���������ſ��Բ�������
*/

#include<iostream>
#include<set>
#include<string>
using namespace std;

class PersonSet_7 {
public:
	string myName;
	int myAge;
	PersonSet_7(string name,int age) {
		this->myName = name;
		this->myAge = age;
	}
};

class myCompareSet_7 {//���÷º��������ƶ��������
public:
	//vs2019Ҫ�ں����const,������
	bool operator()(const PersonSet_7 &p1, const PersonSet_7 &p2) const {
		//���򣬵�һ�������ڵڶ�����
		return p1.myAge > p2.myAge;
	}
};


void testSet_7() {
	set<PersonSet_7, myCompareSet_7> s;
	PersonSet_7 p1("��ɮ", 25);
	PersonSet_7 p2("�����", 999);
	PersonSet_7 p3("��˽�", 758);
	PersonSet_7 p4("ɳɮ", 625);
	PersonSet_7 p5("������", 422);
	//���Զ�����������Ͷ�Ҫ��ָ������ʽ�����ܲ���
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	for (set<PersonSet_7, myCompareSet_7>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << pBegin->myName << "\t" << pBegin->myAge << endl;
	}
}

//void main() {
//	testSet_7();
//}