/*move()	forward()

* move()：将传入的值转化为右值(左值→右值，右值→右值)
  forward()：完美转发,解决右值引用是左值的问题
	  语法：forward<T>(t)
		  当T为左值引用类型时，t将被转换为T类型的左值
		  当T不是左值引用类型时，t将被转换为T类型的右值
*/

#include <iostream>
using namespace std;

template<typename T>
void printValue(T& t)//左值引用调用
{
    cout << "l-value: " << t << endl;
}

template<typename T>
void printValue(T&& t)//右值引用调用
{
    cout << "r-value: " << t << endl;
}

template<typename T>
void testForward(T&& v){
    //v接收一个右值引用，但v是左值
    printValue(v);
    printValue(move(v));//转化为右值
    printValue(forward<T>(v));//根据T的类型自动推导出左值还是右值
    cout << endl;
}


void testMoveForward() {
    testForward(520);//传入右值
    int num = 520;
    testForward(num);//传入左值
    testForward(forward<int>(num));//传入右值
    testForward(forward<int&>(num));//传入左值
    testForward(forward<int&&>(num));//传入右值
}

//void main(){
//    testMoveForward();
//}
