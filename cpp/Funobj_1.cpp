/*��������
���
	���غ������ò�����()���࣬����󳣳�Ϊ**��������**
	��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ��**�º���**

���ʣ�
	��������(�º���)��һ��**��**������һ������

��������ʹ��
�ص㣺
	1.����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
	2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
	3.�������������Ϊ��������

*/

#include<iostream>
#include<string>
using namespace std;

//1.����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
class myAddFunobj_1 {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

void testFunobj_1a() {
	myAddFunobj_1 myadd;
	cout << myadd(10, 10) << endl;//�ȴ��������ٵ���
	cout << myAddFunobj_1()(10, 10) << endl;//�������������

}

//2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
class myPrintFunobj_1 {
public:
	int count;//��¼״̬
	myPrintFunobj_1() {
		count = 0;
	}
	void operator()(string str) {
		cout << str << endl;
		count++;//ͳ��ʹ�õĴ���
	}

};

void testFunobj_1b() {
	myPrintFunobj_1 myprint;
	myprint("Hello!");//�ȴ��������ٵ���
	myprint("Hello!");//�ȴ��������ٵ���
	myprint("Hello!");//�ȴ��������ٵ���
	myprint("Hello!");//�ȴ��������ٵ���
	myPrintFunobj_1()("Hello!");//�������������
	//��������ÿ�ε�����֮�󶼻ᱻ���٣����ƴ���
	cout << "myprint()���õĴ�����" << myprint.count << endl;
	cout << "��������myprint()���õĴ�����" << myPrintFunobj_1().count << endl;
}


//3.�������������Ϊ�������ݣ�����ͨ����Ҳ���Խ��в�������ѽ����֪����һ����ʲô����
void  doPrintFunobj_1(myPrintFunobj_1& myprint, string str) {
	myprint(str);
}
void testFunobj_1c() {
	myPrintFunobj_1 myprint;
	doPrintFunobj_1(myprint, "��ã�");
}


//void main() {
//	//testFunobj_1a();
//	//testFunobj_1b();
//	testFunobj_1c();
//}