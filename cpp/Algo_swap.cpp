/*swap()�����������������ڵ�Ԫ��
* ������ʽ
	void swap(vect1, vect2)
	��������������Ԫ��

ע�⣺swap()���Խ���ͬ�������͵ı�������������
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void testSwap() {
	//void swap(vect1, vect2)
	//��������������Ԫ��
	vector<int> vect1{ 1,2,3,4,5,6,7,8,9 };
	vector<int> vect2{ 9,8,7,6,5,4,3,2,1 };
	for (int i : vect1) { cout << i << " "; }
	cout << endl;
	for (int i : vect2) { cout << i << " "; }
	cout << endl << "===========================" << endl;
	swap(vect1, vect2);
	for (int i : vect1) { cout << i << " "; }
	cout << endl;
	for (int i : vect2) { cout << i << " "; }
	cout << endl;

	//swap()���Խ���ͬ�������͵ı�������������
	int a = 10;
	int b = 2;
	swap(a, b);
	cout << a << b << endl;
}

//void main() {
//	testSwap();
//}

