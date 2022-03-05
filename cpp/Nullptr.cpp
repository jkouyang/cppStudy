/*nullptr 空指针
* 
    nullptr 出现的目的是为了替代 NULL。
    在某种意义上来说，传统 C++ 会把 NULL、0 视为同一种东西
    这取决于编译器如何定义 NULL，有些编译器会将 NULL 定义为 ((void*)0)，有些则会直接将其定义为 0
    C++ 不允许直接将 void * 隐式转换到其他类型

总结：
    C++11 引入了 nullptr 关键字，专门用来区分空指针、0
    nullptr能够隐式的转换为任何指针或成员指针的类型，也能和他们进行相等或者不等的比较
    建议使用nullptr，而非NULL
*/

#include<iostream>
#include <type_traits>
using namespace std;

void funcNullptr(int a) {
	cout << "funcNullptr(int a)" << endl;
}

void funcNullptr(char* a) {
	cout << "funcNullptr(char* a)" << endl;
}

void testNullptr() {
    //decltype()用于类型推导，而is_same()用于比较两个类型是否相同
    if (is_same<decltype(NULL), decltype(0)>::value) {
        cout << "NULL == 0" << endl;
    }   
    if (is_same<decltype(NULL), decltype((void*)0)>::value) {
        cout << "NULL == (void *)0" << endl;
    }
    if (is_same<decltype(NULL), nullptr_t>::value) {
        cout << "NULL == nullptr" << endl;
    }

    funcNullptr(0);// 调用(int)
    funcNullptr(NULL);//编译器认为NULL=0，调用(int)
    funcNullptr(nullptr);//调用(char*)
}

//void main() {
//	testNullptr();
//}