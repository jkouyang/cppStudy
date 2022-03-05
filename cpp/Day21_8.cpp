/*��ģ���������������
��ģ��ʵ�������Ķ����������εķ�ʽ
һ�������ִ��뷽ʽ��
	1. ָ�����������(����) --- ֱ����ʾ�������������
	2. ����ģ�廯			--- �������еĲ�����Ϊģ����д���
	3. ������ģ�廯			--- ������������� ģ�廯���д���
*/

#include<iostream>
#include<string>
using namespace std;

template<class nameType, class ageType>
class Person_21_8 {
public:
	nameType name;
	ageType age;
	Person_21_8(nameType name, ageType age) {
		this->name = name;
		this->age = age;
	}
	void print() {
		cout << this->name << "  " << this->age << endl;
	}
};

//1��ָ����������ͣ�ͨ�����õ�һ�ַ���
void printPerson_21_8a(Person_21_8<string, int> &p) {
	p.print();
}
//2������ģ�廯
template<typename T1, typename T2>
void printPerson_21_8b(Person_21_8<T1, T2>& p) {
	p.print();
	cout << "T1����������Ϊ��" << typeid(T1).name() << endl;//��ȡģ�����������
	cout << "T2����������Ϊ��" << typeid(T2).name() << endl;
}
//3��������ģ�廯
template<class T>
void printPerson_21_8c(T &p) {
	p.print();
	cout << "T����������Ϊ��" << typeid(T).name() << endl;
}

void test_21_8() {
	Person_21_8<string, int> p("�����",999);
	//1��ָ�����������
	printPerson_21_8a(p);
	//2������ģ�廯
	printPerson_21_8b(p);
	//3��������ģ�廯
	printPerson_21_8c(p);
}

//void main() {
//	test_21_8();
//}