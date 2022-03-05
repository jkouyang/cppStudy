/*Day19:����������
�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������

��̬���ŵ㣺
	1.������֯�ṹ����
	2.�ɶ���ǿ
	3.����ǰ�ںͺ��ڵ���չ�Լ�ά��

C++�����ᳫ���ö�̬��Ƴ���ܹ�����Ϊ��̬�ŵ�ܶ�
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
		//���Ҫ�ṩ�µ����㣬��Ҫ�޸�Դ��
	}
public:
	int num1;
	int num2;

};

//��̬��ʵ�ּ�����
class AbstractCalculator_19_2 {//������
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

class Add_19_2: public AbstractCalculator_19_2 {//�ӷ���
public:
	Add_19_2(int a, int b) :AbstractCalculator_19_2(a,b) {}
	int getResult() {
		return num1+ num2;
	}
};

class Sub_19_2 : public AbstractCalculator_19_2 {//������
public:
	Sub_19_2(int a, int b) :AbstractCalculator_19_2(a, b) {}
	int getResult() {
		return num1 - num2;
	}
};

class Mul_19_2 : public AbstractCalculator_19_2 {//�˷���
public:
	Mul_19_2(int a, int b) :AbstractCalculator_19_2(a, b) {}
	int getResult() {
		return num1 * num2;
	}
};

void test_19_2a() {
	Calculator_19_2 c(10,10);

	cout << " ��ͨ����ʵ�ּ����� "  << endl;
	cout << c.num1 << " + " << c.num2 << " = " << c.getResult("+") << endl;
	cout << c.num1 << " - " << c.num2 << " = " << c.getResult("-") << endl;
	cout << c.num1 << " * " << c.num2 << " = " << c.getResult("*") << endl;
}

void test_19_2b() {
	cout << endl << " ��̬ʵ�ּ����� " << endl;

	AbstractCalculator_19_2* abc = new Add_19_2(100, 100);
	cout << abc->num1 << " + " << abc->num2 << " = " << abc->getResult() << endl;
	delete abc;//deleteֻ���ͷ�ָ��ָ��Ŀռ䣬�������ͷ�ָ�룬����ָ�벻���ٶ��壬ֻ�ø�һ��ָ����Ϳ���


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








