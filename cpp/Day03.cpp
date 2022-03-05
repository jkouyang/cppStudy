/*Day03
程序流程结构
    顺序结构
    选择结构：
            if，else if，else

            三目运算：表达式1?表达式2:表达式3     如果表达式1为真，执行表达式2并返结果，如果表达式1为假，执行表达式3并返回结果

            switch：注意不加break时switch语句会从第一个正确的case往下依次执行。
                    switch执行时判断的只能是整型或者字符型，不能是一个区间
                    switch的执行效率比if高
                    switch(表达式){
                        case 结果1：执行语句;break;
                        case 结果2：执行语句;break;
                        case 结果3：执行语句;break;
                        default:执行语句;break;

                    }

    循环结构：
            while
                while(循环条件){
                    循环语句}  //循环条件为真时就一直执行

            do while
                do{
                循环语句}
                while(循环条件)；//先执行循环语句，再判断循环条件，注意while后要加分号；

            for
                for(起始表达式；循环条件；末尾循环体){循环语句}
    
    跳转语句：break; 跳出循环结构或switch选择结构
              continue;在循环语句中跳出本次循环中余下尚未执行的语句，继续执行下一次循环
              goto;如果标记的名称存在，执行到goto语句时，会跳转到标记的位置

*/

#include <iostream>
#include <string>
using namespace std;

void Day03_if()
{
    int a = 10;
    int b = 0;
    cout << "请输入b" << endl;
    cin >> b;
    if (a > b){
        cout << "较大的数是" << a << endl;
    }
    else {
        cout << "较大的数是" << b << endl;    
    }
    int c = a > b ? a: b;//三目运算
    cout << "c是" << c << endl;


}

void Day03_for_continue() {
    //输出星图
    cout << endl << "输出星图" << endl;
    for (int i = 0; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        for (int j = 0; j <= i; j++) {
            cout << " *";
        }
        cout << endl;
    }
}


void Day03_goto() {
    cout << "1.xx" << endl;
    cout << "2.xx" << endl; 
    goto flag;//会跳转到标记的位置接着执行
    cout << "3.xx" << endl;
    cout << "4.xx" << endl;
    flag:
    cout << "5.xx" << endl;
    cout << "6.xx" << endl;

}

//void main()
//{
//    //Day03_if();
//    //Day03_for_continue();
//    Day03_goto();
//}