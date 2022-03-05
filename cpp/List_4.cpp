/*List �����ɾ��

����ԭ�ͣ�
	1.push_back(elem);//������β������һ��Ԫ��
	2.pop_back();//ɾ�����������һ��Ԫ��
	3.push_front(elem);//��������ͷ����һ��Ԫ��
	4.pop_front();//��������ͷ�Ƴ���һ��Ԫ��
	5.insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ��
	6.insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ
	7.insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
	8.erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
	9.erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
	10.remove(elem);//ɾ��������������elemֵƥ���Ԫ��
	11.clear();//�Ƴ���������������
*/

#include<iostream>
#include<list>
using namespace std;

void myPrintList_4(const list<int>& L) {
	for (list<int>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {//����������Ҫ�����ĵ�����
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testList_4() {
	list<int> L;
	//1.push_back(elem);β��
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//3.push_front(elem);ͷ��
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	myPrintList_4(L);

	//2.pop_back();βɾ
	L.pop_back();
	myPrintList_4(L);
	//4.pop_front();ͷɾ
	L.pop_front();
	myPrintList_4(L);

	//5.insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ��
	list<int>::iterator pBegin = L.begin();
	list<int>::iterator p1 = L.insert(++++pBegin, 99);//����һ�����ݲ����������ݵ�λ��
	myPrintList_4(L);

	//8.erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
	list<int>::iterator p2 =L.erase(p1);
	myPrintList_4(L);

	//6.insert(pos, n, elem);//��posλ�ò���n��elem���ݣ��޷���ֵ
	L.insert(p2, 5, 77);
	myPrintList_4(L);
	//7.insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
	L.insert(p2, L.begin(), ++++L.begin());
	myPrintList_4(L);

	//9.erase(beg, end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
	L.erase(L.begin(), ++++L.begin());
	myPrintList_4(L);

	//10.remove(elem);//ɾ��������������elemֵƥ���Ԫ��
	L.remove(77);
	myPrintList_4(L);

	//11.clear();//�Ƴ���������������
	L.clear();
	myPrintList_4(L);
}

//void main() {
//	testList_4();
//}