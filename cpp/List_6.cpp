/*List ��ת������
	1.reverse();//��ת����
	2.sort();//��������Ĭ�ϵ���������С����
ע�⣺sort()������������Ĵ�С��ȡ��ͬ�������㷨
*/

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void myPrintList_6(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//����������Ҫ�����ĵ�����
		cout << *pBegin << " ";
	}
	cout << endl;
}

bool myCompareList_6(int a,int b) {//ָ�����򣬴Ӵ�С
	//���򣺾��õ�һ�������ڵڶ�����
	return a>b;
}

void testList_6() {
	list<int> L;
	L.push_back(4);
	L.push_back(3);
	L.push_back(1);
	L.push_back(5); 
	L.push_back(2);
	myPrintList_6(L);

	//1.reverse();//��ת����
	L.reverse();
	myPrintList_6(L);

	//sort(L.begin(), L.end());//���в�֧����ַ��ʵ�������������������sort()��׼�㷨
								//��֧����ַ��ʵ��������������ڲ����ṩһЩ��Ӧ���㷨(��Ա����)
	//2.sort();//��������
	L.sort();//Ĭ�ϵ�������򣬴�С����
	myPrintList_6(L);

	L.sort(myCompareList_6);//ָ�����򣬴Ӵ�С
	myPrintList_6(L);
}

//void main() {
//	testList_6();
//}