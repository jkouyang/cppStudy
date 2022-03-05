/*move()	forward()

* move()���������ֵת��Ϊ��ֵ(��ֵ����ֵ����ֵ����ֵ)
  forward()������ת��,�����ֵ��������ֵ������
	  �﷨��forward<T>(t)
		  ��TΪ��ֵ��������ʱ��t����ת��ΪT���͵���ֵ
		  ��T������ֵ��������ʱ��t����ת��ΪT���͵���ֵ
*/

#include <iostream>
using namespace std;

template<typename T>
void printValue(T& t)//��ֵ���õ���
{
    cout << "l-value: " << t << endl;
}

template<typename T>
void printValue(T&& t)//��ֵ���õ���
{
    cout << "r-value: " << t << endl;
}

template<typename T>
void testForward(T&& v){
    //v����һ����ֵ���ã���v����ֵ
    printValue(v);
    printValue(move(v));//ת��Ϊ��ֵ
    printValue(forward<T>(v));//����T�������Զ��Ƶ�����ֵ������ֵ
    cout << endl;
}


void testMoveForward() {
    testForward(520);//������ֵ
    int num = 520;
    testForward(num);//������ֵ
    testForward(forward<int>(num));//������ֵ
    testForward(forward<int&>(num));//������ֵ
    testForward(forward<int&&>(num));//������ֵ
}

//void main(){
//    testMoveForward();
//}
