/*array ��������
* 
һ.ΪʲôҪ���� array ������ֱ��ʹ�� vector��
	1.��vector��ͬ��array�Ĵ�С�ǹ̶���
	2.vector���Զ����ݵģ�������������ݺ�vector���������
	  ��ʱ������������ɾ�������������������Զ��黹��ɾ��Ԫ����Ӧ���ڴ棬
	  ��Ҫ�ֶ����� shrink_to_fit() �ͷ��ⲿ���ڴ档

��.�Ѿ����˴�ͳ���飬ΪʲôҪ�� std::array?
	array �ܹ��ô����ø��ӡ��ִ���������װ��һЩ��������
	��װ��size()��empty()��data()(����ָ�룬��&arr[0])�ȳ�Ա������ͬʱ����ʹ�ñ�׼���е������㷨������sort()

�﷨��	#include<array>
		array<T,n> arr;//TΪ�������ͣ�nΪarray��size.
ע�⣺array<int,n>Ҫ�ֶ���ʼ��������vector<int>���Զ�ȫ0
*/

#include<iostream>
#include<string>
#include<vector>
#include<array>
#include <algorithm>
using namespace std;

void funcArray(int* p, int len) {//Ҫ����һ������ָ������鳤��
}

void testArray() {
	array<int, 10> arr{5,2,8,1,3,9,6,4,0,7};
	//int* p = arr;//����array�����鲻ͬ�������Զ��˻��� T*
	int aa[10];
	int* p = aa;
	cout << "arr.empty():" << arr.empty() << endl;
	cout << "arr.size():" << arr.size() << endl;

	cout << "sort()����";
	sort(arr.begin(), arr.end(), [](int a, int b)->bool{return a > b;});//ʹ��lambda���ʽ����
	for (auto&& i : arr) { cout << i << " "; }

	//array������Ľӿڣ�Ҫ����һ������ָ������鳤��
	//funcArray(arr, arr.size());// �Ƿ�, �޷���ʽת��
	funcArray(&arr[0], arr.size());
	funcArray(arr.data(), arr.size());
}

//void main() {
//	testArray();
//}