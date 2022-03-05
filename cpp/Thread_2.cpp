/*���������������		mutex m;ʵ����mmutex����

* ����Sleep(int m);ģ��io��ʱ��
	����mΪ���룬1000ms=1s;������Ҫ����#include <windows.h>

* ��
	mutex m;ʵ����mmutex����
	m.lock();//m��������
	m.unlock();//m�������
	//�����Դ��������1�����Զ���һ��ȫ�ֱ���flag��û����һ��falg-1����flag=0ʱ����
*/

#include <iostream>
#include <windows.h>
#include <thread>
#include<mutex>
#include<stdlib.h>
#include <time.h>
using namespace std;

mutex wThread_2;//д(�ٽ���Դ),ʵ����mutex����wThread_2��һ��mutex���͵Ķ��󣬿ɵ������ڲ���Ա����lock();unlock();
mutex cpuThread_2;//cpu(�ٽ���Դ),ʵ����mutex����

static int aThread_2 = 10;
static int bThread_2 = 20;

int readThread_2(int& p) {
	return p;
}

void writeThread_2(int temp, int& b) {
	string str;
	if (b == aThread_2) { str = "A"; }
	else { str = "B"; }
	wThread_2.lock();//д����
	cout << str + "����д��..." << endl;
	Sleep(rand() % 1000 + 500);//���ߣ�ģ�´���д��
	b = temp;
	cout << str + "д����ɣ�" << endl;
	wThread_2.unlock();//д����
}

int calTheread_2(int a) {
	string str;
	if (a == aThread_2) { str = "A"; }
	else { str = "B"; }
	cpuThread_2.lock();//cpu����
	cout << str + "���ڼ���..." << endl;
	Sleep(rand() % 1000 + 500);//���ߣ�ģ��cpu����
	cout << str + "������ɣ�" << endl;
	cpuThread_2.unlock();//cpu����
	return a*a;
}

void func1Thread_2() {
	srand((unsigned)time(NULL));
	int& p = aThread_2;//���̵�ַ
	int a = readThread_2(p);//��ȡ��������
	int temp = calTheread_2(a);//����
	writeThread_2(temp, p);//����
}

void func2Thread_2() {
	int& p = bThread_2;//���̵�ַ
	int b = readThread_2(p);//��ȡ��������
	int temp = calTheread_2(b);//����
	writeThread_2(temp, p);//����
}

//����cpuֻ��һ����(ͬʱֻ�ܼ���һ��)�����̶��ǹ�������д�ǻ����
//�����Դ��������1�����Զ���һ��ȫ�ֱ���flag��û����һ��falg-1����flag=0ʱ����
void testThread() {
	cout << "A = " << aThread_2 << endl;
	cout << "B = " << bThread_2 << endl;
	thread thr1(func1Thread_2);//�߳�1
	thread thr2(func2Thread_2);//�߳�2
	//�߳�1��2�����߳�main��ʵ��ͬ���ģ�Ҳ����˵������߳�1��2���Ի�û��ɣ�main�ͻ����������
	cout << "A = " << aThread_2 << endl;//�߳�1��2���Ի�û��ɣ���ʱֵ��δ��
	cout << "B = " << bThread_2 << endl;
	thr1.join();
	thr2.join();
	cout << "A = " << aThread_2 << endl;
	cout << "B = " << bThread_2 << endl;
}

//void main() {
//	testThread();
//}