/*
类作为另一个类的成员时,我们称该成员为 对象成员
	构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	析构顺序与构造相反
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
		cout << "phone构造函数" << endl;
	}
};


class Person_11_6 {
public:
	string name;
	Phone_11_6 myphone;
	Person_11_6(string a, string b, int c) :name(a), myphone(b, c) {//这里myphone(b, c)是一个隐式转换法，等价Phone_11_6 myphone={b,c}
		cout << "person构造函数" << endl;
	}
};

//class Person_11_6 {
//public:
//	string name;
//	Phone_11_6 myphone;
//	Person_11_6(string a, string b, int c){
//		name = a;
//		myphone = { b,c };
//		cout << "person构造函数" << endl;
//	}
//};


void test_11_6() {
	Person_11_6 person("张三", "华为", 3200);
	cout << "name:" << person.name << "\t\tphone:" << person.myphone.pname << "\t\tprice:" << person.myphone.price << endl;
}

//void main() {
//	test_11_6();
//}