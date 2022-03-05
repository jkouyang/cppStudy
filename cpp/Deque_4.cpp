/*deque�����ɾ��
���˲���ɾ��������
	1.push_back(elem);//������β�����һ������
	2.push_front(elem);//������ͷ������һ������
	3.pop_back();//ɾ���������һ������
	4.pop_front();//ɾ��������һ������

ָ��λ�ò���ɾ��������
	1.insert(pos,elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ��
	2.insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ
	3.insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
	4.erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
	5.erase(pos); //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
	6.clear();//�����������������
*/


#include<iostream>
#include<deque>
#include<string>
using namespace std;

void myPrintDeque_4(const deque<string>& deq) {//��const�����ô�����������ֻ������Ӧ�ĵ�����ҲҪ��Ϊconst_iterator
	for (deque<string>::const_iterator pBegin = deq.begin(); pBegin != deq.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

//���˲���ɾ������
void testDeque_4a() {
	deque<string> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(to_string(i));
	}
	myPrintDeque_4(deq);
	//1.push_back(elem);//������β�����һ������
	deq.push_back("β��");
	myPrintDeque_4(deq);
	//2.push_front(elem);//������ͷ������һ������
	deq.push_front("ͷ��");
	myPrintDeque_4(deq);
	//3.pop_back();//ɾ���������һ������
	deq.pop_back();
	myPrintDeque_4(deq);
	//4.pop_front();//ɾ��������һ������
	deq.pop_front();
	myPrintDeque_4(deq);
}

//ָ��λ�ò���ɾ������
void testDeque_4b() {
	deque<string> deq;
	for (int i = 0; i < 10; i++) {
		deq.push_back(to_string(i));
	}
	myPrintDeque_4(deq);

	//1.insert(pos, elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ��
	deq.insert(deq.begin()+3, "�м��");//posΪ������
	myPrintDeque_4(deq);
	//2.insert(pos, n, elem);//��posλ�ò���n��elem���ݣ��޷���ֵ
	deq.insert(deq.begin() + 5, 3,"�м��n��");//posΪ������
	myPrintDeque_4(deq);
	//3.insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
	deq.insert(deq.begin(), deq.begin()+5, deq.begin() + 7);//pos, beg, end��Ϊ������
	myPrintDeque_4(deq);
	//4.erase(beg, end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
	deq.erase(deq.begin(), deq.begin() + 5);//beg, end��Ϊ������
	myPrintDeque_4(deq);
	//5.erase(pos); //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
	deq.erase(deq.begin());//pos��Ϊ������
	myPrintDeque_4(deq);
	//6.clear();//�����������������
	deq.clear();
	myPrintDeque_4(deq);
}

//void main() {
//	testDeque_4a();
//	cout << "====================================" << endl;
//	testDeque_4b();
//}