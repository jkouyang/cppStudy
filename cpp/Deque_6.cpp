/*deque���򡪡������㷨ʵ�ֶ�deque������������

	sort(iterator beg, iterator end)//��beg��end������Ԫ�ؽ�������

*/

#include<iostream>
#include<deque>
#include<string>
#include<algorithm>//�����㷨ͷ�ļ�
using namespace std;

void myPrintDeque_6(const deque<string>& deq) {//��const�����ô�����������ֻ������Ӧ�ĵ�����ҲҪ��Ϊconst_iterator
	for (deque<string>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}


void tetsDeque_6() {
	deque<string> deq;
	deq.push_back(to_string(3));
	deq.push_back(to_string(9));
	deq.push_back(to_string(812));
	deq.push_back(to_string(5));
	deq.push_front(to_string(123));
	deq.push_front(to_string(785));
	deq.push_front(to_string(6));
	deq.push_front(to_string(7));
	myPrintDeque_6(deq);

	//����֧��������ʵ�����������ʹ��sort()��������
	//���Ӻ��ַ�������������sort()�����ַ�����ASSCI������
	sort(deq.begin(), deq.end());//�Զ����������ʱ��ֻ�ô������������ü�()������
	myPrintDeque_6(deq);
}
//void main() {
//	tetsDeque_6();
//}
