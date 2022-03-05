/*类模板
	建立一个通用类，类中的成员 数据类型可以不具体制定，用一个**虚拟的类型**来代表
	类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板

类模板与函数模板区别主要有两点：
	1.类模板没有自动类型推导的使用方式，类模板使用只能用显示指定类型方式
	2.类模板在模板参数列表中可以有默认参数
*/

#include<iostream>
#include<string>
using namespace std;

//类模板的声明和定义
template<class nameType,class ageType = int>//2.类模板在模板参数列表中可以有默认参数，后面加（=数据类型）
class Person_21_6 {
public:
	nameType name;
	ageType age;
	Person_21_6(nameType name, ageType age) {
		this->name = name;
		this->age = age;
	}
	void print() {
		cout << this->name << "  " << this->age << endl;
	}
};

void test_21_6() {
	//创建类模板
	//Person_21_6 p1("孙悟空", 999);//报错，1.类模板使用只能用显示指定类型方式

	Person_21_6<string, int> p1("孙悟空", 999);
	Person_21_6<string, int> p2 = Person_21_6<string, int>("猪八戒", 798);
	p1.print();
	p2.print();

	//2.类模板在模板参数列表中可以有默认参数，函数模板中不能这样用
	Person_21_6<string> p3("沙僧", 697);
	Person_21_6<string,double> p4("唐僧", 399.9);//传了用传递的数据类型，不传用默认的数据类型
	p3.print();
	p4.print();
}

//void main() {
//	test_21_6();
//}


