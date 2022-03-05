/*字符串拼接
	1.string& operator+=(const char* str);				//重载+=操作符
	2.string& operator+=(const char c);					//重载+=操作符
	3.string& operator+=(const string& str);				//重载+=操作符
	4.string& append(const char *s);						//把字符串常量s连接到当前字符串结尾
	5.string& append(const char *s, int n);				//把字符串常量s的前n个字符连接到当前字符串结尾
	6.string& append(const char *s, int pos, int n);		//把字符串常量s从下标pos开始到结尾的字符连接到字符串结尾
	7.string& append(const string &s);					//同operator+=(const string& str)
	8.string& append(const string &s, int pos);			//字符串s中从下标pos开始到结尾的字符连接到字符串结尾
	9.string& append(const string &s, int pos, int n);	//字符串s中从下标pos开始的n个字符连接到字符串结尾

*/


#include<iostream>
#include<string>
using namespace std;

void testStr_3() {
	string str1 = "好好学习";
	string str2 = "天天向上";
	str1 +=  "哦";//1.重载+=操作符，追加字符串常量
	cout << "str1=" << str1 << endl;

	str1 = "好好学习";
	str2 = "天天向上";
	str1 += 'o';//2.重载+=操作符，追加字符常量
	cout << "str1=" << str1 << endl;

	str1 = "好好学习";
	str2 = "天天向上";
	str1 += str2;//3.重载+=操作符，追加字符串
	cout << "str1=" << str1 << endl;

	str1 = "好好学习";
	str2 = "天天向上";
	string str = str1.append("哦哦");//4.使用append()函数将字符串常量加到该字符串的尾部
	cout << "str=" << str << endl;

	str1 = "好好学习";
	str2 = "12345678";
	str = str1.append("12345678", 3);//5.使用append()函数将字符串常量前n个字符加到该字符串的尾部
	cout << "str=" << str << endl;

	str1 = "好好学习";
	str2 = "12345678";
	str = str1.append("12345678", 2, 3);//6.使用append()函数将字符串常量从下标为n1开始的n2个字符加到该字符串的尾部
	cout << "str=" << str << endl;

	str1 = "好好学习";
	str2 = "12345678";
	str = str1.append(str2);//7.使用append()函数将一个字符串加到另一个字符串的尾部
	cout << "str=" << str << endl;

	str1 = "好好学习";
	str2 = "12345678";
	str = str1.append(str2,2);//8.使用append()函数将一个字符串从下标为n到末尾的字符加到另一个字符串的尾部
	cout << "str=" << str << endl;

	str1 = "好好学习";
	str2 = "12345678";
	str = str1.append(str2, 2, 4);//9.使用append()函数将一个字符串从下标为n1开始的n2个字符加到该字符串的尾部
	cout << "str=" << str << endl;

}

//void main() {
//	testStr_3();
//}