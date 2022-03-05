/*
��������
	1.��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
	2.Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
	3.�����10��Ա�����䲿�ź͹���
	4.ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
	5.�ֲ�����ʾԱ����Ϣ

ʵ�ֲ��裺
	1.����10��Ա�����ŵ�vector��
	2.����vector������ȡ��ÿ��Ա���������������
	3.����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
	4.�ֲ�����ʾԱ����Ϣ
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stdlib.h>
#include <time.h>
using namespace std;

class WorkerCase {//Ա����
public:
	string myName;
	int myWage;
	WorkerCase(string name,int wage) {
		this->myName = name;
		this->myWage = wage;
	}
};

void makeWorkerCase(vector<WorkerCase> &v) {//����Ա��
	string str = "Worker_";
	string name = "ABCDEFGHIJ";
	
	for (int i = 0; i < 10; i++) {
		WorkerCase worker(str+name[i],rand()%5000+5000);
		v.push_back(worker);
	}
}

void makeDeptCase(vector<WorkerCase>& v, multimap<int, WorkerCase>& m) {//���䲿��
	for (vector<WorkerCase>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		m.insert(make_pair(rand() % 3, *pBegin));
	}
}

void myPrintWorkerCase(multimap<int, WorkerCase>& m) {//��ʾ��Ϣ
	//key=0ʱΪ������
	multimap<int, WorkerCase>::iterator pBegin = m.find(0);
	int num0 = m.count(0);
	cout << "============������(" << num0 << "��)=========== " << endl;
	for (int index = 0; pBegin != m.end() && index < num0; pBegin++, index++) {
		cout << "������" << pBegin->second.myName << "\t����" << pBegin->second.myWage << endl;
	}
	//key=1ʱΪ�з���
	pBegin = m.find(1);
	int num1 = m.count(1);
	cout << "============�з���(" << num1 << "��)=========== " << endl;
	for (int index = 0; pBegin != m.end() && index < num1; pBegin++, index++) {
		cout << "������" << pBegin->second.myName << "\t����" << pBegin->second.myWage << endl;
	}
	//key=2ʱΪ�߻���
	pBegin = m.find(2);
	int num2 = m.count(2);
	cout << "============�߻���(" << num2 << "��)=========== " << endl;
	for (int index = 0; pBegin != m.end() && index < num2; pBegin++, index++) {
		cout << "������" << pBegin->second.myName << "\t����" << pBegin->second.myWage << endl;
	}
}

void testWorkerCase() {
	srand((unsigned)time(NULL));
	vector<WorkerCase> v_Worker;
	makeWorkerCase(v_Worker);
	multimap<int, WorkerCase> m__Worker;
	makeDeptCase(v_Worker,m__Worker);
	myPrintWorkerCase(m__Worker);
}

//void main() {
//	testWorkerCase();
//}
