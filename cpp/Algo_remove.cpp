/*remove()�����޳������ڵ�Ԫ�أ�α�޳�(û�иı����е�size���������õ�Ԫ��)
*
	������ʽ��
		iteator remove(beg, end, value);
		�޳�������ֵΪvalue��Ԫ��

ע�⣺
	�������������޳���ֻ�ǽ�δ�޳���Ԫ�ط���ǰ�棬����Ԫ����ԭ������ͬ��δ���в���
	û�иı����е�size���������õ�Ԫ��
	�����ص�һ������Ԫ�صĵ�����������Ԫ�ص���һλ��
	�������÷���ֵ��resize()ʵ����ֵ���޳�
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testRemove() {
	vector<int> vect{ 4,4,1,4,2,2,3,2,4 };
	cout << "ԭʼ��";
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//iteator remove(beg, end, value);α�޳�������ֵΪvalue��Ԫ��
	vector<int>::iterator p = remove(vect.begin(), vect.end(), 4);
	cout << "�޳���";
	for (int i : vect) { cout << i << " "; }
	cout << endl << "���ص�����λ��,�±꣺" << p - vect.begin() << " Ԫ�أ�" << *p << endl;
	//���÷���ֵ��resize()ʵ����ֵ���޳�
	cout << "resize()ʵ����ֵ���޳�:";
	vect.resize(p - vect.begin());
	for (int i : vect) { cout << i << " "; }
	cout << endl;

}

//void main() {
//	testRemove();
//}
