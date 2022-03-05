/*可调用对象	可调用对象包装器	绑定器
*******
可调用对象：
	1.函数、函数指针
	2.lambda表达式、函数对象——仿函数
	3.bind对象

********
可调用对象包装器：function()——实现调用语句的统一
语法：
	#include <functional>
	function<返回值类型(参数类型列表)> diy_name = 可调用对象;
	
	function可以将可调用对象进行包装，得到一个统一的格式
	包装完成得到的对象相当于一个函数指针，和函数指针的使用方式相同
	通过包装器对象就可以完成对包装的函数的调用了

********
绑定器：bind()——将可调用对象与其参数一起绑定成一个仿函数
语法：
	bind(可调用对象地址, 绑定的参数/占位符);

	bind用来绑定函数调用的参数
	有时不能一次性获得调用某个函数的全部参数，通过bind()，将部分调用参数提前绑定到函数身上
	成为一个新的对象，然后在参数齐全后，完成调用
	bind()将可调用对象与其参数一起绑定成一个仿函数

********
总结：统一化使用可调用对象
	仿函数名不可以作为函数指针(仿函数本质是类)
	普通函数名可以作为函数指针
*/

#include<iostream>
#include<string>
#include<vector>
#include <functional>
using namespace std;

int FunctionBind_a(int a, int b) {//普通函数
	return a + b;
}

class FunctionBind_b {//仿函数
public:
	int operator()(int a, int b) {
		return a - b;
	}
};

using ptrFunctionBind = int(*)(int, int);
int FunctionBind_c(ptrFunctionBind ptr, int a, int b) {//调用函数指针
	return ptr(a, b);//调用FunctionBind_a()函数
}

int FunctionBind_d(FunctionBind_b p, int a, int b) {//调用仿函数
	return p(a, b);//调用FunctionBind_b()仿函数
}

void testFunctionBind() {
//可调用对象——函数指针+仿函数		其他类推
	cout << FunctionBind_c(FunctionBind_a, 10, 10) << endl;//函数指针
	cout << FunctionBind_d(FunctionBind_b(), 20, 20) << endl;//仿函数	

//可调用对象包装器：function——实现调用语句的统一
	function<int(int, int)> fff;
	fff = FunctionBind_a;
	cout << fff(10, 10) << endl;
	fff = FunctionBind_b();
	cout << fff(10, 10) << endl;

//绑定器：bind()——将可调用对象与其参数一起绑定成一个仿函数
	auto ggg = bind(FunctionBind_a, placeholders::_1, 10);//使用时,不关心绑定器的返回值类型，使用auto接收
	//绑定FunctionBind_a可调用对象，其一共有两个参数
	//第一个参数被placeholders::_1占位(此处接收调用时传进来的第一个参数)，第二个参数为10
	cout << ggg(10) << endl;//绑定成一个仿函数，像仿函数一样使用，placeholders::_1=10
	cout << ggg(10,20,20,20) << endl;//placeholders::_1=10

	auto hhh = bind(FunctionBind_c, placeholders::_3, placeholders::_1, placeholders::_2);
	//绑定FunctionBind_c可调用对象，其一共有三个参数
	//第一个参数被placeholders::_3占位(接收调用时传进来的第3个参数)
	//第二个参数被placeholders::_1占位(接收调用时传进来的第1个参数)
	//第三个参数被placeholders::_2占位(接收调用时传进来的第2个参数)
	cout << hhh(10, 20, FunctionBind_a) << endl;

}

//void main() {
//	testFunctionBind();
//}