/*��ģ��
��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�
	1.��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
	2.��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���

*/

#include<iostream>
#include<string>
using namespace std;

class Person_21_7a{
public:
	void showPerson1(){
		cout << "Person1 show" << endl;
	}
};

class Person_21_7b{
public:
	void showPerson2(){
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass_21_7{
public:
	T obj;
	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }
};

void test_21_7(){
	MyClass_21_7<Person_21_7a> m;
	m.fun1();
	//m.fun2();//��������˵���������òŻ�ȥ������Ա����
}

//int main() {
//	test_21_7();
//	system("pause");
//	return 0;
//}


