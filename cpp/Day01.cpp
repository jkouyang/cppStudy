/*Day01
注释:
变量
常量：define,const
关键字
标识符：标识符（identifier）是指用来标识某个实体的一个符号，在不同的应用环境下有不同的含义。
        在计算机编程语言中，标识符是用户编程时使用的名字，用于给变量、常量、函数、语句块等命名，
        以建立起名称与使用之间的关系。标识符通常由字母和数字以及其它字符构成。
数据类型（意义：给变量分配合适的内存空间）
    整型：short 2B (-32768`32767), int 4B, long 4B, long long 8B
    浮点型：float 4B (7为有效数字)， double 8B （15-16位有效数字）
    字符型：char 1B （内存中存储的是ASCII编码），单引号‘’创建，(int)char,输出ASCII码，A:65,a:97
            转义字符：\n 换行，\t 水平制表符(作用：输出水平对齐)，\\ 反斜杠
    字符串型：char 变量名[]="字符串值"；(C语言风格)
              string 变量名= "字符串值"；(C++风格)，要导入头文件：#include<string>
    布尔类型：bool 1B，true(本质是1)，false(本质是0)
sizeof：sizeof(数据类型/变量)，统计数据类型所占内存大小
*/



#include <iostream>//预处理指令，告诉编译器在程序中要包含C++标准输入输出流头文件
#include <string>//字符串头文件
using namespace std;//标准命名空间，将一些实体（变量，函数，对象，类）放入其中，以解决同名冲突问题

#define Month 12 //define定义宏常量，不可修改

void typeData(){

    const int Day = 7; //const修饰的变量也为常量，不可修改
    cout << "一年有" << Month << "个月，一周有" << Day << "天" << endl;
    //cout为标准输出流，<<为流插入运算符，endl为流操纵算子，它发送一个换行符并刷新输出缓冲区


    //整型
    int a = 0;
    cout << "请输入整型a：" << endl;
    cin >> a;
    cout << "整型a=" << a << endl;

    //浮点型
    float f = 3.14f;//定义单精度数时后面加个f，防止编译器认为它是一个双精度数后再强制转换成单精度
    cout << "请输入浮点型f：" << endl;
    cin >> f;
    cout << "浮点型f=" << f << endl;

    //字符型
    char ch = 97;//ch='a';
    cout << "ch的初始值：" <<ch<< endl;
    cout << "请输入字符型ch：" << endl;
    cin >> ch;
    cout << "浮点型ch=" << ch << endl;

    //字符串型
    char str0[] = "Hello";
    string str = "hello";
    cout << "str的初始值：" << str << endl;
    cout << "请输入字符串型str：" << endl;
    cin >> str;
    cout << "字符串型str=" << str << endl;
    cout << "字符串型str所占内存空间(B)：" << sizeof(str) << endl;


    //布尔型
    bool flag = false;
    cout << "bool类型初始值 flag："  << flag << endl;
    cout << "请输入bool类型 flag：" << endl;
    cin >> flag;//任意非零的数都视为1，true
    cout << "bool类型 flag=" << flag << endl;

    system("pause");
}

//int main(){
//    typeData();
//    return 0;
//}