/*构造函数的分类及调用
两种分类方式：
​	按参数分为： 有参构造和无参构造
​	按类型分为： 普通构造和拷贝构造

三种调用方式：
​	括号法
​	显示法
​	隐式转换法

//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明（返回类型  函数名()，Person p()——错误;）
//注意2：不能利用拷贝构造函数初始化匿名对象编译器认为是对象声明
*/

#include<iostream>
using namespace std;

class Person_11_1 {
public:
	int age;
	int score;

	//普通构造
	Person_11_1() {//无参构造
		cout << "无参构造函数!" << endl;
		this->age = 0;
		this->score = 0;		
	}

	Person_11_1(int age, int score) {//有参构造
		cout << "有参构造函数!" << endl;
		this->age = age;
		this->score = score;		
	}

	//拷贝构造
	Person_11_1(const Person_11_1  &p) {
		cout << "拷贝构造函数!" << endl;
		this->age = p.age;
		this->score = p.score;
	}

	void Show_11_1() {
		cout << "age:" << age << "\tscore:" << score << endl;
	}

	//~Person_11_1() {
	//	cout << "析构函数!" << endl;
	//}
};

//调用有参的构造函数
void test11_1() {

	//括号法，常用
	cout << "*****括号法，常用*****" << endl;
	Person_11_1 p11; 
	p11.Show_11_1();
	Person_11_1 p12(20,80);
	p12.Show_11_1();
	Person_11_1 p13(p12);
	p13.Show_11_1();
	//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明——返回类型  函数名()，Person p()——错误;

	//显式法
	cout << endl << "*****显式法*****" << endl;
	Person_11_1 p21 = Person_11_1();
	p21.Show_11_1();
	Person_11_1 p22 = Person_11_1(20,80);
	p22.Show_11_1();
	Person_11_1 p23 = Person_11_1(p22);
	p23.Show_11_1();
	//Person(10)单独写就是匿名对象  当前行结束之后，马上析构

	//隐式转换法
	cout << endl << "*****隐式转换法*****" << endl;
	Person_11_1 p31 = {  };//元素为空或者有多个元素时要用{ }，只有一个元素时可以不用{ }直接写元素
	p31.Show_11_1();
	Person_11_1 p32 = { 10, 80 };
	p32.Show_11_1();
	Person_11_1 p33 = p32; 
	p33.Show_11_1();

	//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
	//Person p5(p4);
}

//void main() {
//	test11_1();	
//}