/*�������������()����
	�������������()  Ҳ��������
	�������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
	�º���û�й̶�д�����ǳ����

****�൱�����ã�α����
*/

#include<iostream>
#include<string>
using namespace std;

class class_17_4a {
public:
	void operator()() {
		cout << "�������������()����" << endl;
	}
	void showprint() {
		cout << "�������������ͨ����" << endl;
	}
};

class class_17_4b {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

void test_17_4() {
	class_17_4a cla;//�ȴ�������Ȼ����󵱺�����
	cla();//α�����ĵ���
	class_17_4b clb;
	cout << "a+b����֮�ͣ�" << clb(10,15) << endl;

	//�������󣬲�ʵ��������ֱ�ӵ���������ĺ���
	class_17_4a().showprint();//�������������ͨ����
	cout << "�����������α������a+b����֮�ͣ�" << class_17_4b()(10, 15) << endl;//�����������α����

}

//void main() {
//	test_17_4();
//}