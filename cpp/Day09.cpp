/*Day09
�����߼�
	(1)����Ĭ�ϲ���  ����ֵ���� ������(����= Ĭ��ֵ){}
		//1. ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴������ң����붼Ҫ��Ĭ��ֵ
		//2. �������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ�ϲ���(����������ʵ��ֻ����һ����Ĭ�ϲ���)
			int func(int a=10; int b=10);//��������
			int func(int a=10; int b=10){return a+b;}//����ʵ��
			//�������Ӵ��󣬺���������ʵ��ֻ����һ����Ĭ�ϲ���
			int func(int a; int b);//��������
			int func(int a=10; int b=10){return a+b;}//����ʵ��
		//3. �д���Ĳ������ô���Ĳ�����û�о�Ҫ��Ĭ��ֵ
	(2)����ռλ����  ����ֵ���� ������ (��������){}  void func(int a, int) {}
		//1. C++�к������β��б��������ռλ������������ռλ�����ú���ʱ�������λ��
		//2. ����ռλ���� ��ռλ����Ҳ������Ĭ�ϲ���  void func(int a, int = 10) {}
		//3. ���ֽ׶κ�����ռλ�����������岻�󣬵��Ǻ���Ŀγ��л��õ��ü���
	(3)��������  ������������ͬ����߸�����
		//1. ����������ͬһ���������£�����������ͬ�������������Ͳ�ͬ���߸�����ͬ����˳��ͬ��
		//2. ��������ֵ��������Ϊ������������
		//3. ע�⣺	* ������Ϊ��������
					* ����������������Ĭ�ϲ���
*/

#include <iostream>
#include <string>

using namespace std;

//����Ĭ�ϲ���
int sum_3(int a, int b = 10, int c = 10) {//������֮��
	return a + b + c;
}

//����ռλ����
void placeholder(int a, int) {
	cout << "This is placeholder func." << endl;
}

//������Ϊ��������
void ref_overloading(int& a)
{
	cout << "ref_overloading (int &a) ���� " << endl;
}
void ref_overloading(const int& a)
{
	cout << "ref_overloading (const int &a) ���� " << endl;
}

//Ĭ�ϲ���������������
void def_overloading(int a,int b = 10) {
	cout << "def_overloading (int a; int b = 10) ���� " << endl;
}
void def_overloading(int a) {
	cout << "def_overloading (int a) ���� " << endl;
}

//void main() {
//	//������Ĭ�ϲ����ĺ���ʱ��Ĭ�ϵĲ���λ�ÿ��Դ�ֵҲ�ɲ���
//	cout << "Ĭ�ϲ���" << endl;
//	cout << "sum_3 = " << sum_3(20, 20) << endl;
//	cout << "sum_3 = " << sum_3(100) << endl;
//	
//	//������ռλ����(��Ĭ��)�ĺ���ʱ��ռλ�����������ռλ����ΪĬ�ϲ���ʱ����ɲ��
//	cout << endl << "ռλ����" << endl;
//	placeholder(10, 10); //ռλ���������
//
//	//������Ϊ��������,���ݴ�������͵��ã�ָ�볣��(������const)������ָ�볣��(����const)
//	int a = 10;
//	const int b = 10;
//	cout << endl << "������Ϊ��������" << endl;
//	ref_overloading(a); //aΪ������������const
//	ref_overloading(b); //bΪ����������const
//	ref_overloading(10);//int &a = 10 ���Ϸ���const int &a = 10 �Ϸ������Ե�����const
//
//	//Ĭ�ϲ���������������
//	cout << endl << "Ĭ�ϲ���������������" << endl;
//	//def_overloading(10);//������֪�������ĸ�
//	def_overloading(10, 10);
//}
