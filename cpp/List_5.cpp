/*List ���ݴ�ȡ
����ԭ�ͣ�
	1.front();//���ص�һ��Ԫ�ص�����
	2.back();//�������һ��Ԫ�ص�����

ע�⣺list�����в�����ͨ��[]����at��ʽ��������
*/

#include<iostream>
#include<list>
using namespace std;

void myPrintList_5(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//����������Ҫ�����ĵ�����
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testList_5() {
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//cout << L1.at(0) << endl;//���� ��֧��at��������
	//cout << L1[0] << endl; //����  ��֧��[]��ʽ��������
	
	//1.front();//���ص�һ��Ԫ�ص�����
	int& a = L1.front();
	cout << "��һ��Ԫ��Ϊ�� " << a << endl;
	a = 17;
	cout << "��һ��Ԫ��Ϊ�� " << L1.front() << endl;//��Ϊ���ص�������(ָ��)�����Կ��Ա��޸�

	//2.back();//�������һ��Ԫ�ص�����
	cout << "���һ��Ԫ��Ϊ�� " << L1.back() << endl;

	//list�����ĵ�������˫�����������֧���������
	list<int>::iterator pBegin = L1.begin();
	//pBegin = pBegin + 1;//���󣬲�������Ծ���ʣ���ʹ��+1
	//pBegin++;//��ȷ��++���ź���������
}

//void main() {
//	testList_5();
//}