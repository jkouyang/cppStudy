/*List ��ֵ�ͽ���

����ԭ�ͣ�
	1.assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	2.assign(n, elem);//��n��elem������ֵ������
	3.list& operator=(const list &lst);//���صȺŲ�����
	4.swap(lst);//��lst�뱾���Ԫ�ػ���
*/


#include<iostream>
#include<list>
using namespace std;

void myPrintList_2(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//����������Ҫ�����ĵ�����
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testList_2a(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	myPrintList_2(L1);

	//3.list& operator=(const list & lst);//���صȺŲ�����
	list<int> L2;
	L2 = L1;
	myPrintList_2(L2);
	//1.assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	list<int> L3;
	L3.assign(L2.begin(), L2.end());
	myPrintList_2(L3);
	//2.assign(n, elem);//��n��elem������ֵ������
	list<int> L4;
	L4.assign(10, 100);
	myPrintList_2(L4);
}

void testList_2b(){

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);

	cout << "����ǰ�� " << endl;
	myPrintList_2(L1);
	myPrintList_2(L2);

	L1.swap(L2);
	cout << "������ " << endl;
	myPrintList_2(L1);
	myPrintList_2(L2);

}

//void main() {
//	testList_2a();
//	cout<<"=====================================" << endl;
//	testList_2b();
//}