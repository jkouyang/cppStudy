/*set��multiset����
����
	1.set�����Բ����ظ����ݣ���multiset����
	2.set�������ݵ�ͬʱ�᷵����������������λ�õĵ������Ͳ����Ƿ�ɹ�(bool��)���ɶԷ���pair
	3.multiset���������ݣ���˿��Բ����ظ����ݣ�����ʱֻ���ص�����(ָ��������ݵ�λ��)
*/


#include<iostream>
#include<set>
using namespace std;

void myPrintSet_5(const set<int>& s) {
	for (set<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void myPrintMultiset_5(const multiset<int>& s) {
	for (multiset<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testSet_5a() {
	set<int> s;
	pair<set<int>::iterator, bool> ret1 = s.insert(10);//��һ�β���10
	pair<set<int>::iterator, bool> ret2 = s.insert(10);//�ڶ��β���10
	if (ret1.second) {
		cout << "��һ�β���10����ɹ�" << endl;
		cout << "*ret1.first=" << *ret1.first << endl;//��Ȼret1.first�Ǽ�¼���ݲ����λ�õ�����
	}
	else {
		cout << "��һ�β���10����ʧ��" << endl;
	}
	if (ret2.second) {
		cout << "�ڶ��β���10����ɹ�" << endl;
	}
	else {
		cout << "�ڶ��β���10����ʧ��" << endl;
		cout << "*ret2.first=" << *ret2.first << endl;//��Ȼ*ret2.first��Ȼ��¼�˵����ݣ���ʵ�ʲ�û�в���
	}
}

void testSet_5b() {
	multiset<int> ms;
	//multiset���Բ����ظ�ֵ
	multiset<int>::iterator ret1 = ms.insert(10);//��һ�β���10
	multiset<int>::iterator ret2 = ms.insert(10);//�ڶ��β���10
	myPrintMultiset_5(ms);

	cout << "*ret1=" << *ret1 << endl;
	cout << "*ret2=" << *ret2 << endl;

	if (ret1 == ret2) {
		cout << "ret1����ret2" << endl;
	}
	else {
		cout << "ret1������ret2" << endl;
	}

}

//void main() {
//	testSet_5a();
//	cout << "================================" << endl;
//	testSet_5b();
//}