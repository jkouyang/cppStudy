/*�ɵ��ö���	�ɵ��ö����װ��	����
*******
�ɵ��ö���
	1.����������ָ��
	2.lambda���ʽ���������󡪡��º���
	3.bind����

********
�ɵ��ö����װ����function()����ʵ�ֵ�������ͳһ
�﷨��
	#include <functional>
	function<����ֵ����(���������б�)> diy_name = �ɵ��ö���;
	
	function���Խ��ɵ��ö�����а�װ���õ�һ��ͳһ�ĸ�ʽ
	��װ��ɵõ��Ķ����൱��һ������ָ�룬�ͺ���ָ���ʹ�÷�ʽ��ͬ
	ͨ����װ������Ϳ�����ɶ԰�װ�ĺ����ĵ�����

********
������bind()�������ɵ��ö����������һ��󶨳�һ���º���
�﷨��
	bind(�ɵ��ö����ַ, �󶨵Ĳ���/ռλ��);

	bind�����󶨺������õĲ���
	��ʱ����һ���Ի�õ���ĳ��������ȫ��������ͨ��bind()�������ֵ��ò�����ǰ�󶨵���������
	��Ϊһ���µĶ���Ȼ���ڲ�����ȫ����ɵ���
	bind()���ɵ��ö����������һ��󶨳�һ���º���

********
�ܽ᣺ͳһ��ʹ�ÿɵ��ö���
	�º�������������Ϊ����ָ��(�º�����������)
	��ͨ������������Ϊ����ָ��
*/

#include<iostream>
#include<string>
#include<vector>
#include <functional>
using namespace std;

int FunctionBind_a(int a, int b) {//��ͨ����
	return a + b;
}

class FunctionBind_b {//�º���
public:
	int operator()(int a, int b) {
		return a - b;
	}
};

using ptrFunctionBind = int(*)(int, int);
int FunctionBind_c(ptrFunctionBind ptr, int a, int b) {//���ú���ָ��
	return ptr(a, b);//����FunctionBind_a()����
}

int FunctionBind_d(FunctionBind_b p, int a, int b) {//���÷º���
	return p(a, b);//����FunctionBind_b()�º���
}

void testFunctionBind() {
//�ɵ��ö��󡪡�����ָ��+�º���		��������
	cout << FunctionBind_c(FunctionBind_a, 10, 10) << endl;//����ָ��
	cout << FunctionBind_d(FunctionBind_b(), 20, 20) << endl;//�º���	

//�ɵ��ö����װ����function����ʵ�ֵ�������ͳһ
	function<int(int, int)> fff;
	fff = FunctionBind_a;
	cout << fff(10, 10) << endl;
	fff = FunctionBind_b();
	cout << fff(10, 10) << endl;

//������bind()�������ɵ��ö����������һ��󶨳�һ���º���
	auto ggg = bind(FunctionBind_a, placeholders::_1, 10);//ʹ��ʱ,�����İ����ķ���ֵ���ͣ�ʹ��auto����
	//��FunctionBind_a�ɵ��ö�����һ������������
	//��һ��������placeholders::_1ռλ(�˴����յ���ʱ�������ĵ�һ������)���ڶ�������Ϊ10
	cout << ggg(10) << endl;//�󶨳�һ���º�������º���һ��ʹ�ã�placeholders::_1=10
	cout << ggg(10,20,20,20) << endl;//placeholders::_1=10

	auto hhh = bind(FunctionBind_c, placeholders::_3, placeholders::_1, placeholders::_2);
	//��FunctionBind_c�ɵ��ö�����һ������������
	//��һ��������placeholders::_3ռλ(���յ���ʱ�������ĵ�3������)
	//�ڶ���������placeholders::_1ռλ(���յ���ʱ�������ĵ�1������)
	//������������placeholders::_2ռλ(���յ���ʱ�������ĵ�2������)
	cout << hhh(10, 20, FunctionBind_a) << endl;

}

//void main() {
//	testFunctionBind();
//}