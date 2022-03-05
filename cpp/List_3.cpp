/*List��С����
����ԭ�ͣ�
	1.size();//����������Ԫ�صĸ���
	2.empty();//�ж������Ƿ�Ϊ��
	3.resize(num); //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
				 //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	4.resize(num, elem); //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
					   //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
*/

#include<iostream>
#include<list>
using namespace std;

void myPrintList_3(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//����������Ҫ�����ĵ�����
		cout << *pBegin << " ";
	}
	cout << endl;
}


void testList_3(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	myPrintList_3(L1);

	if (L1.empty()){//2.empty();�ж������Ƿ�Ϊ��
		cout << "L1Ϊ��" << endl;
	}
	else{
		cout << "L1��Ϊ��" << endl;
		cout << "L1�Ĵ�СΪ�� " << L1.size() << endl;//1.size();����������Ԫ�صĸ���
	}

	L1.resize(2);//3.resize(elem);����ָ����С
	myPrintList_3(L1);

	L1.resize(10, 5);//4.resize(num, elem);����ָ����С
	myPrintList_3(L1);
}

//void main() {
//	testList_3();
//}