/*
随机数
	1.srand((unsigned)time(NULL))一般只加一次，且不要放在循环里面
	2.注意每个地方如果加上srand((unsigned)time(NULL));导致的不同效果
	3.rand()无法产生很大的随机数，因为是通过时间转换过来的，只有那么大
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