/*lambda���ʽ
	����ʽ�ı�̷�񣺾͵���������Ŀ�꺯���������󣬲���Ҫ����дһ������������������
	lambda���ʽ��������C++11�лᱻ������һ����operator()���࣬���º���

�﷨��[capture](params) opt -> ret {body;};
	  ����capture�ǲ����б�params�ǲ����б�opt�Ǻ���ѡ�ret�Ƿ���ֵ���ͣ�body�Ǻ�����
	
	1.�����б� []: ����һ����Χ�ڵı���
	2.�����б� (): ����ͨ�����Ĳ����б�һ�������û�в��������б����ʡ�Բ�д��
	3.opt ѡ� ����Ҫ����ʡ��
		mutable: �����޸İ�ֵ���ݽ����Ŀ�����ע�������޸Ŀ�����������ֵ����
		exception: ָ�������׳����쳣�����׳��������͵��쳣������ʹ�� throw ();
	4.����ֵ���ͣ��� C++11 �У�lambda ���ʽ�ķ���ֵ��ͨ������ֵ�����﷨������ġ�
	5.�����壺������ʵ�֣��ⲿ�ֲ���ʡ�ԣ������������Ϊ�ա�

	1.�����б� []
		[]  - ����׽�κα���
		[&] - �����ⲿ�����������б���������Ϊ�����ں�������ʹ�� (�����ò���)
		[=] - �����ⲿ�����������б���������Ϊ�����ں�������ʹ�� (��ֵ����)
			  �����ĸ����������������ڲ���ֻ����
		[=, &val] - ��ֵ�����ⲿ�����������б��������������ò����ⲿ����val
		[val] - ��ֵ���� val ������ͬʱ��������������
		[&val] - �����ò��� val ������ͬʱ��������������
		[this] - ����ǰ���е� this ָ��
			�� lambda ���ʽӵ�к͵�ǰ���Ա����ͬ���ķ���Ȩ��
			����Ѿ�ʹ���� & ���� =, Ĭ����Ӵ�ѡ��

	2.���������ľ͵ض���
		function<void(int,int)> foo = [=, &a](int c,int d)mutable->void {}

�ܽ᣺
	1.��ָ�� lambda ���ʽ�ķ���ֵ������������� return ����Զ��Ƶ�����ֵ������
		����Ҫע����� labmda���ʽ����ͨ���б��ʼ���Զ��Ƶ�������ֵ����
	2.lambda���ʽ��������C++11�лᱻ������һ����operator()���࣬���º���
		��˿���ʹ��std::function��std::bind���洢�Ͳ���lambda���ʽ
	3.lambda���ʽ��operator()Ĭ����const�ģ�һ��const��Ա�������޷��޸ĳ�Ա����ֵ��
		mutable ѡ������þ�����ȡ��operator()��const����
	4.δ�����κα����� lambda ���ʽ������ת����һ����ͨ�ĺ���ָ��

*/

#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

vector<int> sortLambda(vector<int>& score) {
	vector<int> order;
	for (int i = 0; i < score.size(); i++) {
		order.push_back(i);
	}
	sort(order.begin(), order.end(), [&score](const int& a, const int& b) {return score[a] > score[b]; });
	//order������˳��0,1,2...���൱���±꣬score���±갴score��ֵ�Ӵ�С�����������±��¼��order��
	//��һ���
	return order;
}

void testLambda() {
	int a = 10;
	int b = 10;
	string str = "hello";
	//�͵���������Ŀ�꺯��
	//function<void(int,int)> ,����ֵΪvoid������Ϊ(int,int)��������
	function<void(int,int)> foo = [=, &a](int c,int d)mutable->void {
	//����auto�Զ������Ƶ�
		a = a + c ;
		// = �ǿ�������(�β�)���������mutable�����βν���ֻ����
		b = b + d;//����mutable��b�Ŀ��������Ͳ����޸�
		str = "world";//����mutable��str�Ŀ��������Ͳ����޸�
		cout << a << "\t" << str << "\t" << b << endl;
		// & ��������޸��ⲿ��ֵ��= �����mutableֻ���ڲ��޸�(�޸Ŀ���������ֵ)
	};
	foo(7,3);
	cout << a << "\t" << str << "\t" << b << endl;

	//�͵��������庯������
	auto func = [](int a, int b)->bool {
		return a > b;
	};
	vector<int> vect{ 2,5,1,6,4,3,8,7,9 };
	sort(vect.begin(), vect.end(), func);//lambda���ʽ�����Ƿº���
	for (auto& i : vect) { cout << i << " "; }
	cout << endl;
	//�߼�lambda���ʽ sort()����
	//vect���±갴vect��ֵ�Ӵ�С�����������±��¼��order�У���һ���
	vector<int> order = sortLambda(vect);

	//δ�����κα����� lambda ���ʽ������ת����һ����ͨ�ĺ���ָ��
	using funcPtr = bool(*)(int, int);
	funcPtr p = func;
	cout << p(2, 1) << endl;
}

//void main() {
//	testLambda();
//}