/*Day18 继承
继承的好处：==可以减少重复的代码==

	语法: class 子类名:继承方式  父类名
	子类(派生类)父类(基类)
	派生类中的成员，包含两大部分:一类是从基类继承过来的，一类是自己增加的成员。

继承方式一共有三种：
	1.公共继承 public		继承下来的成员属性不改变
	2.保护继承 protected	继承下来的成员属性都变为protected
	3.私有继承 private		继承下来的成员属性都变为private
	****三种继承方式下，父类的私有成员都不可以继承

创建一个子类时：先调用父类构造函数，再调用子类构造函数
		释放时：先调用子类析构函数，再调用父类析构函数

子类父类中同名成员的处理方式：
		- 访问子类同名成员   直接访问即可
		- 访问父类同名成员   需要加作用域
*/

#include<iostream>
#include<string>
using namespace std;

class Father_18_1 {
public:
	Father_18_1() {
		cout << "父类构造函数" << endl;
	}
	Father_18_1(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
		cout << "父类构造函数" << endl;
	}
	~Father_18_1() {
		cout << "父类析构函数" << endl;
	}
public:
	int a;
protected:
	int b;
private:
	int c;//私有成员只是被隐藏了，但是还是会继承下去
};

class Son_18_1:public Father_18_1{
public:
	int a;
	int b;
	Son_18_1() {
		cout << "子类构造函数" << endl;
	}
	~Son_18_1() {
		cout << "子类析构函数" << endl;
	}
};

void test_18_1(){
	Son_18_1 son;
	//父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到
	cout << "sizeof Son = " << sizeof(Son_18_1) << endl;
	son.a = 10; //访问子类同名成员   直接访问即可
	son.Father_18_1::a = 20;//访问父类同名成员   需要加作用域
}

//void main() {
//	test_18_1();
//	system("pause");
//}


