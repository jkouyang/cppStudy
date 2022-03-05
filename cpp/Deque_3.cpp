/*deque��С����
	ע�⣺dequeû������(capacity)�ĸ��ֻ�д�С(size)
			deque�������ڱ������ԣ�����ʱֻ��Ҫ���һ����ַ������Ҫ�����µĿռ䣬����û�������ĸ���
����ģ�ͣ�
	1.deque.empty();//�ж������Ƿ�Ϊ��
	2.deque.size();//����������Ԫ�صĸ���
	3.deque.resize(num);//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ��
						//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	4.deque.resize(num, elem);//����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ�á�
							  //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
*/


#include<iostream>
#include<deque>
using namespace std;

void myPrintDeque_3(const deque<int>& deq) {//��const�����ô�����������ֻ������Ӧ�ĵ�����ҲҪ��Ϊconst_iterator
	for (deque<int>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testDeque_3() {
	deque<int> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(i);
	}
	myPrintDeque_3(deq);
	if (deq.empty()) {//1.deque.empty();//�ж������Ƿ�Ϊ��
		cout << "deqΪ��" << endl;
	}
	else {
		cout << "deq��Ϊ��" << endl;
		cout << "deq�Ĵ�С��" << deq.size() << endl;//2.deque.size();//����������Ԫ�صĸ���
	}

	//����ָ������
	deq.resize(15);//3.deque.resize(num);
	deq.resize(20, 1);//4.deque.resize(num, elem);
}

//void main() {
//	testDeque_3();
//}