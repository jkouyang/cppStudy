/*Pair数据成对的出现
构造函数：
	1.pair<type, type> p (value1, value2);
	2.pair<type, type> p = make_pair(value1, value2);

嵌套使用：
	1.pair<type, pair<type,type>> p(value1, {value2, value3});

*/

#include<iostream>
#include<string>
using namespace std;

void testPair_1() {
	//1.pair<type, type> p(value1, value2);
	pair<string, int> p1("唐僧", 25);
	cout << "姓名：" << p1.first << "\t年龄：" << p1.second << endl;

	//2.pair<type, type> p = make_pair(value1, value2);
	pair<string, int> p2 = make_pair("孙悟空", 999);
	cout << "姓名：" << p2.first << "\t年龄：" << p2.second << endl;

	//嵌套使用
	//1.pair<type, pair<type,type>> p(value1, {value2, value3});
	pair<string, pair<int, int>>p3("猪八戒", { 765, 765 });
	cout << "姓名：" << p3.first << "\t年龄：" << p3.second.first << "\t年龄：" << p3.second.second << endl;

}

//void main() {
//	testPair_1();
//}