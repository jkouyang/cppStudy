/*C++11 中提供了专门的类型转换函数，可以非常方便的使用它们进行数值类型和字符串类型之间的转换

*数字型→字符串
	to_string();

*字符串→数字型
	int stoi();
	float stof();
	double stod();
	long stol();

* 总结：
	如果字符串中所有字符都是数值类型，整个字符串会被转换为对应的数值，并通过返回值返回
	如果字符串的前半部分字符是数值类型，后半部不是，那么前半部分会被转换为对应的数值，并通过返回值返回
	如果字符第一个字符不是数值类型转换失败
*/

#include<iostream>
#include<string>
using namespace std;

void testStrNum() {
//1.数字型→字符串	to_string();
	int int_a = 5;
	string str_a = to_string(int_a);
	cout << "str_a: " << str_a << endl;
	cout << "====================" << endl;

//2.字符串→数字型
	string str1 = "45";
	string str2 = "3.1415926546545654654654645678687987987978978978978935898";
	string str3 = "9527 with words";
	string str4 = "words and 2";

	int myint1 = std::stoi(str1);
	float myfloat = std::stof(str2);
	double mydouble = stod(str2);
	int myint2 = std::stoi(str3);
	// 错误： 'std::invalid_argument'
	// int myint4 = std::stoi(str4);

	cout.precision(100);
	cout << "myint1: " << myint1 << endl;
	cout << "myflate: " << myfloat << endl;
	cout << "mydouble: " << mydouble << endl;
	cout << "myint2: " << myint2 << endl;

}

//void main() {
//	testStrNum();
//}