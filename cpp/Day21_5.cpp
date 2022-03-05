/*模板的局限性
模板的通用性并不是万能的，有些特定的数据类型，需要用具体化方法来做特殊的实现

模板函数对特定的数据类型的两种解决方法：	
	1.运算符重载(前面学过，这里就不写了)
	2.利用具体化的Person版本来实现模板函数重载，具体化优先调用

总结：
	利用具体化的模板，可以解决自定义类型的通用化
	学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
*/

#include<iostream>
using namespace std;

class Person_21_5 {//创建一个类来用模板
public:
	string name;
	int age;
	Person_21_5(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

//对比两个数据是否相等
template<typename T>
bool isEqual_21_5(T &a, T &b) {//模板函数
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

//2.利用具体化的Person版本来实现模板函数重载，具体化优先调用
template<> bool isEqual_21_5(Person_21_5& a, Person_21_5& b) {
	if (a.age == b.age && a.name == b.name) {
		return true;
	}
	else {
		return false;
	}
}

void test_21_5a() {//比较两个int数据是否相等
	int a = 10;
	int b = 10;
	bool set = isEqual_21_5(a, b);
	if (set) {
		cout << "a与b相等" << endl;
	}
	else {
		cout << "a与b不相等" << endl;
	}
}

void test_21_5b() {//比较两个Person数据是否相等
	/*两种方法  1.运算符重载(前面学过，这里就不写了)
				2.利用具体化的Person版本来实现模板函数重载，具体化优先调用
	*/
	Person_21_5 p1 = Person_21_5("Tom", 25);
	Person_21_5 p2 = Person_21_5("Tom", 25);
	bool set = isEqual_21_5(p1, p2);
	if (set) {
		cout << "p1与p2相等" << endl;
	}
	else {
		cout << "p1与p2不相等" << endl;
	}
}
//void main() {
//	test_21_5a();
//	test_21_5b();
//}