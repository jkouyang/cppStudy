/*�ڽ��������󡪡�STL�ڽ���һЩ��������
����:
1.�����º���
2.��ϵ�º���
3.�߼��º���

�÷���
1.��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
2.ʹ���ڽ�����������Ҫ����ͷ�ļ� #include<functional>
*/

/*�����º���
����������
	ʵ����������
	����negate��һԪ���㣬�������Ƕ�Ԫ����

**�º���ԭ�ͣ�**
	1.template<class T> T plus<T>//�ӷ��º���
	2.template<class T> T minus<T>//�����º���
	3.template<class T> T multiplies<T>//�˷��º���
	4.template<class T> T divides<T>//�����º���
	5.template<class T> T modulus<T>//ȡģ�º���
	6.template<class T> T negate<T>//ȡ���º���

	*����negate��һԪ���㣬�������Ƕ�Ԫ����
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void testFunobj_3() {
	//+
	plus<int> p1;//��Ϊֻ��ͬ������������ӣ����Դ�һ���������;Ϳ�����
	cout << p1(10, 20) << endl;
	//-
	minus<double> p2;
	cout << p2(10.23, 20) << endl;
	//*
	multiplies<double> p3;
	cout << p3(3.15, 2) << endl;
	//��
	divides<double> p4;
	cout << p4(10.23, 2) << endl;
	//%
	modulus<int> p5;
	cout << p5(10, 3) << endl;
	//ȡ��
	negate<int> p6;
	cout << p6(10) << endl;

}

//void main() {
//	testFunobj_3();
//}