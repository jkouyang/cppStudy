/*
�����
	1.srand((unsigned)time(NULL))һ��ֻ��һ�Σ��Ҳ�Ҫ����ѭ������
	2.ע��ÿ���ط��������srand((unsigned)time(NULL));���µĲ�ͬЧ��
	3.rand()�޷������ܴ�����������Ϊ��ͨ��ʱ��ת�������ģ�ֻ����ô��
*/

#include<iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;

void randnum() {
	//srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		//srand((unsigned)time(NULL));
		cout << rand()%100 << " ";
	}
}

void testRandnum() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++) {
		//srand((unsigned)time(NULL));
		randnum();
		cout << "===============================" << endl;
	}
}


//void main() {
//	testRandnum();
//}