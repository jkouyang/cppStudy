/*Day18 继承

多继承可能会引发父类中有同名成员出现，需要加作用域区分

不建议使用各种交叉继承等，造成混乱和浪费空间(继承了同一个成员)，同一个数据出现两次，造成二歧性
	利用虚继承可以解决二歧性问题  class A : virtual public B {};
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

	//Per_18_2c下面的age成员其实是共用一块数据，一个改了就全改了
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
