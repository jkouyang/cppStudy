/*	二进制的方式对文件进行读写操作
打开方式要指定为	ios::binary

写文件：
	二进制方式写文件主要利用流对象调用成员函数write
	函数原型 ：`ostream& write(const char * buffer,int len);`
	参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
	文件输出流对象 可以通过write函数，以二进制方式写数据

读文件：
	二进制方式读文件主要利用流对象调用成员函数read
	函数原型：`istream& read(char *buffer,int len);`
	参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
	文件输入流对象 可以通过read函数，以二进制方式读数据
*/

#include<iostream>
#include <fstream>
#include<string>
#include<vector>

using namespace std;

class Person_20_2{
public:
	char m_Name[64];
	int m_Age;
};

//二进制文件	写文件
void test_20_2a(){
	//写文件
	//1、包含头文件
	//2、创建输出流对象
	ofstream ofs("person.txt", ios::out | ios::binary);
	//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);
	Person_20_2 p = { "张三"  , 18 };
	//4、写文件
	ofs.write((const char*)&p, sizeof(p));
	//5、关闭文件
	ofs.close();

	//读文件
}

//二进制文件	读文件
void test_20_2b() {

	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person_20_2 p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}


//void main() {
//	test_20_2a();
//	system("pause");
//	test_20_2b();
//	system("pause");
//}