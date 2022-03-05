/*List�������������ݽ�����ʽ�洢
	����(list)��һ������洢��Ԫ�Ϸ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
	�������ɣ�������һϵ��**���**���
	������ɣ�һ���Ǵ洢����Ԫ�ص�**������**����һ���Ǵ洢��һ������ַ��**ָ����**
	STL�е�������һ��˫��ѭ������
	��������Ĵ洢��ʽ�������������ڴ�ռ䣬�������list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����**˫�������**

list���ŵ㣺
	1.���ö�̬�洢���䣬��������ڴ��˷Ѻ����
	2.����ִ�в����ɾ������ʮ�ַ��㣬�޸�ָ�뼴�ɣ�����Ҫ�ƶ�����Ԫ��

list��ȱ�㣺
	1.���������ǿռ�(ָ����) �� ʱ�䣨����������ķѽϴ�
	2.List��һ����Ҫ�����ʣ����������ɾ���������������ԭ��list��������ʧЧ������vector�ǲ������ġ�

�ܽ᣺STL��**List��vector���������ʹ�õ�����**��������ȱ��

���캯����
	1.list<T> lst;//Ĭ�Ϲ���
	2.list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
	3.list(n,elem);//���캯����n��elem����������
	4.list(const list &lst);//��������
*/

#include<iostream>
#include<list>
using namespace std;

void myPrintList_1(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//����������Ҫ�����ĵ�����
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testList_1() {
	//1.list<T> lst;//Ĭ�Ϲ���
	list<int> L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_back(4);
	L1.push_back(5);
	myPrintList_1(L1);

	//2.list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
	list<int> L2(L1.begin(),L1.end());
	myPrintList_1(L2);

	//3.list(n,elem);//���캯����n��elem����������
	list<int> L3(10, 3);
	myPrintList_1(L3);

	//4.list(const list &lst);//��������
	list<int> L4(L3);
	myPrintList_1(L4);

	//int a = L4[3];//������֧���������(û����д[]����)��Ҳû��at()����
	list<int>::iterator pBegin = ++L1.begin();
	cout << *pBegin << endl;
	//������֧���������(list������û����д"+"�ź���)��ֻ����pBegin++(list��������д"++"����)���������������
	//cout << *(pBegin+1) << endl;
}

//void main() {
//	testList_1();
//}