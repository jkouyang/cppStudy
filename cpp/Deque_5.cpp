/*deque�����Ĵ�ȡ(��д)
����ԭ�ͣ�
	1.at(int idx);//��������idx��ָ������
	2.operator[];//��������idx��ָ������
	3.front();//���������е�һ������Ԫ��
	4.back();//�������������һ������Ԫ��
*/

#include<iostream>
#include<deque>
using namespace std;

void myPrintDeque_5(const deque<int>& deq) {//��const�����ô�����������ֻ������Ӧ�ĵ�����ҲҪ��Ϊconst_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void tetsDeque_5() {
	deque<int> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(i);
	}
	myPrintDeque_5(deq);

	//1.at(int idx);//��������idx��ָ������
	cout << "deq.at(5)=" << deq.at(5) << endl;

	//2.operator[];//��������idx��ָ������
	cout << "deq[5]=" << deq[5] << endl;

	//3.front();//���������е�һ������Ԫ��
	cout << "deq.front()=" << deq.front() << endl;

	//4.back();//�������������һ������Ԫ��
	cout << "deq.back()=" << deq.back() << endl;

}

//void main() {
//	tetsDeque_5();
//}