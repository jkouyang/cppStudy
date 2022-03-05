/*constexpr
    const关键字有两层语义：变量只读、修饰常量
    constexpr关键字是用来修饰常量表达式：指的就是由多个常量组成并且在编译过程中就得到计算结果的表达式

    C++ 程序从编写完毕到执行分为四个阶段：预处理、 编译、汇编和链接 4 个阶段
    非常量表达式只能在程序运行阶段计算出结果
    常量表达式的计算往往发生在程序的编译阶段，这可以极大提高程序的执行效率

总结：
    1.将 const 和 constexpr 的功能区分开
    2.表达“只读”语义的场景都使用 const，表达“常量”语义的场景都使用 constexpr
    3.定义常量时，const 和 constexpr 是等价的，都可以在程序的编译阶段计算出结果
    4.内置类型的数据，可以直接用 constexpr 修饰
    5.自定义的数据类型，直接用constexpr修饰struct或class是不行的，只能修饰其创建的对象

常量函数：
    1.函数必须要有返回值，并且 return 返回的表达式必须是常量表达式
    2.函数在使用之前，必须要定义，不能像普通函数那样先声明，使用时再调用
    3.整个函数的函数体中，不能出现非常量表达式之外的语句(C++11特性，C++14后允许使用)
      (using 指令、typedef 语句以及 static_assert 断言、return 语句除外)
      C++14后constexpr 函数可以在内部使用局部变量、循环和分支等简单语句
*/

#include<iostream>
using namespace std;

void testConst(const int num) {//表明num是只读变量
    const int a = 10;//表明a是常量
    int array1[10];
    int array2[a];
    //int array3[num]//报错，因为num是只读的变量，不是常量
}

//constexpr常量函数
constexpr int testConstexpr1() {
    constexpr int a = 100;
    constexpr int b = 10;
    return a + b;
}

//C++14后constexpr函数可以在内部使用局部变量、循环和分支等简单语句
constexpr int testConstexpr2(const int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return testConstexpr2(n - 1) + testConstexpr2(n - 2);
}

//void main() {
//    testConst(10);
//	testConstexpr1();
//    testConstexpr2(10);
//}