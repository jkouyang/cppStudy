/*deque��ֵ����
	1.deque& operator=(const deque &deq);//���صȺŲ�����
	2.assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	3.assign(n, elem);//��n��elem������ֵ������
*/


#include<iostream>
#include<deque>
using namespace std;

void myPrintDeque_2(const deque<int>& deq) {//��const�����ô�����������ֻ������Ӧ�ĵ�����ҲҪ��Ϊconst_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}


void testDeque_2() {
	deque<int> deq1;
	for (int i = 0; i < 10; i++) {
		deq1.push_back(i);
	}
	myPrintDeque_2(deq1);

	//��ֵ����
	//1.deque & operator=(const deque & deq);//���صȺŲ�����
	deque<int> deq2;
	deq2 = deq1;
	myPrintDeque_2(deq2);

	//2.assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
	deque<int> deq3;
	deq3.assign(deq1.begin(), deq1.end());
	myPrintDeque_2(deq3);


	//3.assign(n, elem);//��n��elem������ֵ������
	deque<int> deq4;
	deq4.assign(10, 3);
	myPrintDeque_2(deq4);
}

//void main() {
//	testDeque_2();
//}