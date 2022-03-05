/*
初始对象
	方法一：利用构造函数，写在构造函数里面，一个一个成员的赋值
	方法二：构造函数()：属性1(值1),属性2（值2）... {}
*/

#include<iostream>
using namespace std;

class Person_11_5 {
public:
	int age;
	int height;
	int score;
	Person_11_5(int a,int b,int c) :age(a), height(b), score(c) {//方法二初始化列表
	}
	void showprint() {
		cout << "age:" << age << "\t\theight:" << height << "\tscore:" << score << endl;
	}
};

//void main() {
//	Person_11_5 person(20,180,85);
//	person.showprint();
//}