/*remove_if()�����޳�����������������Ԫ�أ�α�޳�(û�иı����е�size���������õ�Ԫ��)
*
	������ʽ��
		iteator remove(beg, end, value, _Pred);
		�޳�����������������Ԫ��

ע�⣺
	�������������޳���ֻ�ǽ���ȷ��Ԫ�ط���ǰ�棬����Ԫ����ԭ������ͬ��δ���в���
	û�иı����е�size���������õ�Ԫ��
	�����ص�һ������Ԫ�صĵ����������õ���һλ��
	�������÷���ֵ��resize()ʵ����ֵ���޳�
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myRemoveIf {
public:
	bool operator()(int val) {
		return val >= 3;//�Ƴ�����3��Ԫ��
	}
};

void testRemoveIf() {
	vector<int> vect{ 4,4,1,4,2,2,3,2,4 };
	cout << "ԭʼ��";
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//iteator remove_if(beg, end, _Pred);α�޳�����������������Ԫ��
	vector<int>::iterator p = remove_if(vect.begin(), vect.end(), myRemoveIf());
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
//	testRemoveIf();
//}
