/*vector�������ʹ�С

	1.empty();//�ж������Ƿ�Ϊ��
	2.capacity();//����������
	3.size();//����������Ԫ�صĸ���
	4.max_size();//�����������Դ洢����󳤶�(�ô�ô�)
	5.resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
		//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	6.resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
		//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

*/



#include<iostream>
#include<vector>
using namespace std;

void myPrintVect_3(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testVect_3() {
	vector<int> v1;
	for(int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	myPrintVect_3(v1);

	if (v1.empty()) {//1.empty();//�ж������Ƿ�Ϊ��
		cout << "v1Ϊ��!" << endl;
	}
	else {
		cout << "v1��Ϊ��!" << endl;
		cout << "v1��������" << v1.capacity() << endl;//2.capacity();����������
		cout << "v1�ĳ��ȣ�" << v1.size() << endl;//3.size();����������Ԫ�صĸ���
		cout << "v1��max���ȣ�" << v1.max_size() << endl;//4.max_size();�����������Դ洢����󳤶�(�ô�ô�)
	}

	v1.resize(15);//5.resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
	myPrintVect_3(v1);
	v1.resize(8);//5.resize(int num);//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
	myPrintVect_3(v1);

	v1.resize(15, 5);//6.resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ��
	myPrintVect_3(v1);
	v1.resize(5, 5);//6.resize(int num, elem)//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
	myPrintVect_3(v1);
}

//void main() {
//	testVect_3();
//}