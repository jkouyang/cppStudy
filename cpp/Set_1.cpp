/*Set������������Ԫ�ض����ڲ���ʱ�Զ�������
���ʡ���set/multiset����**����ʽ����**���ײ�ṹ����**������**ʵ��

set��multiset����
	set���������������ظ���Ԫ��
	multiset�������������ظ���Ԫ��

���캯����
	1.set<T> st;//Ĭ�Ϲ��캯����
	2.set(const set &st);//�������캯��

��ֵ��
	set& operator=(const set &st);//���صȺŲ�����

*/

#include<iostream>
#include<set>
using namespace std;

void myPrintSet_1(const set<int>& s) {
	for (set<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void myPrintMultiset_1(const multiset<int>& s) {
	for (multiset<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testSet_1() {
	//1.set<T> st;//Ĭ�Ϲ��캯����
	set<int> s1;

	//�������� ֻ��insert()��ʽ
	s1.insert(4);
	s1.insert(2);
	s1.insert(3);
	s1.insert(5);
	s1.insert(1);
	myPrintSet_1(s1);//����Ԫ�ض����ڲ���ʱ�Զ�������
	cout << "set�����ĳ��ȣ�" << s1.size() << endl;

	s1.insert(1);
	s1.insert(1);
	s1.insert(1);
	myPrintSet_1(s1);//set���������������ظ���Ԫ�أ��������ʱ�򲻻ᱨ����Ч����
	cout << "set�����ĳ��ȣ�" << s1.size() << endl;

	//2.set(const set & st);//�������캯��
	set<int> s2(s1);

	multiset<int> s3;
	s3.insert(3);
	s3.insert(2);
	s3.insert(1);
	s3.insert(1);
	s3.insert(2);
	myPrintMultiset_1(s3);//multiset�������������ظ���Ԫ��
	cout << "multiset�����ĳ��ȣ�" << s1.size() << endl;

}

//void main() {
//	testSet_1();
//}