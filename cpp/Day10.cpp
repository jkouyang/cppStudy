/*Day10
类和对象-基础
	C++面向对象的三大特性为：==封装、继承、多态==
	(1)语法：class 类名{ 访问权限： 属性 / 行为  };
	(2)访问权限
			公共权限 public		成员 类内可以访问，类外可以访问
			保护权限 protected	成员 类内可以访问，类外不可访问		子类可以访问父类中的保护内容
			私有权限 private	成员 类内可以访问，类外不可访问		子类不以访问父类中的私有内容
	(3)stuct和class的比较
			在C++中 struct和class唯一的区别就在于默认的访问权限不同
			* struct 默认权限为公共
			* class  默认权限为私有
	(4)封装：成员属性设置为私有
		优点：将所有成员属性设置为私有，可以自己控制读写权限
			  对于写权限，我们可以检测数据的有效性
注意：同一个项目下结构体之间，类之间，结构体和类之间的命名都要不同
*/

#include<iostream>
#include<string>
using namespace std;

class stu_10 {
public:
	//属性  成员属性  成员变量
	string sName;
	int sId;

	//行为  成员函数  成员方法
	void set_sName(string name) {
		sName = name;
	}
	void set_sId(int id) {
		sId = id;
	}

	void showprint() {
		cout << "name:" << sName << "\tid:" << sId << endl;
	}
};

class tea_10 {
	//属性
public:
	string tName;
protected:
	int tId;
private:
	int tWage;

	//方法
public:
	void set_tea(string name, int id, int wage) {
		this->tName = name;
		this->tId = id;
		this->tWage = wage;
	}

	void showprint() {
		cout << "name:" << tName << "\tid:" << tId << "\t\twage:" << tWage << endl;
	}
};

struct test_101 {
	int struct_test = 10;//struct 默认权限为公共
};

class test_102 {
	int class_test = 10;//class  默认权限为私有
};

//void main() {
//	stu_10 tony;
//	//public类可以这样赋值
//	//tony.sName = "tony";
//	//tony.sId = 123;
//
//	tony.set_sName("tony");
//	tony.set_sId(123);
//	tony.showprint();
//
//	tea_10 mary;
//	mary.set_tea("mary",101,1000);
//	mary.showprint();
//	
//
//	test_101 a;
//	a.struct_test = 0;//可访问
//	test_102 b;
//	//b.struct_test = 0;//不可访问
//}