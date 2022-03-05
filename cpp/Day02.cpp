/*Day02
运算符类型
    算术运算符：+，-，*，/(两个数中只要有一个是浮点数，结果就算浮点数)
                %取模(取余)(只有整型可以进行取模，浮点数不能进行取模运算)
                ++(自加)，--(自减)
    赋值运算符：=，+=，-=，*=，/=，%=
    比较运算符：==，！=，<，>，<=，>=  (关系运算符)
    逻辑运算符：！，&&，||   （真为1，假为0）
    位运算符：


*/

#include <iostream>
#include <string>
using namespace std;

void Day02()
{
    int a = 10;
    int b = 3;
    double c = 10;
    double d = 3;

    cout << a / b << endl;
    cout << a / d << endl;
    cout << c / b << endl;
    cout << c / d << endl;

    cout << a % b << endl;

}


//void main()
//{
//    //调用另一个cpp文件的函数有两种方法
//    /*方法1
//    首先创建一个xxx.h头文件，声明函数aaa(int x,int y)
//    然后再创建一个与头文件同名的源文件xxx.cpp，在该文件中实现函数max(int x,int y)的功能
//    最后在需要调用的cpp文件中导入头文件 #inclued"xxx.h"
//
//    */
//    /*方法2
//    调用前声明一下Day01函数
//    因为在同一个project里面的源文件之间的函数一般情况下是可以互相调用的，前提是要声明以及不限制它的作用域！
//    */
//    //void Day01();
//    //Day01();
//
//    Day02();
//
//}