/*Day18 �̳�

��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������

������ʹ�ø��ֽ���̳еȣ���ɻ��Һ��˷ѿռ�(�̳���ͬһ����Ա)��ͬһ�����ݳ������Σ���ɶ�����
	������̳п��Խ������������  class A : virtual public B {};
*/

#include<iostream>
#include<string>
using namespace std;

class Per_18_2 {
public:
	int age;
};

class Per_18_2a :virtual public Per_18_2 {};

class Per_18_2b :virtual public Per_18_2 {};

class Per_18_2c :public Per_18_2a, public Per_18_2b {};

void test_18_2() {
	Per_18_2c p;

	cout << sizeof(Per_18_2c) << endl;

	//Per_18_2c�����age��Ա��ʵ�ǹ���һ�����ݣ�һ�����˾�ȫ����
	p.age = 10;
	cout << p.age << endl;
	cout << p.Per_18_2a::age << endl;
	cout << p.Per_18_2b::age << endl;

	p.Per_18_2a::age = 15;
	cout << p.age << endl;
	cout << p.Per_18_2a::age << endl;
	cout << p.Per_18_2b::age << endl;

}

//void main() {
//	test_18_2();
//	system("pause");
//}
