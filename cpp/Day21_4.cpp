/*��ͨ�����뺯��ģ��ĵ��ù���
	1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
	2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
	3.����ģ��Ҳ���Է�������
	4.�������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��

ע�⣺�ܽ�--��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����
*/

#include<iostream>
using namespace std;

//��ͨ����
void print_21_4(int a,int b) {
	cout << "��ͨ�����ĵ���" << endl;
}

//����ģ��
template<typename T>
void print_21_4(T a, T b) {
	cout << "����ģ��ĵ���" << endl;
}

template<typename T>
void print_21_4(T a, T b,T c) {//3.����ģ��Ҳ���Է�������
	cout << "����ģ��ĵ���" << endl;
}


void test_21_4() {
	print_21_4(10, 10);//1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
						//�����ͨ����ֻ������û�ж���Ҳ�������ͨ������������ִ��ʱ�ᱨ��(��ͨ����û�ж��壬�޷�ִ��)

	print_21_4<>(10, 10);//2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��

	print_21_4(10, 10, 10);//3.����ģ��Ҳ���Է�������

	print_21_4('a', 'b');//4.�������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
						 //�����������ɵ��ã������ú���ģ�岻�ý�����ʽת����������ȵ��ú���ģ��
}

//void main() {
//	test_21_4(); 
//}
