/*stackջ
	һ��*�Ƚ����**(First In Last Out,FILO)�����ݽṹ����ֻ��һ������

���캯����
	stack<T> stk;//stack����ģ����ʵ�֣� stack�����Ĭ�Ϲ�����ʽ
	stack(const stack &stk);//�������캯��

��ֵ������
	stack& operator=(const stack &stk);//���صȺŲ�����

���ݴ�ȡ��
	void push(elem);//��ջ�����Ԫ��
	void pop();//��ջ���Ƴ���һ��Ԫ��
	T top();//����ջ��Ԫ��

��С������
	bool empty();//�ж϶�ջ�Ƿ�Ϊ��
	int size();//����ջ�Ĵ�С

ע�⣺1.���в�֧��������ʣ�ֻ�ܷ��ʶ�ͷ�Ͷ�βԪ��
	  2.��������������stackû�г�Աbegin��end����Ϊջ�Ͷ��в�֧�ֵ����������ܶ�����Ԫ�ؽ��з��ʣ���
*/


#include<iostream>
#include<stack>

using namespace std;


void testStack() {
	stack<int> sta;//Ĭ�Ϲ��촴��ջ
	//��ջ
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);
	sta.push(5);
	while (!sta.empty()) {//�ж�ջ�Ƿ�Ϊ��
		cout << "ջ�ĳ��ȣ�" << sta.size();//ջ�ĳ���size()
		cout << "\tջ��Ԫ��Ϊ:" << sta.top();//����ջ��Ԫ��
		sta.pop();//����ջ��Ԫ��
		cout << "\t���ʲ�������ջ�ĳ��ȣ�" << sta.size() << endl;
	}

	stack<int> sta1(sta);//��������
	sta1 = sta;//��ֵ��"="������

}

//void main() {
//	testStack();
//}