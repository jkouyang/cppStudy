/*字符串的查找和替换
* 查找：查找指定字符串是否存在
* 替换：在指定的位置替换字符串

==============================================================================================
* int find(const string& str, int pos = 0) const;		//查找str第一次出现位置,从pos开始查找
* int find(const char* s, int pos = 0) const; 			//查找s第一次出现位置,从pos开始查找
* int find(const char* s, int pos, int n) const;		//从pos位置查找s的前n个字符第一次位置
* int find(const char c, int pos = 0) const;			//查找字符c第一次出现位置
* int rfind(const string& str, int pos = npos) const;	//查找str最后一次位置,从pos开始查找
* int rfind(const char* s, int pos = npos) const;		//查找s最后一次出现位置,从pos开始查找
* int rfind(const char* s, int pos, int n) const;		//从pos查找s的前n个字符最后一次位置
* int rfind(const char c, int pos = 0) const;			//查找字符c最后一次出现位置
* string& replace(int pos, int n, const string& str);	//替换从pos开始n个字符为字符串str
* string& replace(int pos, int n,const char* s);		//替换从pos开始的n个字符为字符串s

*/


#include<iostream>
#include<string>
using namespace std;

void testStr_4a() {
	string str1 = "abcdefgde";
	//1.利用find()函数从左至右查找第一个出现的地方
	int pos1 = str1.find("de");//利用find()函数查找，找到返回下标，没找到返回-1
	int pos2 = str1.find("df");//利用find()函数查找，找到返回下标，没找到返回-1
	cout << "de的下标" << pos1 << endl;
	cout << "df的下标" << pos2 << endl;


	//2.利用rfind()函数从右至左查找第一个出现的地方
	int pos3 = str1.rfind("de");
	int pos4 = str1.rfind("df");
	cout << "de的下标" << pos3 << endl;
	cout << "df的下标" << pos4 << endl;
}

void testStr_4b() {
	string str2 = "abcdefg";
	//利用replace()函数将字符串从pos下标开始n个字符替换为新串
	str2 = str2.replace(1, 3, "12345");
	cout << "str2=" << str2 << endl;
}

//void main() {
//	testStr_4a();
//	testStr_4b();
//}