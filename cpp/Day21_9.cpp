/*��ģ����̳�

����ģ�������̳�ʱ����Ҫע��һ�¼��㣺
	1.������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
	2.�����ָ�����������޷�����������ڴ�
	3.��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��

��ģ���г�Ա��������ʵ��ʱ����Ҫ����ģ������б�
*/

#include<iostream>
using namespace std;

template<class T>
class Base_21_9 {
public:
	T age;
	Base_21_9() {
		cout << "����T���������ͣ�" << typeid(T).name() << endl;
	}
};

//class Son_21_9 :public Base_21_9//���������ָ�����������޷�����������ڴ�
class Son_21_9a :public Base_21_9<int> {//1.����Ҫ֪�������е�T���ͣ����ܼ̳и�����
public:
	Son_21_9a() {
		cout << "1.����Ҫ֪�������е�T���ͣ����ܼ̳и�����" << endl;
	}
};

//3.��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
template<class T1, class T2>
class Son_21_9b :public Base_21_9<T1> {//1.����Ҫ֪�������е�T���ͣ����ܼ̳и�����
public:
	T2 var;
	Son_21_9b();
	void sayChar(T1 a);	
};

template<class T1, class T2>//��ģ�幹�캯��������ʵ�֣���Ҫ����ģ��ȫ�������б�
Son_21_9b<T1,T2>::Son_21_9b(){
	cout << "3.��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��" << endl;
	cout << "����T1���������ͣ�" << typeid(T1).name() << endl;
	cout << "����T2���������ͣ�" << typeid(T2).name() << endl;
}

template<class T1, class T2>//��ģ����ͨ��Ա����������ʵ�֣���Ҫ����ģ��ȫ�������б�
void Son_21_9b<T1, T2>::sayChar(T1 a) {
	cout << "��ģ���Ա�������ⶨ�壬sayChar��" << a << endl;
}

void test_21_9() {
	Son_21_9a obj1;
	Son_21_9b<char, int> obj2;
	obj2.sayChar('a');
}

//void main() {
//	test_21_9();
//	system("pause");
//}