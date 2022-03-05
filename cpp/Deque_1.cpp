/*deque���� + deque���캯��
	˫�����飬���Զ�ͷ�˽��в���ɾ��������deque�����ĵ�����Ҳ��֧��������ʵ�
	
deque��vector����
	1.vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
	2.deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻر�vector��
	3.vector����Ԫ��ʱ���ٶȻ��deque��,��������ڲ�ʵ���й�

deque�ڲ�����ԭ��:
	1.deque�ڲ��и�**�п���**��ά��ÿ�λ������е����ݣ��������д����ʵ����
	2.�п���ά������ÿ���������ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�

deque�������캯����
	1.deque<��������> deq;//Ĭ�Ϲ�����ʽ
	2.deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
	3.deque(n, elem);//���캯����n��elem����������
	4.deque(const deque &deq);//�������캯��
*/

#include<iostream>
#include<deque>
using namespace std;

void myPrintDeque_1(const deque<int> &deq) {//��const�����ô�����������ֻ������Ӧ�ĵ�����ҲҪ��Ϊconst_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testDeque_1() {
	//1.Ĭ�Ϲ���  �޲ι���
	deque<int> deq1;
	for (int i = 0; i < 10; i++) {
		deq1.push_back(i);
	}
	myPrintDeque_1(deq1);

	//2.���캯����[beg, end)�����е�Ԫ�ؿ���������
	deque<int> deq2(deq1.begin(), deq1.end());
	myPrintDeque_1(deq2);

	//3.deque(n, elem);//���캯����n��elem����������
	deque<int> deq3(10, 3);
	myPrintDeque_1(deq3);

	//4.deque(const deque &deq);//�������캯��
	deque<int> deq4(deq3);
	myPrintDeque_1(deq4);
}

//void main() {
//	testDeque_1();
//}