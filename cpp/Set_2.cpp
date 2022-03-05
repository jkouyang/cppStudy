/*Set�����Ĵ�С�ͽ���

����ԭ�ͣ�
	1.size();//����������Ԫ�ص���Ŀ
	2.empty();//�ж������Ƿ�Ϊ��
	3.swap(st);//����������������
*/

#include<iostream>
#include<set>
using namespace std;

void myPrintSet_2(const set<int>& s) {
	for (set<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testSet_2a() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	if (s1.empty()){
		cout << "s1Ϊ��" << endl; //2.empty();//�ж������Ƿ�Ϊ��
	}
	else{
		cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ�� " << s1.size() << endl;//1.size();//����������Ԫ�ص���Ŀ
	}
}

void testSet_2b() {
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "����ǰ" << endl;
	myPrintSet_2(s1);
	myPrintSet_2(s2);
	cout << endl;

	cout << "������" << endl;
	s1.swap(s2);
	myPrintSet_2(s1);
	myPrintSet_2(s2);
}

//void main() {
//	testSet_2a();
//	cout << "================================" << endl;
//	testSet_2b();
//}