/*
�����ǳ����
	ǳ�������򵥵ĸ�ֵ��������
			���ܶ����������ʲô�������ͣ�����ֱ�ӿ���һ�ݣ������ָ��Ļ�����ʵֻ�����˵�ַ����û�и�������
			����ָ�룬ֱ�Ӹ���ָ�룬û�и�������(���������е�heightָ���ŵĵ�ַ��ͬ��ָ��ͬһ���ڴ�ռ�)
	������ڶ�����������ռ䣬���п�������
			����ָ�룬���ڶ�������һ��ԭ����ָ��ָ������ݣ��ٽ��¶����ָ��ָ�������(���������е�heightָ���ŵĵ�ַ��ͬ����������ַ��������ͬ)

****�����г�Ա��ָ��ʱ�����������
*/

#include<iostream>
using namespace std;

class Person_11_4 {
public:
	int age;
	int *height;

	Person_11_4() {
		cout << "�޲ι���" << endl;
	}

	Person_11_4(int age, int height) {
		cout << "�вι���" << endl;
		this->age = age;
		this->height = new int(height);//new���ڶ������¿���һ���ռ䣬�����ص��Ǹ��������͵�ָ��
	}

	Person_11_4(const Person_11_4 &p) {
		cout << "��������" << endl;
		this->age = p.age;
		
		//ǳ����������ָ�룬ֱ�Ӹ���ָ�룬û�и�������(���������е�heightָ���ŵĵ�ַ��ͬ��ָ��ͬһ���ڴ�ռ�)
		//this->height = p.height;//��ǳ������ʱ�������������ָ�붼�ͷŵ�ʱ��ᱨ��
		
		//���������ָ�룬���ڶ�������һ��ԭ����ָ��ָ������ݣ��ٽ��¶����ָ��ָ�������(���������е�heightָ���ŵĵ�ַ��ͬ����������ַ��������ͬ)
		this->height = new int(*p.height);//�����ʱ������ָ���ͷŵ�ʱ��Ҳ���ᱨ��
	}

	~Person_11_4() {
		cout << "��������!" << endl;//����������������ı����ͷ�
		if (height != NULL)
		{
			delete height;
			height = NULL;//�ÿգ���ֹҰָ�����
		}
	}
};

void test_11_4() {
	Person_11_4 person(24, 180);
	cout << "person\t\tage:" << person.age << "\thegiht" << *person.height << endl;
	Person_11_4 new_person(person);
	cout << "new_person\tage:" << person.age << "\thegiht" << *person.height << endl;
}

//void main() {
//	test_11_4();
//}