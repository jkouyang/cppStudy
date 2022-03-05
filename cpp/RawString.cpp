/*原始字符串
语法:	R "xxx(原始字符串)xxx"
	原始字面量 R 可以直接表示字符串的实际含义，而不需要额外对字符串做转译或连接等操作
	原始字符串必须用括号()括起来
	括号的前后可以加其他字符串，所加的字符串会被忽略，并且加的字符串必须相同且在括号两边同时出现

适用：
	1.含有转义字符的，想要直接表达字符串含义
	2.字符串较长，想要写多行——没啥用
*/

#include<iostream>
#include<string>
using namespace std;

void testRawString() {
	//1.含有转义字符的，想要直接表达字符串含义
	string str1 = "D:\\hello\\world\\test.text";
	cout << str1 << endl;
	string str2 = R"(D:\hello\world\test.text)";
	cout << str2 << endl;

	//2.raw string可以跨越多行，其中的空白和换行符都属于字符串的一部分
	string str3 = "<html>\
					<head>\
					<title>\ ";
	cout << str3 << endl;
	string str4 = R"(
				<html>
				<head>
				<title>)";
	cout << str4 << endl;

}

//void main() {
//	testRawString();
//}