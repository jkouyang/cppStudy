/*constexpr
    const�ؼ������������壺����ֻ�������γ���
    constexpr�ؼ������������γ������ʽ��ָ�ľ����ɶ��������ɲ����ڱ�������о͵õ��������ı��ʽ

    C++ ����ӱ�д��ϵ�ִ�з�Ϊ�ĸ��׶Σ�Ԥ���� ���롢�������� 4 ���׶�
    �ǳ������ʽֻ���ڳ������н׶μ�������
    �������ʽ�ļ������������ڳ���ı���׶Σ�����Լ�����߳����ִ��Ч��

�ܽ᣺
    1.�� const �� constexpr �Ĺ������ֿ�
    2.��ֻ��������ĳ�����ʹ�� const��������������ĳ�����ʹ�� constexpr
    3.���峣��ʱ��const �� constexpr �ǵȼ۵ģ��������ڳ���ı���׶μ�������
    4.�������͵����ݣ�����ֱ���� constexpr ����
    5.�Զ�����������ͣ�ֱ����constexpr����struct��class�ǲ��еģ�ֻ�������䴴���Ķ���

����������
    1.��������Ҫ�з���ֵ������ return ���صı��ʽ�����ǳ������ʽ
    2.������ʹ��֮ǰ������Ҫ���壬��������ͨ����������������ʹ��ʱ�ٵ���
    3.���������ĺ������У����ܳ��ַǳ������ʽ֮������(C++11���ԣ�C++14������ʹ��)
      (using ָ�typedef ����Լ� static_assert ���ԡ�return ������)
      C++14��constexpr �����������ڲ�ʹ�þֲ�������ѭ���ͷ�֧�ȼ����
*/

#include<iostream>
using namespace std;

void testConst(const int num) {//����num��ֻ������
    const int a = 10;//����a�ǳ���
    int array1[10];
    int array2[a];
    //int array3[num]//������Ϊnum��ֻ���ı��������ǳ���
}

//constexpr��������
constexpr int testConstexpr1() {
    constexpr int a = 100;
    constexpr int b = 10;
    return a + b;
}

//C++14��constexpr�����������ڲ�ʹ�þֲ�������ѭ���ͷ�֧�ȼ����
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