/*main()
	写法只有两种，注意一定要返回值int，判断程序执行情况
	int main(){};
	int main(int argc, char* argv[]){};//argc为传入参数的数量，argv[]是指向传入参数的字符串（指针数组）

调试：
	修改调试中项目规属性的命令参数
*/


#include<iostream>
#include<string>
using namespace std;

//int main(int   argc, char* argv[]) {
//	for (int i = 0; i < argc; i++) {
//		cout << "argv[" << i << "]:" << argv[i] << endl;
//	}
//	char* pChar = argv[0];//存放的是char*类型，在c++下可视为字符串
//	//int 速度aa = stoi(argv[1]);
//	string str = argv[0];
//	cout << pChar << endl;
//	cout << str << endl;
//	cout << "程序结束" << endl;
//	return   0;
//}