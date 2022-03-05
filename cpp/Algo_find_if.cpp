/*find_if()������������_Pred()������ϵ�ĵ�һ��Ԫ��
*
	������ʽ��
		iterator find_if(beg, end, _Pred);

	�����Ҳ���ָ��Ԫ�أ��ҵ���һ�����ϵ�Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end()
	_Pred��һ������ֵΪbool�ĺ�����ͨ��Ϊ�º���

ע�⣺


*/



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class PersonFindIf {
public:
	string myName;
	int myAge;
	PersonFindIf(string name, int age) :myName(name), myAge(age) {}
};

class mySelectFindIf {
public:
	bool operator()(const PersonFindIf& p) {
		if (p.myAge < 30) {//��������30���µ�
			return true;
		}
		else {
			return false;
		}
	}
};

void testFindIf() {
	PersonFindIf p1("����", 35);
	PersonFindIf p2("����", 32);
	PersonFindIf p3("�ŷ�", 31);
	PersonFindIf p4("����", 30);
	PersonFindIf p5("�����", 25);
	PersonFindIf p6("������", 20);
	vector<PersonFindIf> vect{ p1, p2, p3, p4, p5, p6 };
	vector<PersonFindIf>::iterator p = find_if(vect.begin(), vect.end(), mySelectFindIf());
	if (p != vect.end()) {
		cout << "�ҵ���Ԫ�أ��±�Ϊ��" << p - vect.begin() << endl;
		cout << p->myName << "\t" << p->myAge << endl;
	}
	else {
		cout << "û�ҵ���" << endl;
	}
}

//void main() {
//	testFindIf();
//}

