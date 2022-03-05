/*��ģ��
	����һ��ͨ���࣬���еĳ�Ա �������Ϳ��Բ������ƶ�����һ��**���������**������
	��ģ��ͺ���ģ���﷨���ƣ�������ģ��template������࣬�����Ϊ��ģ��

��ģ���뺯��ģ��������Ҫ�����㣺
	1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ����ģ��ʹ��ֻ������ʾָ�����ͷ�ʽ
	2.��ģ����ģ������б��п�����Ĭ�ϲ���
*/

#include<iostream>
#include<string>
using namespace std;

//��ģ��������Ͷ���
template<class nameType,class ageType = int>//2.��ģ����ģ������б��п�����Ĭ�ϲ���������ӣ�=�������ͣ�
class Person_21_6 {
public:
	nameType name;
	ageType age;
	Person_21_6(nameType name, ageType age) {
		this->name = name;
		this->age = age;
	}
	void print() {
		cout << this->name << "  " << this->age << endl;
	}
};

void test_21_6() {
	//������ģ��
	//Person_21_6 p1("�����", 999);//����1.��ģ��ʹ��ֻ������ʾָ�����ͷ�ʽ

	Person_21_6<string, int> p1("�����", 999);
	Person_21_6<string, int> p2 = Person_21_6<string, int>("��˽�", 798);
	p1.print();
	p2.print();

	//2.��ģ����ģ������б��п�����Ĭ�ϲ���������ģ���в���������
	Person_21_6<string> p3("ɳɮ", 697);
	Person_21_6<string,double> p4("��ɮ", 399.9);//�����ô��ݵ��������ͣ�������Ĭ�ϵ���������
	p3.print();
	p4.print();
}

//void main() {
//	test_21_6();
//}


