/*lambda表达式
	声明式的编程风格：就地匿名定义目标函数或函数对象，不需要额外写一个命名函数或函数对象
	lambda表达式的类型在C++11中会被看做是一个带operator()的类，即仿函数

语法：[capture](params) opt -> ret {body;};
	  其中capture是捕获列表，params是参数列表，opt是函数选项，ret是返回值类型，body是函数体
	
	1.捕获列表 []: 捕获一定范围内的变量
	2.参数列表 (): 和普通函数的参数列表一样，如果没有参数参数列表可以省略不写。
	3.opt 选项， 不需要可以省略
		mutable: 可以修改按值传递进来的拷贝（注意是能修改拷贝，而不是值本身）
		exception: 指定函数抛出的异常，如抛出整数类型的异常，可以使用 throw ();
	4.返回值类型：在 C++11 中，lambda 表达式的返回值是通过返回值后置语法来定义的。
	5.函数体：函数的实现，这部分不能省略，但函数体可以为空。

	1.捕获列表 []
		[]  - 不捕捉任何变量
		[&] - 捕获外部作用域中所有变量，并作为引用在函数体内使用 (按引用捕获)
		[=] - 捕获外部作用域中所有变量，并作为副本在函数体内使用 (按值捕获)
			  拷贝的副本在匿名函数体内部是只读的
		[=, &val] - 按值捕获外部作用域中所有变量，并按照引用捕获外部变量val
		[val] - 按值捕获 val 变量，同时不捕获其他变量
		[&val] - 按引用捕获 val 变量，同时不捕获其他变量
		[this] - 捕获当前类中的 this 指针
			让 lambda 表达式拥有和当前类成员函数同样的访问权限
			如果已经使用了 & 或者 =, 默认添加此选项

	2.匿名函数的就地定义
		function<void(int,int)> foo = [=, &a](int c,int d)mutable->void {}

总结：
	1.不指定 lambda 表达式的返回值，编译器会根据 return 语句自动推导返回值的类型
		但需要注意的是 labmda表达式不能通过列表初始化自动推导出返回值类型
	2.lambda表达式的类型在C++11中会被看做是一个带operator()的类，即仿函数
		因此可以使用std::function和std::bind来存储和操作lambda表达式
	3.lambda表达式的operator()默认是const的，一个const成员函数是无法修改成员变量值的
		mutable 选项的作用就在于取消operator()的const属性
	4.未捕获任何变量的 lambda 表达式，可以转换成一个普通的函数指针

*/

#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

vector<int> sortLambda(vector<int>& score) {
	vector<int> order;
	for (int i = 0; i < score.size(); i++) {
		order.push_back(i);
	}
	sort(order.begin(), order.end(), [&score](const int& a, const int& b) {return score[a] > score[b]; });
	//order本来是顺序0,1,2...，相当于下标，score的下标按score的值从大到小排序，排序后的下标记录在order中
	//这一招妙啊
	return order;
}

void testLambda() {
	int a = 10;
	int b = 10;
	string str = "hello";
	//就地匿名定义目标函数
	//function<void(int,int)> ,返回值为void，参数为(int,int)匿名函数
	function<void(int,int)> foo = [=, &a](int c,int d)mutable->void {
	//可用auto自动类型推导
		a = a + c ;
		// = 是拷贝副本(形参)，如果不加mutable，该形参仅是只读的
		b = b + d;//不加mutable，b的拷贝副本就不能修改
		str = "world";//不加mutable，str的拷贝副本就不能修改
		cout << a << "\t" << str << "\t" << b << endl;
		// & 捕获可以修改外部的值，= 捕获加mutable只能内部修改(修改拷贝副本的值)
	};
	foo(7,3);
	cout << a << "\t" << str << "\t" << b << endl;

	//就地匿名定义函数对象
	auto func = [](int a, int b)->bool {
		return a > b;
	};
	vector<int> vect{ 2,5,1,6,4,3,8,7,9 };
	sort(vect.begin(), vect.end(), func);//lambda表达式本质是仿函数
	for (auto& i : vect) { cout << i << " "; }
	cout << endl;
	//高级lambda表达式 sort()排序
	//vect的下标按vect的值从大到小排序，排序后的下标记录在order中，这一招妙啊
	vector<int> order = sortLambda(vect);

	//未捕获任何变量的 lambda 表达式，可以转换成一个普通的函数指针
	using funcPtr = bool(*)(int, int);
	funcPtr p = func;
	cout << p(2, 1) << endl;
}

//void main() {
//	testLambda();
//}