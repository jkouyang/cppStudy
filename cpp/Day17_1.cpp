/*Day17  ���������
* ��������ظ�������е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
	��+�������������
			���ã�ʵ�������Զ�������������ӵ�����
			ʵ�֣�1.��Ա����ʵ�֡�+�������������
				  2.ȫ�ֺ���ʵ�֡�+�������������
			�ܽ᣺1.�������õ��������͵ı���ʽ�ĵ�������ǲ����ܸı��
				  2.��Ҫ�������������

	��<<���������������
			ʵ�֣�ȫ�ֺ���
	��++��������������أ�����ǰ�õ�����������غͺ��õ������������
			ʵ�֣���Ա����
*/

#include<iostream>
#include<string>
using namespace std;

class Person_17_1 {
public:
	int A;
	int B;

	void show_17_a() {
		cout << "A:" << A << "\tB:" << B << endl;
	}
	//Person_17_1 operator+(Person_17_1 &p) {//1.��Ա����ʵ�֡� + �������������
	//	Person_17_1 temp;
	//	temp.A = this->A + p.A;
	//	temp.B = this->B + p.B;
	//	return temp;
	//}

	//���ǲ��ó�Ա����ʵ��<<���������
	//��Ա���� ʵ�ֲ���  p << cout ����������Ҫ��Ч��
	//void operator<<(Person_17_1& p){
	//}

	Person_17_1& operator++() {//ǰ�õ���
		this->A++;//��+
		this->B++;
		return *this;//�ٷ���
		//ǰ�õ���������ʽ���������Է�������(����)
	}

	Person_17_1 operator++(int) {//��ռλ��ʵ�ֺ������أ�����ǰ�úͺ���
		Person_17_1 temp = *this;//�ȼ�¼
		A++;//��+
		B++;
		return temp;//�ٷ���
		//���õ���������ʽ���������Է�����(�β�)
	}

	//ͨ�������������������������ͷ����
	//~Person_17_1() {
	//	cout << "�ͷ���ı�����" << endl;
	//}

};

Person_17_1 operator+(Person_17_1 p1, Person_17_1 &p2) {//2.ȫ�ֺ���ʵ�֡�+�������������
	Person_17_1 temp;
	temp.A = p1.A + p2.A;
	temp.B = p1.B + p2.B;
	return temp;
}

//ȫ�ֺ���ʵ�֡�<<���������������
ostream& operator<<(ostream &out, Person_17_1 p) {//cout�Ǳ�׼�������������ֻ��һ��������ֻ�������ã����������������������������㣬����out
	out << "A:" << p.A << "\tB:" << p.B;//Ϊʲô����ط������ô���Person_17_1 &p����91��(cout << "p2++:\t\t" << p2++ << endl;//���õ���)����
	return out;
}

void test_17_1() {
	//��+�������������
	Person_17_1 p1;
	p1.A = 10;
	p1.B = 10;
	Person_17_1 p2;
	p2.A = 15;
	p2.B = 15;
	Person_17_1 p3 = p1 + p2;

	cout << "p1.A=10\tp1.B = 10" << endl;
	cout << "p2.A=15\tp1.B = 15" << endl;
	cout << "p3=p1+p2\t";
	p3.show_17_a();

	//�� << ���������������
	cout << "p3:\t\t"<< p3 << "\t��ʽ˼��" << endl;

	//��++���������������
	cout << "++++++p1:\t"<< ++++++p1 << endl;//ǰ�õ���
	cout << "p1:\t\t" << p1 << endl;//ǰ�õ���
	cout << "p2++:\t\t" << p2++ << endl;//���õ���
	cout << "p2:\t\t" << p2 << endl;//���õ���
}

//void main() {
//	test_17_1();
//	system("pause");
//}