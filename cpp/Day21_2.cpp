/*����
	���ú���ģ���װһ������ĺ��������Զ�**��ͬ������������**��������
	�������Ӵ�С�������㷨Ϊ**ѡ������**
	�ֱ�����**char����**��**int����**���в���
*/
#include<iostream>
using namespace std;

template<typename T>
void mySwap_21_2(T &a, T &b) {//ͨ�õĽ�������
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort_21_2(T arr[],int len) {//����
	for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			mySwap_21_2(arr[min], arr[i]);
		}
	}
}

template<typename T>
void printArr_21_2(T arr[], int len) {//��ӡ���
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test_20_2() {
	//����char����
	char chArr[] = {'c','a','f','d','e','b'};
	//char chArr[] = "cafdeb";
	//ϵͳ���Զ����ַ�����ĩβ�����ַ�������������'\0',����д���������д����ռһ���ֽ�,������һ��'\0'(�ַ�����������)
	int numChar = sizeof(chArr) / sizeof(char);
	//ע��sizeof()��strlen()������
	mySort_21_2(chArr, numChar);
	printArr_21_2(chArr, numChar);

	//����int����
	int intArr[] = { 3,5,9,4,2,8,1,6,7 };
	int numInt = sizeof(intArr) / sizeof(int);
	mySort_21_2(intArr, numInt);
	printArr_21_2(intArr, numInt);
	
}


//void main() {
//	test_20_2();
//	system("pause");
//}