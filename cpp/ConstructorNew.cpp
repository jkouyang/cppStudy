/*ί�й���	�̳й���	����Ĭ�Ϲ���	�ܾ�Ĭ�Ϲ���
	ί�й��죺����ʹ��ͬһ�����е�һ�����캯�����������Ĺ��캯��
	�̳й��죺����̳и���Ĺ��캯����using ����::���캯����(��ʵ�����͹��캯������һ����)


	����() = default; // ��ʽ����ʹ�ñ��������ɵĹ���
	����& operator=(const ����&) = delete; // ��ʽ�����ܾ����������ɹ���

}

*/

#include<iostream>
#include<string>
using namespace std;

//ί�й���
class BaseConstructorNew {
public:
	int A;
	int B;
	string C;
	BaseConstructorNew() {}
	BaseConstructorNew(int a):BaseConstructorNew(){//ί�й���
		this->A = a;
	}
	BaseConstructorNew(int a, int b) :BaseConstructorNew(a) {//ί�й���
		this->B = b;
	}
	BaseConstructorNew(int a, int b, string c) :BaseConstructorNew(a, b) {//ί�й���
		this->C = c;
	}
};

//�̳й���
class SonConstructorNew: BaseConstructorNew {
	using BaseConstructorNew::BaseConstructorNew;//�̳и�������й��췽��
};


void testConstructorNew() {
	SonConstructorNew son(10, 20, "abcd");
}

//void main() {
//	testConstructorNew();
//}


