/*ָ�뺯��		����ָ��
* 
	ָ�뺯��������ֵΪָ��ĺ���
	����ָ�룺ָ������ָ��

�ܽ᣺
	�������������һ����ַ������һ������ָ��
	����ָ�������Ϊ�������д���
*/

#include<iostream>
using namespace std;

int* pterDay08_3a(int& val) {//����ָ�룬ָ�뺯��
	val = val + 1;
	return &val;
}

int& pterDay08_3b(int& val) {//�������ã�ָ�뺯��
	val = val + 1;
	return val;
}

int pterDay08_3c(int& val) {//��ͨ����
	val = val + 1;
	return val;
}

void testDay08_3() {
	int value = 1;
	//����ָ�룬ָ�뺯��
	int* p1 = pterDay08_3a(value);
	cout << "value:" << value << "\t\t*p1:" << *p1 << endl;

	//�������ã�ָ�뺯��
	int& p2 = pterDay08_3b(value);
	p2++;
	cout << "value:" << value << "\t\tp2:" << p2 << endl;

	//��ͨ������������ɺ���ָ��
	// ֱ�Ӷ���
	int (*func_ptr)(int&);//����һ��ָ�룬ָ����(����ֵΪint������Ϊint&)
	func_ptr = pterDay08_3c;//��ֵ
	func_ptr(value);
	cout << "value:" << value << endl;

	//typedef
	typedef int(*func_ptr2)(int&);//��typedef������ָ��(����ֵΪint������Ϊint&)����func_ptr2
	func_ptr2 ptr1 = pterDay08_3c;//����һ������ָ�룬����ֵ
	ptr1(value);//���ú���ָ����ú���
	cout << "value:" << value << endl;

	//using���Ƽ�ʹ��
	using func_ptr3 = int(*)(int&);//��using������ָ��(����ֵΪint������Ϊint&)����func_ptr3
	func_ptr3 ptr2 = pterDay08_3c;//����һ������ָ�룬����ֵ
	ptr2(value);//���ú���ָ����ú���
	cout << "value:" << value << endl;

}

//void main() {
//	testDay08_3();
//}