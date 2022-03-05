/*Map��С�ͽ���
����ԭ�ͣ�
	1.size();//����������Ԫ�ص���Ŀ
	2.empty();//�ж������Ƿ�Ϊ��
	3.swap(st);//����������������

*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

void myPrintMap_2(map<int, int>& m) {
	for (map<int, int>::iterator pBegin = m.begin(); pBegin != m.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
}

void testMap_2a() {
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	if (m.empty()){//2.empty();//�ж������Ƿ�Ϊ��
		cout << "mΪ��" << endl;
	}
	else{
		cout << "m��Ϊ��" << endl;//1.size();//����������Ԫ�ص���Ŀ
		cout << "m�Ĵ�СΪ�� " << m.size() << endl;
	}
}

void testMap_2b() {
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));

	cout << "����ǰ" << endl;
	myPrintMap_2(m1);
	myPrintMap_2(m2);

	cout << "������" << endl;
	m1.swap(m2);//3.swap(st);//����������������
	myPrintMap_2(m1);
	myPrintMap_2(m2);
}

//void main() {
//	testMap_2a();
//	cout << "=========================" << endl;
//	testMap_2b();
//}