/*
����Ϊ��һ����ĳ�Աʱ,���ǳƸó�ԱΪ �����Ա
	�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	����˳���빹���෴
*/

#include<iostream>
#include<string>
using namespace std;

class Phone_11_6 {
public:
	string pname;
	int price;
	Phone_11_6() {}
	Phone_11_6(string a, int b) :pname(a), price(b) {
		cout << "phone���캯��" << endl;
	}
};


class Person_11_6 {
public:
	string name;
	Phone_11_6 myphone;
	Person_11_6(string a, string b, int c) :name(a), myphone(b, c) {//����myphone(b, c)��һ����ʽת�������ȼ�Phone_11_6 myphone={b,c}
		cout << "person���캯��" << endl;
	}
};

//class Person_11_6 {
//public:
//	string name;
//	Phone_11_6 myphone;
//	Person_11_6(string a, string b, int c){
//		name = a;
//		myphone = { b,c };
//		cout << "person���캯��" << endl;
//	}
//};


void test_11_6() {
	Person_11_6 person("����", "��Ϊ", 3200);
	cout << "name:" << person.name << "\t\tphone:" << person.myphone.pname << "\t\tprice:" << person.myphone.price << endl;
}

//void main() {
//	test_11_6();
//}