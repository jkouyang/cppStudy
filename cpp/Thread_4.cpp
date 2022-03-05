/* �첽�߳�	async	future

* async��future��
	async��һ������ģ�壬��������һ���첽�̣߳�������һ��future��ģ�����
	future��������ռλ�����ã��մ���ʵ����ʱ��future��û�д���ֵ�ģ�
	���ڵ���future�����get()��Ա����ʱ�����̻߳ᱻ����ֱ���첽�߳�ִ�н��������ѷ��ؽ�����ݸ�future����ͨ��FutureObject.get()��ȡ��������ֵ

* �﷨��future<T> obj = async(funcPtr, ����1, ����2, ...);
	TΪ����ָ��ָ�����ķ���ֵ���ͣ�����1��2...Ϊ������Ӧ�Ĳ���
	���պ����ķ���ֵ�洢��obj�У�����obj.get()���ã���ֻ�ܵ���һ��

*shared_future ����	���obj.get()ֻ�ܵ���һ�ε�����
	future��get()��Ա������ת����������Ȩ;shared_future��get()��Ա�����Ǹ������ݡ�
	future�����get()ֻ�ܵ���һ�Σ��޷�ʵ�ֶ���̵߳ȴ�ͬһ���첽�̣߳�һ������һ���̻߳�ȡ���첽�̵߳ķ���ֵ�������߳̾��޷��ٴλ�ȡ
	shared_future�����get()���Ե��ö�Σ�����ʵ�ֶ���̵߳ȴ�ͬһ���첽�̣߳�ÿ���̶߳����Ի�ȡ�첽�̵߳ķ���ֵ

*/

#include<iostream>
#include<thread>
#include <windows.h>
#include<future>
using namespace std;

double futureThread_4(double a,double b) {
	Sleep(3000);
	return a + b;
}

void testThread_4() {
	future<double> fu = async(futureThread_4, 3.14, 6.28);//�����첽�߳��̣߳������̵߳�ִ�н����fuռλ��
	shared_future<double> sharedfu = async(futureThread_4, 3.14, 6.28);//�����첽�߳��̣߳������̵߳�ִ�н����fuռλ��
	//���߳̿��Լ��������ߣ�ֱ������get()ʱ����
	cout << "�ȸɵ������飡" << endl;
	cout << "�ȸɵ������飡" << endl;
	cout << "�ȸɵ������飡" << endl;
	cout << "�ȸɵ������飡" << endl;

	cout << "�ȴ����ؽ��fu.get()��" << fu.get() << endl;//����������ȴ����
	cout << "�ȴ����ؽ��sharedfu.get()��" << sharedfu.get() << endl;//����������ȴ����
	try {cout << "��һ�η��ؽ����" << fu.get() << endl;}
	catch(...){cout << "future.get()���ܵ�������" << endl; }//future.get()���ܵ�������

	cout << "�ٴη��ؽ��sharedfu.get()��" << sharedfu.get() << endl;//sharedfu.get()���Զ�ε���
	cout << "�ٴη��ؽ��sharedfu.get()��" << sharedfu.get() << endl;

}

//void main() {
//	testThread_4();
//}
