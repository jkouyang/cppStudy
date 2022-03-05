/*heap
	�Ѳ�����STL����������Ǿ����䵱�ŵײ�ʵ�ֽṹ���������ȼ����У�Priority Queue���ȵ�
	����һ����ȫ��������������ǿ���������(������)���洢���нڵ�

* ������ʽ
	1.void make_heap(beg,end)//Ĭ�Ϲ���󶥶ѣ�_Pred=less<T>
	  void make_heap(beg,end,_Pred)//���Զ���_Pred

	2.void push_heap(beg,end)//��Ԫ�صļ��벻����ѵ����ʣ�����ʹ������������ѵ��ص�
	  void push_heap(beg,end,_Pred)

	3.void pop_heap(beg,end)//�ӶѶ�����һ��Ԫ��(�߼���)
	  void pop_heap(beg,end,_Pred)

	4.void sort_heap(beg,end)//������
	  void pop_heap(beg,end,_Pred)
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testHeap() {
	//����һ������
	cout << "����һ������" << endl;
	vector<int> vect{ 5,7,1,3,6,4,8,2,9 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//����������Ϊ��
	//1.make_heap()
	cout << "����������Ϊ��" << endl;
	make_heap(vect.begin(), vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//���(����)����һ�����ݣ����������
	cout << "���(����)����һ�����ݣ����������" << endl;
	vect.push_back(0);
	for (int i : vect) { cout << i << " "; }
	cout << endl;
	
	//��Ԫ�صļ��벻����ѵ����ʣ�����ʹ������������ѵ��ص�
	//2.push_heap()
	cout << "����ʹ������������ѵ��ص�" << endl;
	push_heap(vect.begin(), vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//3.pop_heap() �ӶѶ�����һ��Ԫ��
	//ֻ���ڶѵ��߼��ϵ���һ���Ѷ�Ԫ�أ���������������ϲ�û��ɾ���������������
	//���resize()����ʵ��������ɾ��
	cout << "�ӶѶ�����һ��Ԫ��(�߼���)" << endl;
	pop_heap(vect.begin(), vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
	cout << "�ӶѶ�����һ��Ԫ��(������)" << endl;
	vect.resize(vect.size() - 1);
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//4.sort_heap()��������
	//ִ�к������е�Ԫ��ʵ�����򣬶�Ӧ�Ķѵ�Ҫ��Ҳ����
	cout << "������" << endl;
	sort_heap(vect.begin(), vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testHeap();
//}