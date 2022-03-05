/*����
����������	vector<��������> ������;
��������	vector<��������>::iterator ��������(ָ��)=������.begin();//��ʼ������
			vector<��������>::iterator ��������(ָ��)=������.end();//��ֹ������
ע�⣺
	1.ÿһ�����������Լ��ĵ����������������������������е�Ԫ��
	2.v.begin()���ص����������������ָ�������е�һ������
	3.v.end()���ص����������������ָ������Ԫ�ص����һ��Ԫ�ص���һ��λ��
	4.vector<int>::iterator �õ�vector<int>���������ĵ���������
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint_22_2(int val) {
	cout << val << " ";
}

void test_22_2() {

	//����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ����ݵ�����
	vector<int> v1;
	for (int i = 0; i < 5; i++) {//�������з�����
		v1.push_back(i+1);
	}
	//����������
	vector<int>::iterator pBegin = v1.begin();
	vector<int>::iterator pEnd = v1.end();

	//��һ�ֱ�����ʽ��
	while (pBegin != pEnd) {
		cout << *pBegin << " ";
		pBegin++;
	}
	cout << endl;

	//�ڶ��ֱ�����ʽ��
	for (vector<int>::iterator pBegin = v1.begin(); pBegin != v1.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;

	//�����ֱ�����ʽ��
	//ʹ��STL�ṩ��׼�����㷨  ͷ�ļ� algorithm
	for_each(v1.begin(), v1.end(), myPrint_22_2);
	//��v1.begin()!=v1.end()ʱ����������v1.begin()��Ӧ��ֵ(*v1.begin())���ݸ�������v1.begin()++

}

//void main() {
//	test_22_2();
//}