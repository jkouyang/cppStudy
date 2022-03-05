/*lock_guard()	unique_guard()	�ֶ������Զ�����

* lock_guard():
	��ԭ���ǣ�����һ���ֲ���lock_guard����lock_guard<mutex> g1(mutex)�����乹�캯���н��м������������������н��н�����
	���յĽ�����ǣ�����������������������Զ��������Ӷ�ʹ��lock_guard()�Ϳ������lock()��unlock()
	ͨ���趨������ʹ��lock_guard�ں��ʵĵط���������ͨ��ʹ��{}������������Χ����ʹ�û�����m�ں��ʵĵط�������
    lock_guradҲ���Դ��������������ڶ�������Ϊadopt_lock��ʶʱ����ʾ���ٹ��캯���в��ٽ��л�������������˴�ʱ��Ҫ��ǰ�ֶ�����

* unique_lock() ���� ��lock_guard()���ܸ���ǿ��ļ�������
    ����֧��lock_guard()��ԭ�й���
    �����ṩ���Լ������񣺼��û�ָ�������ĵط���Ҳ����ָ�������ĵط��������Խ���������Ȩ����ת��
    unique_lock�ĵڶ���������Ϊ��adopt_lock��try_to_lock(����ȥ����)��defer_lock(��ʼ����һ��û�м�����mutex);
    try_to_lock: ����ȥ�������ñ�֤������unlock��״̬,Ȼ���������ܲ��ܻ������������mutx��lock()ȥ�������mutex�������û�������ɹ������������أ���������������
    defer_lock: ��ʼ����һ��û�м�����mutex;

*/


#include <iostream>
#include <windows.h>
#include <thread>
#include<mutex>
#include<stdlib.h>
#include <time.h>
using namespace std;

mutex m_lockguard;
mutex m_uniquelock;

void LockGuardThread_3a(int& a)
{
    lock_guard<mutex> g1(m_lockguard);//�ô�����滻��m.lock()��lock_guard����һ������ʱ���ò���Ϊ����������ʱ������lock_guard�Ĺ��캯������������m
    cout << "proc1�������ڸ�дa" << endl;
    cout << "ԭʼaΪ" << a << endl;
    Sleep(1000);
    a = a + 2;
    cout << "����aΪ" << a << endl;
}//��ʱ����Ҫдm.unlock(),g1�����������ͷţ��Զ�������������������m������

void LockGuardThread_3b(int& a){
    {
        //lock_guradҲ���Դ��������������ڶ�������Ϊadopt_lock��ʶʱ����ʾ���ٹ��캯���в��ٽ��л�������������˴�ʱ��Ҫ��ǰ�ֶ�������
        m_lockguard.lock();
        lock_guard<mutex> g2(m_lockguard, adopt_lock);//�о�ûɶ��
        cout << "proc2�������ڸ�дa" << endl;
        cout << "ԭʼaΪ" << a << endl;
        Sleep(1000);
        a = a + 1;
        cout << "����aΪ" << a << endl;
    }//ͨ��ʹ��{}������������Χ����ʹ��m�ں��ʵĵط�������
    cout << "�������������3" << endl;
    cout << "�������������4" << endl;
    cout << "�������������5" << endl;
}

void UniqueLockThread_3a() {
    unique_lock<mutex> g1(m_uniquelock,defer_lock);//��ʼ����һ��û�м�����mutex
    g1.lock();//�ֶ�������ע�⣬����m.lock();ע�⣬����m.lock();ע�⣬����m.lock()
    cout << "����111111" << endl;
    g1.unlock();
    Sleep(1000);
    g1.lock();
}//���Զ�����


void UniqueLockThread_3b() {
    unique_lock<mutex> g2(m_uniquelock, try_to_lock);//���Լ����������û�������ɹ������������أ��������������
    unique_lock<mutex> g3(move(g2));//����Ȩת�ƣ���ʱ��g3����������m
    cout << "����222222" << endl;
    Sleep(1000);
    g3.unlock();
}//���Զ�����

void testThread_3() {
    int a = 0;
    //�̲߳�Ҫ�ͺ�������
    thread thr1(LockGuardThread_3a, ref(a));//����lock_guard
    thread thr2(LockGuardThread_3b, ref(a));

    thr1.join();//�߳�1��2û�����꣬main()�����������������������
    thr2.join();

    thread thr3(UniqueLockThread_3a);//����lock_guard
    thread thr4(UniqueLockThread_3b);
    thr3.join();
    thr4.join();
}

//void main(){
//    testThread_3();
//}