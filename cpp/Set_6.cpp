/*set��������
**ʾ��һ**   set���������������

	set����Ĭ���������Ϊ��С����������θı��������
	���÷º��������Ըı��������
*/

#include<iostream>
#include<set>
using namespace std;

class myCompareSet_6 {//���÷º��������ƶ��������
public:
	bool operator()(int v1, int v2) const {//vs2019Ҫ�ں����const,������
		//���򣬵�һ�������ڵڶ�����
		return v1 > v2;
	}
};

void testSet_6() {
	set<int> s1;

	s1.insert(10);
	s1.insert(60);
	s1.insert(20);
	s1.insert(40);
	s1.insert(50);
	s1.insert(30);
	//Ĭ�ϴ�С����
	for (set<int>::const_iterator pBegin = s1.begin(); pBegin != s1.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;

	set<int,myCompareSet_6> s2;
	s2.insert(10);
	s2.insert(60);
	s2.insert(20);
	s2.insert(40);
	s2.insert(50);
	s2.insert(30);
	for (set<int, myCompareSet_6>::const_iterator pBegin = s2.begin(); pBegin != s2.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

//void main() {
//	testSet_6();
//}