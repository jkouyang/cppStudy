/*Day17  运算符重载
* 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
	“+”号运算符重载
			作用：实现两个自定义数据类型相加的运算
			实现：1.成员函数实现“+”号运算符重载
				  2.全局函数实现“+”号运算符重载
			总结：1.对于内置的数据类型的表达式的的运算符是不可能改变的
				  2.不要滥用运算符重载

	“<<”左移运算符重载
			实现：全局函数
	“++”递增运算符重载，包括前置递增运算符重载和后置递增运算符重载
			实现：成员函数
*/

#include<iostream>
#include<string>
using namespace std;

class Person_17_1 {
public:
	int A;
	int B;

	void show_17_a() {
		cout << "A:" << A << "\tB:" << B << endl;
	}
	//Person_17_1 operator+(Person_17_1 &p) {//1.成员函数实现“ + ”号运算符重载
	//	Person_17_1 temp;
	//	temp.A = this->A + p.A;
	//	temp.B = this->B + p.B;
	//	return temp;
	//}

	//我们不用成员函数实现<<运算符重载
	//成员函数 实现不了  p << cout 不是我们想要的效果
	//void operator<<(Person_17_1& p){
	//}

	Person_17_1& operator++() {//前置递增
		this->A++;//先+
		this->B++;
		return *this;//再返回
		//前置递增可以链式操作，所以返回引用(本体)
	}

	Person_17_1 operator++(int) {//用占位符实现函数重载，区分前置和后置
		Person_17_1 temp = *this;//先记录
		A++;//先+
		B++;
		return temp;//再返回
		//后置递增不能链式操作，所以返回类(形参)
	}

	//通过析构函数可以来看变量的释放情况
	//~Person_17_1() {
	//	cout << "释放类的变量了" << endl;
	//}

};

Person_17_1 operator+(Person_17_1 p1, Person_17_1 &p2) {//2.全局函数实现“+”号运算符重载
	Person_17_1 temp;
	temp.A = p1.A + p2.A;
	temp.B = p1.B + p2.B;
	return temp;
}

//全局函数实现“<<”左移运算符重载
ostream& operator<<(ostream &out, Person_17_1 p) {//cout是标准的数据输出流，只有一个，所以只能用引用，引用是起别名，所以命名可以随便，例：out
	out << "A:" << p.A << "\tB:" << p.B;//为什么这个地方用引用传递Person_17_1 &p，在91行(cout << "p2++:\t\t" << p2++ << endl;//后置递增)报错
	return out;
}

void test_17_1() {
	//“+”号运算符重载
	Person_17_1 p1;
	p1.A = 10;
	p1.B = 10;
	Person_17_1 p2;
	p2.A = 15;
	p2.B = 15;
	Person_17_1 p3 = p1 + p2;

	cout << "p1.A=10\tp1.B = 10" << endl;
	cout << "p2.A=15\tp1.B = 15" << endl;
	cout << "p3=p1+p2\t";
	p3.show_17_a();

	//“ << ”左移运算符重载
	cout << "p3:\t\t"<< p3 << "\t链式思想" << endl;

	//“++”递增运算符重载
	cout << "++++++p1:\t"<< ++++++p1 << endl;//前置递增
	cout << "p1:\t\t" << p1 << endl;//前置递增
	cout << "p2++:\t\t" << p2++ << endl;//后置递增
	cout << "p2:\t\t" << p2 << endl;//后置递增
}

//void main() {
//	test_17_1();
//	system("pause");
//}