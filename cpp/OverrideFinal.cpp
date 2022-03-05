/*override	final
* 
	override：确保在派生类中声明的重写函数与基类的虚函数有相同的签名，同时也明确表明将会重写基类的虚函数
	final：限制某个类不能被继承，或者某个虚函数不能被重写
*/

#include<iostream>
#include<string>
using namespace std;

class BaseOverrideFinal {
public:
	virtual void func1() final{//final修饰函数(只能是虚函数)，该虚函数不能在子类被重写(可以重载)，子类能使用该虚函数
	}
	
	virtual void func2(){
	}
};

class SonOverrideFinal final :BaseOverrideFinal {//final修饰类，该类不能被继承
	virtual void func2() override {//override修饰函数，重写基类函数
	}
};