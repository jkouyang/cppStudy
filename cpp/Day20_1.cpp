/*Day20 文件输入输出
C++中对文件操作需要包含头文件 <fstream>

文件类型分为两种：
	1.文本文件   -  文件以文本的ASCII码形式存储在计算机中
	2.二进制文件 -  文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

操作文件的三大类:
	1.ofstream：写操作
	2.ifstream：读操作
	3.fstream ：读写操作

写文件步骤如下：
	1.包含头文件	#include <fstream>
	2.创建流对象	ofstream ofs;
	3.打开文件		ofs.open("文件路径",打开方式);
	4.写数据		ofs << "写入的数据";
	5.关闭文件		ofs.close();

文件的打开方式
	| 打开方式    | 解释                       |
	| ----------- | -------------------------- |
	| ios::in     | 为读文件而打开文件         |
	| ios::out    | 为写文件而打开文件         |
	| ios::ate    | 初始位置：文件尾           |
	| ios::app    | 追加方式写文件             |
	| ios::trunc  | 如果文件存在先删除，再创建 |
	| ios::binary | 二进制方式                 |


读文件步骤如下：
	1.包含头文件						#include <fstream>
	2.创建流对象						ifstream ifs;
	3.打开文件并判断文件是否打开成功	ifs.open("文件路径",打开方式);
	4.读数据							四种方式读取
	5.关闭文件							ifs.close();

*/
#include<iostream>
#include<string>
#include<fstream>


using namespace std;

void test_20_1a(){
	ofstream ofs;
	ofs.open("test.txt", ios::out);

	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	ofs.close();
}

void test_20_1b()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}


	////四种读文件的操作
	////第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	////第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	////第四种
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;
	//}

	ifs.close();

}

//void main() {
//
//	test_20_1a();
//	system("pause");
//	test_20_1b();
//	system("pause");
//
//}