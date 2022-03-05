/*auto
	使用auto声明的变量必须要进行初始化，以让编译器推导出它的实际类型，在编译时将auto占位符替换为真正的类型

语法：auto 变量名 = 变量值;
	当变量不是指针或者引用类型时，推导的结果中不会保留 const、volatile 关键字
	当变量是指针或者引用类型时，推导的结果中会保留 const、volatile 关键字

auto 的限制
	1.不能作为函数参数使用(C++20支持，auto能用于函数传参)
		因为只有在函数调用的时候才会给函数参数传递实参,auto要求必须要给修饰的变量赋值，因此二者矛盾
	2.不能用于类的非静态成员变量的初始化
	3.不能使用 auto 关键字定义数组
	4.无法使用 auto 推导出模板参数

应用：
	1.用于类型推导，例如STL的容器迭代器的数据类型推导
	2.用于泛型编程，在使用模板的时候，很多情况下我们不知道变量应该定义为什么类型
*/

#include<iostream>
#include<vector>
using namespace std;

void testAuto() {
	auto a = 10;
	auto b = 3.14;
	vector<int> vect{ 1,2,3,4,5,6 };
	auto p = vect.begin();
}

//void main() {
//	testAuto();
//}


/* 1.不能作为函数参数使用(C++20支持，auto能用于函数传参)
int func(auto a, auto b){
}
*/

/*2.不能用于类的非静态成员变量的初始化
class Test{
	auto v1 = 0;//error
	static auto v2 = 0;//error，类的非常量成员不能再类内初始化
	static const auto v3 = 10;// ok
}

*/
/*3.不能使用 auto 关键字定义数组
auto t3[] = {1,2,3,4,5};;   // error, auto无法定义数组
*/

/*4.无法使用 auto 推导出模板参数
template <class T>
class Test{}
Test<auto> aa;//error
*/