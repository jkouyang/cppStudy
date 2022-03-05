/*委托构造	继承构造	声明默认构造	拒绝默认构造
	委托构造：允许使用同一个类中的一个构造函数调用其它的构造函数
	继承构造：子类继承父类的构造函数，using 类名::构造函数名(其实类名和构造函数名是一样的)


	类名() = default; // 显式声明使用编译器生成的构造
	类名& operator=(const 类名&) = delete; // 显式声明拒绝编译器生成构造

}

*/

#include<iostream>
#include<string>
using namespace std;

//委托构造
class BaseConstructorNew {
public:
	int A;
	int B;
	string C;
	BaseConstructorNew() {}
	BaseConstructorNew(int a):BaseConstructorNew(){//委托构造
		this->A = a;
	}
	BaseConstructorNew(int a, int b) :BaseConstructorNew(a) {//委托构造
		this->B = b;
	}
	BaseConstructorNew(int a, int b, string c) :BaseConstructorNew(a, b) {//委托构造
		this->C = c;
	}
};

//继承构造
class SonConstructorNew: BaseConstructorNew {
	using BaseConstructorNew::BaseConstructorNew;//继承父类的所有构造方法
};


void testConstructorNew() {
	SonConstructorNew son(10, 20, "abcd");
}

//void main() {
//	testConstructorNew();
//}


