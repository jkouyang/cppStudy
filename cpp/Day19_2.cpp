/*Day19:案例描述：
分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

多态的优点：
	1.代码组织结构清晰
	2.可读性强
	3.利于前期和后期的扩展以及维护

C++开发提倡利用多态设计程序架构，因为多态优点很多
*/


#include<iostream>
#include<string>

using namespace std;


class Calculator_19_2 {
public:
	Calculator_19_2(int a,int b) {
		this->num1 = a;
		this->num2 = b;
	}
	int getResult(string oper)
	{
		if (oper == "+") {
			return num1 + num2;
		}
		else if (oper == "-") {
			return num1 - num2;
		}
		else if (oper == "*") {
			return num1 * num2;
		}
		//如果要提供新的运算，需要修改源码
	}
public:
	int num1;
	int num2;

};

//多态来实现计算器
class AbstractCalculator_19_2 {//抽象类
public:
	AbstractCalculator_19_2(int a, int b) {
		this->num1 = a;
		this->num2 = b;
	}
	virtual int getResult() {
		return 0;
	}
	int num1;
	int num2;
};

class Add_19_2: public AbstractCalculator_19_2 {//加法类
public:
	Add_19_2(int a, int b) :AbstractCalculator_19_2(a,b) {}
	int getResult() {
		return num1+ num2;
	}
};

class Sub_19_2 : public AbstractCalculator_19_2 {//减法类
public:
	Sub_19_2(int a, int b) :AbstractCalculator_19_2(a, b) {}
	int getResult() {
		return num1 - num2;
	}
};

class Mul_19_2 : public AbstractCalculator_19_2 {//乘法类
public:
	Mul_19_2(int a, int b) :AbstractCalculator_19_2(a, b) {}
	int getResult() {
		return num1 * num2;
	}
};

void test_19_2a() {
	Calculator_19_2 c(10,10);

	cout << " 普通方法实现计算器 "  << endl;
	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;
}

void test_19_2b() {
	cout << endl << " 多态实现计算器 " << endl;

	AbstractCalculator_19_2* abc = new Add_19_2(100, 100);
	cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;//delete只是释放指针指向的空间，并不是释放指针，后面指针不用再定义，只用改一下指向方向就可以


	abc = new Sub_19_2(100, 100);
	cout << abc->num1 << " - " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;

	abc = new Mul_19_2(100, 100);
	cout << abc->num1 << " * " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;
}

//void main() {
//	test_19_2a();
//	test_19_2b();
//	system("pause");
//}








