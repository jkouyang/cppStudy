/*
"="��������
c++���������ٸ�һ�������4������

1. Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
2. Ĭ����������(�޲Σ�������Ϊ��)
3. Ĭ�Ͽ������캯���������Խ���ֵ����
4. ��ֵ����� operator=, �����Խ���ֵ����

�������������ָ�����������ֵ����ʱҲ�������ǳ��������
*/
#include<iostream>
#include<string>
using namespace std;

class Person_17_2 {
public:
	int *age;
	Person_17_2(int age) {
		this->age = new int(age);
	}

	~Person_17_2() {
		if (this->age != NULL) {
			delete this->age;//deleteʵ�������ͷ�ָ��ָ����ڴ�ռ�
			this->age = NULL;//ָ���ÿ�
		}
		cout << "�ͷ�" << endl;
	}

	Person_17_2& operator=(Person_17_2 &p) {
		if (this->age != NULL) {//�ȼ�鱻��ֵ�����Ƿ�Ϊ��
			delete this->age;//deleteʵ�������ͷ�ָ��ָ����ڴ�ռ�
			this->age = NULL;//ָ���ÿ�
		}
		this->age = new int(*p.age);
		return *this;
	}
};

void test_17_2() {
	Person_17_2 p1(18);
	Person_17_2 p2(20);
	Person_17_2 p3(30);

	//Person_17_2 p3 = p2;//��Ҫд���֣����Ǵ������󣬶�Ӧ���ǹ��캯������û�ж��������Ĺ��캯��������������ֻ�Ḵ��ָ�룬�ͷ�ʱ����
	p3= p2 = p1;//��ֵ������û������
	cout << "p1.age:" << *p1.age << "\t\tp2.age" << *p2.age << "\t\tp3.age" << *p3.age << endl;//ֵ
	cout << "&p1.age:" << p1.age << "\t&p2.age" << p2.age << "\t\t&p3.age" << p3.age << endl;//��ַ
}

//void main() {
//	test_17_2();
//	system("pause");
//}