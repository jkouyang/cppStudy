/*Day10
��Ͷ���-����
	C++����������������Ϊ��==��װ���̳С���̬==
	(1)�﷨��class ����{ ����Ȩ�ޣ� ���� / ��Ϊ  };
	(2)����Ȩ��
			����Ȩ�� public		��Ա ���ڿ��Է��ʣ�������Է���
			����Ȩ�� protected	��Ա ���ڿ��Է��ʣ����ⲻ�ɷ���		������Է��ʸ����еı�������
			˽��Ȩ�� private	��Ա ���ڿ��Է��ʣ����ⲻ�ɷ���		���಻�Է��ʸ����е�˽������
	(3)stuct��class�ıȽ�
			��C++�� struct��classΨһ�����������Ĭ�ϵķ���Ȩ�޲�ͬ
			* struct Ĭ��Ȩ��Ϊ����
			* class  Ĭ��Ȩ��Ϊ˽��
	(4)��װ����Ա��������Ϊ˽��
		�ŵ㣺�����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
			  ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
ע�⣺ͬһ����Ŀ�½ṹ��֮�䣬��֮�䣬�ṹ�����֮���������Ҫ��ͬ
*/

#include<iostream>
#include<string>
using namespace std;

class stu_10 {
public:
	//����  ��Ա����  ��Ա����
	string sName;
	int sId;

	//��Ϊ  ��Ա����  ��Ա����
	void set_sName(string name) {
		sName = name;
	}
	void set_sId(int id) {
		sId = id;
	}

	void showprint() {
		cout << "name:" << sName << "\tid:" << sId << endl;
	}
};

class tea_10 {
	//����
public:
	string tName;
protected:
	int tId;
private:
	int tWage;

	//����
public:
	void set_tea(string name, int id, int wage) {
		this->tName = name;
		this->tId = id;
		this->tWage = wage;
	}

	void showprint() {
		cout << "name:" << tName << "\tid:" << tId << "\t\twage:" << tWage << endl;
	}
};

struct test_101 {
	int struct_test = 10;//struct Ĭ��Ȩ��Ϊ����
};

class test_102 {
	int class_test = 10;//class  Ĭ��Ȩ��Ϊ˽��
};

//void main() {
//	stu_10 tony;
//	//public�����������ֵ
//	//tony.sName = "tony";
//	//tony.sId = 123;
//
//	tony.set_sName("tony");
//	tony.set_sId(123);
//	tony.showprint();
//
//	tea_10 mary;
//	mary.set_tea("mary",101,1000);
//	mary.showprint();
//	
//
//	test_101 a;
//	a.struct_test = 0;//�ɷ���
//	test_102 b;
//	//b.struct_test = 0;//���ɷ���
//}