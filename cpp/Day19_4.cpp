/* ����--������Ʒ
������Ʒ�Ĵ�������Ϊ����ˮ -  ���� - ���뱭�� - ���븨��

*/



#include<iostream>
#include<string>

using namespace std;

//����������Ʒ
class AbstractDrinking_19_4 {
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;
	//�涨����
	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffee_19_4 : public AbstractDrinking_19_4 {
public:
	//��ˮ
	virtual void Boil() {
		cout << "��ũ��ɽȪ!" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݿ���!" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "�����ȵ��뱭��!" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "����ţ��!" << endl;
	}
};

//������ˮ
class Tea_19_4 : public AbstractDrinking_19_4 {
public:
	//��ˮ
	virtual void Boil() {
		cout << "������ˮ!" << endl;
	}
	//����
	virtual void Brew() {
		cout << "���ݲ�Ҷ!" << endl;
	}
	//���뱭��
	virtual void PourInCup() {
		cout << "����ˮ���뱭��!" << endl;
	}
	//���븨��
	virtual void PutSomething() {
		cout << "�������!" << endl;
	}
};

//ҵ����
void DoWork_19_4(AbstractDrinking_19_4* drink) {
	drink->MakeDrink();
	delete drink;
}

void test_19_4() {
	DoWork_19_4(new Coffee_19_4);
	cout << "--------------" << endl;
	DoWork_19_4(new Tea_19_4);
}


//void main() {
//	test_19_4();
//	system("pause");
//
//}