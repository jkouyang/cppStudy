/*unique()�����޳�������ͬ��Ԫ�أ�α�޳�(û�иı����е�size���������õ�Ԫ��)
*
	������ʽ��
		1.iterator unique(beg, end);
		�޳�������ͬ��Ԫ��
		����2��Ĭ��_Pred=equal<T>()

		2.iterator unique(beg, end, _Pred);
		�޳�������ͬ��Ԫ��
		�Զ���_Pred�����Զ�������������ȵĹ���
		���ã���ֻ�������ݣ�����==����equal<T>()����

ע�⣺
	������ͬ��Ԫ�أ��������ظ����ֵ�Ԫ��
	�������������޳���ֻ�ǽ����������Ԫ�ط���ǰ�棬����Ԫ����ԭ������ͬ��δ���в���
	û�иı����е�size���������õ�Ԫ��
	�����ص�һ������Ԫ�صĵ����������õ���һλ��
	�������÷���ֵ��resize()ʵ����ֵ���޳�
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myUnique {
public:
	bool operator()(int a, int b) {
		return a == b + 1;
	}
};


void testUnique() {
	vector<int> vect{ 4,4,1,4,2,2,3,2,4,5 };
	cout << "ԭʼ��";
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//1.iterator unique(beg, end);
	//�޳�������ͬ��Ԫ��
	vector<int>::iterator p1 = unique(vect.begin(), vect.end());
	cout << "�޳���";
	for (int i : vect) { cout << i << " "; }
	cout << endl << "���ص�����λ��,�±꣺" << p1 - vect.begin() << " Ԫ�أ�" << *p1 << endl;
	//���÷���ֵ��resize()ʵ����ֵ���޳�
	cout << "resize()ʵ����ֵ���޳�:";
	vect.resize(p1 - vect.begin());
	for (int i : vect) { cout << i << " "; }
	cout << endl;


	//2.iterator unique(beg, end, _Pred);
	//�Զ���_Pred�����Զ�������������ȵĹ���
	vector<int>::iterator p2 = unique(vect.begin(), vect.end(), myUnique());
	cout << "�޳���";
	for (int i : vect) { cout << i << " "; }
	cout << endl << "���ص�����λ��,�±꣺" << p2 - vect.begin() << " Ԫ�أ�" << *p2 << endl;

}

//void main() {
//	testUnique();
//}
