/*��ֵ����(R-value reference)
* 
* ��ֵ��ֵ�����֣�
	lvalue �� loactor value ����д��rvalue �� read value ����д
	��ֵ��ָ�洢���ڴ��С�����ȷ�洢��ַ����ȡ��ַ�������ݣ�
	��ֵ��ָ�����ṩ����ֵ�����ݣ�����ȡ��ַ����
	���ԶԱ��ʽȡ��ַ��&��������ֵ������Ϊ��ֵ

	��ֵ��Ϊ���֣�����ֵ������ֵ
	����ֵ�������÷��ص���ʱ������������ʽ��������ʱ������ԭʼ�������� lambda ���ʽ��
	����ֵ������ֵ������صı��ʽ�����磬T&& ���ͺ����ķ���ֵ�� std::move �ķ���ֵ�ȡ�

* ��ֵ���á�����һ����ֵ�������õ�����
�﷨����������&& ���� = ��ֵ��
	��Ϊ��ֵ�������ģ�ֻ��ͨ�����õķ�ʽ�ҵ���
	��ֵ���ú���ֵ���ö�Ҫ���г�ʼ������Ϊ���ñ�����ӵ�ж�����ڴ棬ֻ�Ǹö����һ������
	��ֵ���õ������������ʱֵ���������ڵ����ӳ���ֻҪ���õı��������ţ���ô����ֵ��������

* ��ֵ���õ�Ӧ��
	���ж���ֵ������ʱ�򣬺ܶ�����»ᷢ������֮��������������ڴ�ܴ���������Ĵ���Ҳ�ͷǳ���
	��ĳЩ����£������Ҫ��������������Ϳ���ʹ����ֵ���ý������ܵ��Ż�

* move()��������������ֵת��Ϊ��ֵ

* ע��
	��ֵ���ÿ���������ֵ
	��ֵ���ÿ���������ֵ
	������ֵ���ÿ���������ֵ+��ֵ
	������ֵ���ÿ���������ֵ

	**��ֵ������һ����ֵ(int&& a = 10, ����aΪ��ֵ)
*/

#include<iostream>
#include<string>
#include<vector>
#include <functional>
using namespace std;

class moveRvalue {
public:
	vector<int>* pArray;
	moveRvalue() :pArray(new vector<int>(100)) {
		cout << "Ĭ�Ϲ���" << endl;
	}
	moveRvalue(moveRvalue& t) {//��������
		this->pArray = new vector<int>((*t.pArray).size());
		for (int i = 0; i < (*t.pArray).size(); i++) {
			(*this->pArray)[i] = (*t.pArray)[i];
		}
		cout << "��������" << endl;
	}

	//���ڴ�ܴ������ƶ�����������
	//��������t��һ����ֵ(����ֵ+����ֵ)�Ļ��Ż�����ƶ�����
	//��������t��һ����ֵ��Ȼ���ÿ�������
	//���û�ж����ƶ����죬������ֵҲ����ÿ�������
	moveRvalue(moveRvalue&& t) :pArray(t.pArray) {//�ƶ�����
		t.pArray = nullptr;
		cout << "�ƶ�����" << endl;
	}

	~moveRvalue() {
		if (this->pArray != nullptr) {
			delete this->pArray;
			this->pArray = nullptr;
			cout << "��������ִ���ͷſռ�" << endl;
		}
		cout << "���������ö�������" << endl;
	}
};

moveRvalue getmoveRvalue() {
	moveRvalue tt;
	return tt;
}

void testRvalue1() {
	moveRvalue mm;//Ĭ�Ϲ���
	moveRvalue nn(mm);//�����mm����ֵ�����ÿ�������
	moveRvalue hh(getmoveRvalue());//�����getmoveRvalue()����ֵ�������ƶ�����


	//ע��
	int a = 10;
	int& b = a;//��ֵ���ÿ���������ֵ
	const int& c= a;//��ֵ���ÿ���������ֵ
	const int& d = 10;//������ֵ���ÿ���������ֵ + ��ֵ
	int&& e = 10;//������ֵ���ÿ���������ֵ + ��ֵ
	//const int&& f = a;//���󣬳�����ֵ���ò�����������ֵ
	const int&& f = move(a);//move()��������������ֵת��Ϊ��ֵ
	const int&& g = 10;//������ֵ���ÿ���������ֵ

}

void testRvalue2() {//�ƶ����
	string str = "hello world";
	vector<string> vect;

	// ��ʹ�� push_back(const T&), ������������Ϊ
	//str��ֵ����
	vect.push_back(str);
	cout << "str: " << str << endl;
	cout<< "vect[1]: " << *vect.begin() << endl;

	// ��ʹ�� push_back(const T&&), ������ֿ�����Ϊ
	// �������ַ����ᱻ�ƶ��� vector �У�������ʱ�� move() ���������ٿ������ֵĿ���
	// �ⲽ������, str �е�ֵ���Ϊ��
	vect.push_back(move(str));
	cout << "str: " << str << endl;
	cout << "vect[1]: " << *vect.begin() << endl;
	cout << "vect[2]: " << *(vect.begin()+1) << endl;
}

//void main() {
//	testRvalue1();
//	testRvalue2();
//}