/*Day07
ջ����
	ջ���ɱ������Զ������ͷ�, ��ź����Ĳ���ֵ,�ֲ�������
	ע�����**��Ҫ���ؾֲ������ĵ�ַ��ջ�����ٵ������ɱ������Զ��ͷ�**

������
	new�����ڶ�����������

����new�������ڶ�����������
�������ٵ����ݣ��ɳ���Ա�ֶ����٣��ֶ��ͷţ��ͷ����ò����� delete
*/

#include <iostream>
#include <string>

using namespace std;

int* func1(){
	int a = 10;
	return &a;//ջ�����ٵ������ɱ������Զ��ͷ�,�ֲ������ĵ�ַ��Ҫ����
}

int* func2()
{
	// new�����ڶ�����������
	int *a = new int(10);//new���ص��Ǹ��������͵�ָ��
	//ָ��a�Ǿֲ���������ջ����ָ��aָ�������int(10)�����˶���
	return a;
}

void test1_new() {
	int* p = func2();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//�������ٵ����ݣ��ɳ���Ա�ֶ����٣��ֶ��ͷţ��ͷ����ò����� delete
	delete p;
	//cout << *p << endl;//�ڴ��ѱ��ͷţ��ٴη��ʾ���Ƿ��������ᱨ��
}
void test2_new() {
	//����10�������飬��Ŷ���
	int *arr = new int[10];
	for (int i = 0; i < 10; i++) {//��ֵ
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {//��ֵ
		cout << arr[i] << endl;
	}
	//�ͷ������ʱ��Ҫ��[]
	delete[] arr;
}

//void main() {
//
//	int* p1 = func1();
//
//	//*p������a��ֵ��func()������ɺ�pָ��Ŀռ䱻�ͷ�
//	cout << "ջ�����ٵ������ɱ������Զ��ͷ�,�ֲ������ĵ�ַ��Ҫ����" << endl;
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//
//	cout << endl << "�������ٵ����ݣ��ɳ���Ա�ֶ����٣��ֶ��ͷ�" << endl;
//	int *p2 = func2();//ָ��a��ŵĵ�ַ������p2������ָ��p2ָ�������int(10)�����˶���
//	cout << *p2 << endl;
//	cout << *p2 << endl;
//	cout << *p2 << endl;
//	cout << *p2 << endl;
//
//	cout << endl << "����new��delete" << endl;
//	test1_new();
//	cout << endl << "����new��������" << endl;
//	test2_new();
//
//	system("pause");
//
//}