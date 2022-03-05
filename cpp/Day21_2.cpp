/*案例
	利用函数模板封装一个排序的函数，可以对**不同数据类型数组**进行排序
	排序规则从大到小，排序算法为**选择排序**
	分别利用**char数组**和**int数组**进行测试
*/
#include<iostream>
using namespace std;

template<typename T>
void mySwap_21_2(T &a, T &b) {//通用的交换函数
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort_21_2(T arr[],int len) {//排序
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
void printArr_21_2(T arr[], int len) {//打印输出
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test_20_2() {
	//测试char数组
	char chArr[] = {'c','a','f','d','e','b'};
	//char chArr[] = "cafdeb";
	//系统会自动在字符串的末尾加上字符串结束符，即'\0',这种写法比上面的写法多占一个字节,最后多了一个'\0'(字符串结束符号)
	int numChar = sizeof(chArr) / sizeof(char);
	//注意sizeof()和strlen()的区别
	mySort_21_2(chArr, numChar);
	printArr_21_2(chArr, numChar);

	//测试int数组
	int intArr[] = { 3,5,9,4,2,8,1,6,7 };
	int numInt = sizeof(intArr) / sizeof(int);
	mySort_21_2(intArr, numInt);
	printArr_21_2(intArr, numInt);
	
}


//void main() {
//	test_20_2();
//	system("pause");
//}