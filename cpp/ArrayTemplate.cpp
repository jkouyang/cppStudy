//模板

#include"MyArray.hpp"
//对内置数据类型的数据进行存储
void print1_ArrayTemplate(myArray<int> &arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "数组中第" << i << "个元素为：" << arr[i] << endl;
	}
}

void test1_ArrayTemplate() {
	myArray<int> arr(5);
	for (int i = 0; i < 5; i++) {
		arr.Push_back(i);
	}
	print1_ArrayTemplate(arr);
	cout << "arr容量：" << arr.getCapacity() << endl;
	cout << "arr大小：" << arr.getSize() << endl;
	arr.Pop_back(); arr.Pop_back();
	print1_ArrayTemplate(arr);
	cout << "arr容量：" << arr.getCapacity() << endl;
	cout << "arr大小：" << arr.getSize() << endl;
}

//对自定义数据类型的数据进行存储
class Person_ArrayTemplate {
public:
	string name;
	int age;
	Person_ArrayTemplate() {}
	Person_ArrayTemplate(string name,int age) {
		this->name = name;
		this->age = age;
	}
};

void print2_ArrayTemplate(myArray<Person_ArrayTemplate>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "姓名：" << arr[i].name << "\t年龄：" << arr[i].age << endl;
	}
}

void test2_ArrayTemplate() {
	Person_ArrayTemplate p1("唐僧",25);
	Person_ArrayTemplate p2("孙悟空", 999);
	Person_ArrayTemplate p3("猪八戒", 798);
	Person_ArrayTemplate p4("沙僧", 658);
	Person_ArrayTemplate p5("白龙马", 452);

	myArray<Person_ArrayTemplate> arr(10);//在创建myArray对象时会构造Person_ArrayTemplate空类，所以要提供类的空构造函数
	arr.Push_back(p1);
	arr.Push_back(p2);
	arr.Push_back(p3);
	arr.Push_back(p4);
	arr.Push_back(p5);
	
	print2_ArrayTemplate(arr);
	cout << "arr容量：" << arr.getCapacity() << endl;
	cout << "arr大小：" << arr.getSize() << endl;
	arr.Pop_back(); arr.Pop_back();

	print2_ArrayTemplate(arr);
	cout << "arr容量：" << arr.getCapacity() << endl;
	cout << "arr大小：" << arr.getSize() << endl;
}

//void main() {
//	cout << "===============对内置数据类型的数据进行存储=================" << endl;
//	test1_ArrayTemplate();
//	cout << endl << "===============对自定义数据类型的数据进行存储===============" << endl;
//	test2_ArrayTemplate();
//}