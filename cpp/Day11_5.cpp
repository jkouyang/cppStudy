/*
��ʼ����
	����һ�����ù��캯����д�ڹ��캯�����棬һ��һ����Ա�ĸ�ֵ
	�����������캯��()������1(ֵ1),����2��ֵ2��... {}
*/

#include<iostream>
using namespace std;

class Person_11_5 {
public:
	int age;
	int height;
	int score;
	Person_11_5(int a,int b,int c) :age(a), height(b), score(c) {//��������ʼ���б�
	}
	void showprint() {
		cout << "age:" << age << "\t\theight:" << height << "\tscore:" << score << endl;
	}
};

//void main() {
//	Person_11_5 person(20,180,85);
//	person.showprint();
//}