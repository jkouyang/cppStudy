/*
vector中存放自定义数据类型，并打印输出

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Person_22_3 {
public:
	string myName;
	int myAge;
	Person_22_3(string name,int age) {
		this->myName = name;
		this->myAge = age;
	}
};

void test_22_3a() {//存放类的对象
	vector<Person_22_3> v1;
	Person_22_3 p1("唐僧",25);
	Person_22_3 p2("孙悟空", 999);
	Person_22_3 p3("猪八戒", 798);
	Person_22_3 p4("沙僧", 654);
	Person_22_3 p5("白龙马", 425);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
	for (vector<Person_22_3>::iterator pBegin = v1.begin(); pBegin != v1.end(); pBegin++) {
		//pBegin是一个指针，指向的数据类型为vector里面存放的数据结构
		cout << pBegin->myName << " \t" << pBegin->myAge << endl;
		//cout << (*pBegin).myName << " \t" << (*pBegin).myAge << endl;
		//上面两种写法都可以
	}
	//cout << endl;
}

void test_22_3b() {
	vector<Person_22_3*> v2;
	Person_22_3 p1("唐僧", 25);
	Person_22_3 p2("孙悟空", 999);
	Person_22_3 p3("猪八戒", 798);
	Person_22_3 p4("沙僧", 654);
	Person_22_3 p5("白龙马", 425);
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);
	v2.push_back(&p4);
	v2.push_back(&p5);
	for (vector<Person_22_3*>::iterator pBegin = v2.begin(); pBegin != v2.end(); pBegin++) {
		cout << (*pBegin)->myName << " \t" << (*pBegin)->myAge << endl;
	}
}

//void main() {
//	test_22_3a();
//	cout << "=============================================" << endl;
//	test_22_3b();
//}