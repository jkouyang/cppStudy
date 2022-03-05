/*auto
	ʹ��auto�����ı�������Ҫ���г�ʼ�������ñ������Ƶ�������ʵ�����ͣ��ڱ���ʱ��autoռλ���滻Ϊ����������

�﷨��auto ������ = ����ֵ;
	����������ָ�������������ʱ���Ƶ��Ľ���в��ᱣ�� const��volatile �ؼ���
	��������ָ�������������ʱ���Ƶ��Ľ���лᱣ�� const��volatile �ؼ���

auto ������
	1.������Ϊ��������ʹ��(C++20֧�֣�auto�����ں�������)
		��Ϊֻ���ں������õ�ʱ��Ż��������������ʵ��,autoҪ�����Ҫ�����εı�����ֵ����˶���ì��
	2.����������ķǾ�̬��Ա�����ĳ�ʼ��
	3.����ʹ�� auto �ؼ��ֶ�������
	4.�޷�ʹ�� auto �Ƶ���ģ�����

Ӧ�ã�
	1.���������Ƶ�������STL�����������������������Ƶ�
	2.���ڷ��ͱ�̣���ʹ��ģ���ʱ�򣬺ܶ���������ǲ�֪������Ӧ�ö���Ϊʲô����
*/

#include<iostream>
#include<vector>
using namespace std;

void testAuto() {
	auto a = 10;
	auto b = 3.14;
	vector<int> vect{ 1,2,3,4,5,6 };
	auto p = vect.begin();
}

//void main() {
//	testAuto();
//}


/* 1.������Ϊ��������ʹ��(C++20֧�֣�auto�����ں�������)
int func(auto a, auto b){
}
*/

/*2.����������ķǾ�̬��Ա�����ĳ�ʼ��
class Test{
	auto v1 = 0;//error
	static auto v2 = 0;//error����ķǳ�����Ա���������ڳ�ʼ��
	static const auto v3 = 10;// ok
}

*/
/*3.����ʹ�� auto �ؼ��ֶ�������
auto t3[] = {1,2,3,4,5};;   // error, auto�޷���������
*/

/*4.�޷�ʹ�� auto �Ƶ���ģ�����
template <class T>
class Test{}
Test<auto> aa;//error
*/