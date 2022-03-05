/*tuple	元组——用来存放多个不同类型的数据(加强版pair)

make_tuple: 构造元组
get: 获得元组某个位置的值
tie: 元组拆包


1.tuple初始化
	tuple<T1,T2,...Tn> tup;
	tuple<T1,T2,...Tn> tup(v1,v2,...vn);
	tuple(T1&) tup(tup1);
	make_tuple(v1,v2,...vn);

2.tuple的操作
	获取元素：
		2.1 get<ith>(tup)//获取下标为i的元素，要求ith为常数右值
		2.2 get<T>(tup)//获取数据类型为T的元素，要求元组中T的数据类型只有一个
		2.3 tie(elem1,elem2,...elemn)=tup;//拆包，元组中每个元素都接收
		2.4 tie(elem1,ignore,ignore,...)=tup;//拆包，不想接收的元素可以ignore
		2.5 tuple_cat(tup1,tup2);//合并两个元组
		2.6 tuple_size<decltype(tup)>::value//获取tup中有几个数据
		2.7 tuple_element<1, decltype(tup)>::type//获取tuo中下标为i的数据结果
*/

#include<iostream>
#include<string>
#include<tuple>
#include<variant>
using namespace std;

void testTuple() {
//1.元组初始化
	tuple<int, double, string> tup1;
	tuple<int, double, string> tup2(1,1.5,"hello");//小括号()和大括号{}都可
	tuple<int, double, string> tup3(tup2);
	tuple<int, double, string> tup4 = make_tuple(1, 1.5, "hello");

//2.tuple的操作
	//2.1 get<ith>(tup)//获取下标为i的元素，要求ith为常数右值
	cout << "get<2>(tup2): " << get<2>(tup2) << endl;
		//int i=2;get<i>(tup2);//错误
	
	//2.2 get<T>(tup)//获取数据类型为T的元素，要求元组中T的数据类型只有一个
	cout << "get<double>(tup2): " << get<double>(tup2) << endl;

	//2.3 tie(elem1, elem2, ...elemn) = tup;//拆包，元组中每个元素都接收
	int a; double b; string c;
	tie(a, b, c) = tup2;
	cout << a << " " << b << " "<< c << endl;

	//2.4 tie(elem1, ignore, ignore, ...) = tup;//拆包，不想接收的元素可以ignore
	int d; double e = 0.0; string f;
	tie(d, ignore, f) = tup2;
	cout << d << " " << e << " " << f << endl;

	//2.5 tuple_cat(tup1, tup2);//合并多个元组
	auto tup = tuple_cat(tup1, tup2, tup3, tup3);

	//2.6 tuple_size<decltype(tup)>::value//获取tup中有几个数据
	cout << "tup共有" << tuple_size<decltype(tup)>::value << "个数据" << endl;
	
	//2.7 tuple_element<1, decltype(tup)>::type
	tuple_element<1, decltype(tup1)>::type aa;//获取tuo中下标为i的数据结构
	decltype(get<1>(tup1)) bb = aa;//get<1>(tup1)为表达式，获得的为该位置的引用类型
}

//void main() {
//	testTuple();
//}
