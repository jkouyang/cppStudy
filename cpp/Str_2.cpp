/*string赋值操作
*赋值方法：
	1.str1 = "hello";				//char*类型字符串，赋值给当前的字符串
	2.str2 = str1;					//把字符串s赋给当前的字符串
	3.str3 = 'a';					//字符赋值给当前的字符串
	4.str4.assign("hello C++");		//把字符串s赋给当前的字符串
	5.str5.assign("hello C++",n);	//把字符串s的前n个字符赋给当前的字符串
	6.str6.assign(str4);			//把字符串s赋给当前字符串
	7.str7.assign(n, 'a');			//用n个字符c赋给当前字符串

*/

#include<iostream>
#include<string>
using namespace std;

void testStr_2() {
	string str1;
	str1 = "hello";//1.字符串常量赋值给当前字符串
	cout << "str1=" << str1 << endl;

	string str2;
	str2 = str1;//2.把一个字符串的值赋值给另一个字符串
	cout << "str2=" << str2 << endl;

	string str3;
	str3 = 'a';//3.给字符串赋值一个字符
	cout << "str3=" << str3 << endl;

	string str4;
	str4.assign("hello C++");//4.利用assign()函数，把字符串常量赋值给当前字符串
	cout << "str4=" << str4 << endl;

	string str5;
	str5.assign("hello C++",5);//5.利用assign()函数，把字符串常量的前n个字符赋值给当前字符串
	cout << "str5=" << str5 << endl;

	string str6;
	str6.assign(str4);//6.利用assign()函数，把一个字符串的值赋值给另一个字符串
	cout << "str6=" << str6 << endl;

	string str7;
	str7.assign(10, 'a');//7.利用assign()函数，给字符串赋值n个连续的字符
	cout << "str7=" << str7 << endl;

}

//void main() {
//	testStr_2();
//}