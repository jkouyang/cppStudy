/*nullptr ��ָ��
* 
    nullptr ���ֵ�Ŀ����Ϊ����� NULL��
    ��ĳ����������˵����ͳ C++ ��� NULL��0 ��Ϊͬһ�ֶ���
    ��ȡ���ڱ�������ζ��� NULL����Щ�������Ὣ NULL ����Ϊ ((void*)0)����Щ���ֱ�ӽ��䶨��Ϊ 0
    C++ ������ֱ�ӽ� void * ��ʽת������������

�ܽ᣺
    C++11 ������ nullptr �ؼ��֣�ר���������ֿ�ָ�롢0
    nullptr�ܹ���ʽ��ת��Ϊ�κ�ָ����Աָ������ͣ�Ҳ�ܺ����ǽ�����Ȼ��߲��ȵıȽ�
    ����ʹ��nullptr������NULL
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
    //decltype()���������Ƶ�����is_same()���ڱȽ����������Ƿ���ͬ
    if (is_same<decltype(NULL), decltype(0)>::value) {
        cout << "NULL == 0" << endl;
    }   
    if (is_same<decltype(NULL), decltype((void*)0)>::value) {
        cout << "NULL == (void *)0" << endl;
    }
    if (is_same<decltype(NULL), nullptr_t>::value) {
        cout << "NULL == nullptr" << endl;
    }

    funcNullptr(0);// ����(int)
    funcNullptr(NULL);//��������ΪNULL=0������(int)
    funcNullptr(nullptr);//����(char*)
}

//void main() {
//	testNullptr();
//}