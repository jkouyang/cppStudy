/*
关系运算符重载：== ， !=
	重载关系运算符，可以让两个自定义类型对象进行对比操作
*/
#include<iostream>
#include<string>
using namespace std;

class Person_17_3 {
public:
	int age;
	Person_17_3(int age) {
		this->age = age;
	}

	bool operator==(Person_17_3 &p) {
		if (this->age == p.age) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(Person_17_3& p) {
		if (this->age == p.age) {
			return false;
		}
		else {
			return true;
		}
	}
};

void test_17_3() {
	Person_17_3 p1(23);
	Person_17_3 p2(24);
	Person_17_3 p3(23);

	if (p1 == p2) {
		cout << "p1与p2年龄相同" << endl;
	}
	else {
		cout << "p1与p2年龄不相同" << endl;
	}

	if (p1 != p2) {
		cout << "p1与p2年龄不相同" << endl;
	}
	else {
		cout << "p1与p2年龄相同" << endl;
	}

	if (p1 == p3) {
		cout << "p1与p3年龄相同" << endl;
	}
	else {
		cout << "p1与p3年龄不相同" << endl;
	}

	if (p1 != p3) {
		cout << "p1与p3年龄不相同" << endl;
	}
	else {
		cout << "p1与p3年龄相同" << endl;
	}
}

//void main() {
//	test_17_3();
//}