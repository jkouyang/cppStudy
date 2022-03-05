/*
"="符号重载
c++编译器至少给一个类添加4个函数

1. 默认构造函数(无参，函数体为空)
2. 默认析构函数(无参，函数体为空)
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符 operator=, 对属性进行值拷贝

如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
*/
#include<iostream>
#include<string>
using namespace std;

class Person_17_2 {
public:
	int *age;
	Person_17_2(int age) {
		this->age = new int(age);
	}

	~Person_17_2() {
		if (this->age != NULL) {
			delete this->age;//delete实际上是释放指针指向的内存空间
			this->age = NULL;//指针置空
		}
		cout << "释放" << endl;
	}

	Person_17_2& operator=(Person_17_2 &p) {
		if (this->age != NULL) {//先检查被赋值的类是否为空
			delete this->age;//delete实际上是释放指针指向的内存空间
			this->age = NULL;//指针置空
		}
		this->age = new int(*p.age);
		return *this;
	}
};

void test_17_2() {
	Person_17_2 p1(18);
	Person_17_2 p2(20);
	Person_17_2 p3(30);

	//Person_17_2 p3 = p2;//不要写这种，这是创建对象，对应的是构造函数，并没有定义这样的构造函数，编译器还是只会复制指针，释放时出错
	p3= p2 = p1;//赋值操作，没有问题
	cout << "p1.age:" << *p1.age << "\t\tp2.age" << *p2.age << "\t\tp3.age" << *p3.age << endl;//值
	cout << "&p1.age:" << p1.age << "\t&p2.age" << p2.age << "\t\t&p3.age" << p3.age << endl;//地址
}

//void main() {
//	test_17_2();
//	system("pause");
//}