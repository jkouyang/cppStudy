/*
深拷贝与浅拷贝
	浅拷贝：简单的赋值拷贝操作
			不管对象的属性是什么数据类型，都是直接拷贝一份，如果是指针的话，其实只拷贝了地址，并没有复制数据
			对于指针，直接复制指针，没有复制数据(两个对象中的height指针存放的地址相同，指向同一个内存空间)
	深拷贝：在堆区重新申请空间，进行拷贝操作
			对于指针，先在堆区域复制一个原对象指针指向的数据，再将新对象的指针指向该数据(两个对象中的height指针存放的地址不同，但两个地址的数据相同)

****对象中成员含指针时，建议用深拷贝
*/

#include<iostream>
using namespace std;

class Person_11_4 {
public:
	int age;
	int *height;

	Person_11_4() {
		cout << "无参构造" << endl;
	}

	Person_11_4(int age, int height) {
		cout << "有参构造" << endl;
		this->age = age;
		this->height = new int(height);//new是在堆区重新开辟一个空间，并返回的是该数据类型的指针
	}

	Person_11_4(const Person_11_4 &p) {
		cout << "拷贝构造" << endl;
		this->age = p.age;
		
		//浅拷贝，对于指针，直接复制指针，没有复制数据(两个对象中的height指针存放的地址相同，指向同一个内存空间)
		//this->height = p.height;//用浅拷贝的时候，在两个对象的指针都释放的时候会报错
		
		//深拷贝，对于指针，先在堆区域复制一个原对象指针指向的数据，再将新对象的指针指向该数据(两个对象中的height指针存放的地址不同，但两个地址的数据相同)
		this->height = new int(*p.height);//用深拷贝时，对象含指针释放的时候也不会报错
	}

	~Person_11_4() {
		cout << "析构函数!" << endl;//析构函数将堆区域的变量释放
		if (height != NULL)
		{
			delete height;
			height = NULL;//置空，防止野指针出现
		}
	}
};

void test_11_4() {
	Person_11_4 person(24, 180);
	cout << "person\t\tage:" << person.age << "\thegiht" << *person.height << endl;
	Person_11_4 new_person(person);
	cout << "new_person\tage:" << person.age << "\thegiht" << *person.height << endl;
}

//void main() {
//	test_11_4();
//}