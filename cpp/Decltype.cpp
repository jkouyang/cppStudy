/*decltype
	Ϊ���autoֻ�ܶԱ������������Ƶ���ȱ�ݣ�decltype�ɶԱ��ʽ�����Ƶ�

�﷨��decltype (���ʽ)
	1.���ʽΪ��ͨ����������ͨ���ʽ��������ʽ������������£�ʹ�� decltype �Ƶ��������ͺͱ��ʽ��������һ�µ�
	2.���ʽ�Ǻ������ã�ʹ�� decltype �Ƶ��������ͺͺ�������ֵһ�¡�
	3.���ʽ����ֵ�����߱�()��Χ��decltype�Ƶ������Ǳ��ʽ���͵�����(����� const��volatile�޶������ܺ���)

Ӧ�ã�decltype ��Ӧ�ö�����ڷ��ͱ����

*/

#include<iostream>
#include<vector>
using namespace std;

double testDecltypeFunc() { return 0.1; }

void testDecltype() {
	int a = 10;
	//1.��ͨ����������ͨ���ʽ��������ʽ���Ƶ��������ͺͱ��ʽ��������һ�µ�
	decltype(a) b;
	//2.���ʽ�Ǻ������ã�ʹ�� decltype �Ƶ��������ͺͺ�������ֵһ��
	decltype(testDecltypeFunc()) c;
	//3.���ʽ����ֵ�����߱�()��Χ��decltype�Ƶ������Ǳ��ʽ���͵�����(����� const��volatile�޶������ܺ���)
	decltype((a)) d = a;//()��Χ
	int m;
	decltype(m = a + b) e = a;//��ֵ
}

//�������ͺ��ã�C++14�����ֱ��ʹ��auto��Ϊ����ֵ����
template <typename T, typename U>
//auto add(T t, U u) -> decltype(t + u)  //C++11
auto add(T t, U u)//C++14
{
	return t + u;
}


//void main() {
//	testDecltype();
//}


