/*queue����
	һ��**�Ƚ��ȳ�**(First In First Out,FIFO)�����ݽṹ��������������

���캯����
	queue<T> que;//queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ
	queue(const queue &que);//�������캯��

��ֵ������
	queue& operator=(const queue &que);//���صȺŲ�����

���ݴ�ȡ��
	void push(elem);//����β���Ԫ��
	void pop();//�Ӷ�ͷ�Ƴ���һ��Ԫ��
	T back();//���ʶ�βԪ��
	T front();//���ʶ�ͷԪ��

��С������
	bool empty();//�ж϶�ջ�Ƿ�Ϊ��
	int size();//����ջ�Ĵ�С

ע�⣺1.���в�֧��������ʣ�ֻ�ܷ��ʶ�ͷ�Ͷ�βԪ��
	  2.������������������queueû�г�Աbegin��end����Ϊջ�Ͷ��в�֧�ֵ����������ܶ�����Ԫ�ؽ��з��ʣ���

��Щ����������漰�����ι��죬�����Ƕ���ĳ�ʼ�����죬�����ڲ����ʱ��Ḵ��һ�Σ��ᴥ���������졣
���Ǻܶ�ʱ�����ǲ�����Ҫ���ι������Ч�ʵ��˷ѣ���������ڲ����ʱ��ֱ�ӹ��죬��ֻ��Ҫ����һ�ξ͹��ˡ�
C++11��׼�Ѿ����������﷨����ֱ��ʹ���ˣ��Ǿ���emplace()
*/

#include<iostream>
#include<string>
#include<queue>
using namespace std;

void testQueue() {
	queue<string> que;
	//���
	que.push("��ɮ");
	que.push("�����");
	que.push("��˽�");
	que.push("ɳɮ");
	que.push("������");
	que.emplace("�׹Ǿ�");
	

	while (!que.empty()) {
		cout << "���еĳ��ȣ�" << que.size();
		cout << "\t��ͷ��Ԫ�أ�" << que.front();//���ʶ�ͷԪ��
		cout << "\t��β��Ԫ�أ�" << que.back();//���ʶ�βԪ��
		que.pop();//����
		cout << "\t���Ӻ���еĳ��ȣ�" << que.size() << endl;//���еĳ���
	}

	queue<string> que1(que);//��������
	que1 = que;//��ֵ��"="������
}


//void main() {
//	testQueue();
//}