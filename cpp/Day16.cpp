/*Day16  友元
在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
友元的目的就是让一个函数或者类 访问另一个类中私有成员
友元的关键字为  ==friend==

友元的三种实现
	1.全局函数做友元	friend void myfriend_16();
	2.类做友元			friend class friend_16a;
	3.成员函数做友元	friend void friend_16b::visit1();

****注意：	1.用指针(或引用)创建类，可以解决类未定义的问题(先声明)
			2.把类中所有的函数先声明，放在最后定义，可以解决未定义的问题
*/

#include<iostream>
#include<string>
using namespace std;
class Building_16;
class friend_16a;
class friend_16b;

class friend_16a {//友元类
public:
	friend_16a();
	void visit();
private:
	Building_16 *b;
};

class friend_16b {//友元函数的类
public:
	friend_16b();
	void visit1();//友元函数
	void visit2();//非友元函数
private:
	Building_16 *b;
};


class Building_16 {//本类
	//1.全局函数做友元，告诉编译器 myfriend_16全局函数是 Building类的友元，可以访问类中的私有内容
	friend void myfriend_16();
	//2.类做友元，友元类内的函数可以访问该类的私有容
	friend class friend_16a;
	//3.成员函数做友元，该成员函数可以访问该类的私有容
	friend void friend_16b::visit1();
public:
	string sittingroom;
private:
	string bedroom;
public:
	Building_16();
};

friend_16a::friend_16a() {
	b = new Building_16;
}

friend_16b::friend_16b() {
	b = new Building_16;
}
Building_16::Building_16() {
	sittingroom = "客厅";
	bedroom = "卧室";
}
void friend_16a::visit() {//2.类做友元
	cout << "我的朋友正在访问：" << b->sittingroom << endl;
	cout << "我的朋友正在访问：" << b->bedroom << endl;//friend_16类是 Building类的友元，可以访问类中的私有内容
}

void friend_16b::visit1() {
	cout << "我的朋友正在访问：" << b->sittingroom << endl;
	cout << "我的朋友正在访问：" << b->bedroom << endl;//friend_16b::visit1()成员函数是Building类的友元，可以访问类中的私有内容
}
void friend_16b::visit2() {
	cout << "我的朋友正在访问：" << b->sittingroom << endl;
	//cout << "我的朋友正在访问：" << b->bedroom << endl;//friend_16b::visit2()成员函数不是Building类的友元，不可以访问类中的私有内容
}


void myfriend_16() {//1.全局函数做友元
	Building_16 see;
	cout << "我的朋友正在访问：" << see.sittingroom << endl;
	cout << "我的朋友正在访问：" << see.bedroom << endl;//myfriend_16全局函数是 Building类的友元，可以访问类中的私有内容
}


//void main() {
//	myfriend_16();
//	friend_16a fria;
//	fria.visit();
//	friend_16b frib;
//	frib.visit1();
//	frib.visit2();
//}