/* 虚析构和纯虚析构
多态使用时，如果子类中有属性开辟到堆区(用 new)，那么父类指针在释放时无法调用到子类的析构代码
	解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构(要声明也要实现)**

虚析构和纯虚析构共性：
	1.可以解决父类指针释放子类对象
	2.都需要有具体的函数实现
****纯虚析构函数和纯虚函数不一样，纯虚析构函数也需要实现(写在类外面)(因为父类也有空间要释放)

虚析构和纯虚析构区别：
	1.如果是纯虚析构，该类属于抽象类，无法实例化对象


总结：
​	1.虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
​	2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
​	3.拥有纯虚析构函数的类也属于抽象类
*/



#include<iostream>
#include<string>

using namespace std;

class Animal_19_5 {
public:
	Animal_19_5() {
		cout << "父类构造函数" << endl;
	}
	//virtual ~Animal_19_5() {//利用虚析构函数可以解决  父类指针无法释放子类对象时不干净的问题
	//	cout << "父类虚析构函数" << endl;
	//}

	virtual ~Animal_19_5() = 0;//需要声明，需要实现

	virtual void speak() = 0;
	
};

Animal_19_5::~Animal_19_5() {
	cout << "父类纯虚析构函数" << endl;
}

class Cat_19_5:public Animal_19_5 {
public:
	Cat_19_5(string name) {
		this->name = new string(name);//对象属性姓名存储在堆区域
		cout << "子类构造函数" << endl;
	}
	~Cat_19_5() {
		cout << "子类析构函数" << endl;
		if (name != NULL) {
			delete name;
			name = NULL;
		}
	}
	virtual void speak() {
		cout << *this->name <<"在说话" << endl;
	}
	string *name;

};

void test_19_5() {
	Animal_19_5 *animal = new Cat_19_5("Tom");//实例化的对象存储在堆区域
	animal->speak();
	delete animal;
	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
}

//void main() {
//	test_19_5();
//	system("pause");
//}