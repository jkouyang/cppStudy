/*Day05
ָ�룺
	���� �������� *p��
	����  p=��ַ��pΪ��ַ��*pΪ��ַ��Ӧ��ֵ
	���岢���� �������� *p=��ַ��

	��ָ�룺ָ�����ָ���ڴ��б��Ϊ0�Ŀռ䣬���ڳ�ʼ��ָ���������ָ��ָ����ڴ��ǲ����Է��ʵ�
			int *p = NULL;

	Ұָ�룺ָ�����ָ��Ƿ����ڴ�ռ䣬�����б�����Ұָ��

	����ָ�룺const int *p = &a; //ָ���ָ����Ըģ�������ͨ����ָ�����޸�ָ���ڴ��ֵ

	ָ�볣����int * const p = &a; //ָ���ָ���ܸģ���ָ��ָ����ڴ��ֵ���Ը�

	const int * const p = &a; //ָ���ָ���ָ��ָ���ڴ��ֵ������

ע�⣺ָ���p++,���ǵ�ַ�ĵ�ַ(pֵ)������+1���Ǽ�һ��ָ��ָ���������͵ĳ��ȣ�������һλԪ��

ָ�������飺������ָ���ʾ�����е�Ԫ��

ָ���뺯������ַ����
			void xxx(int *p1, int *p2){}
			xxx(&a,&b)
*/

#include <iostream>
#include <string>
using namespace std;

void Day05()
{
	int num = 10;//��
	double arr1[5] = { 1,2,3,4,5 };//һά
	int arr2[5][4] = { { 1,2,3,4 }, {6,7,8,9} };//��ά
	
	int *p= &num;
	double *p1 = arr1;
	int *p2 = arr2[0];
	cout << arr2 << endl;
	cout << &arr2[0] << endl;

	cout << "p:" << p << endl ;
	cout << "*p:" << *p << endl;
	cout << "&num:" << &num << endl;
	cout << "num:" << num << endl << endl;
	

	cout << "p1:" << p1 << endl;
	cout << "++p1:" << ++p1 << endl;
	cout << "*p1:" << *p1 << endl;
	cout << "arr1:" << arr1 << endl;
	cout << "arr1[0]:" << arr1[0] << endl << endl;

	cout << "p2:" << p2 << endl;
	cout << "*p2:" << *p2 << endl;
	cout << "arr2:" << arr2 << endl;
	cout << "arr2[0]:" << arr2[0] << endl;
	cout << "arr2[0][0]:" << arr2[0][0]<< endl << endl;


	//32λ��(x86)ָ�붼��ռ4B��64λ(x64)ָ�붼��ռ8B
	cout << "int*��ռ�ռ�:" << sizeof(int*) << endl;
	cout << "double*��ռ�ռ�:" << sizeof(double*) << endl;
	cout << "char*��ռ�ռ�:" << sizeof(char*) << endl;
	cout << "string*��ռ�ռ�:" << sizeof(string*) << endl;
	

}


//void main(){
//	Day05();
//}