/*
������Ƕ�����������ǽ��������ݽ��б������
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void test_22_4() {
	vector<vector<int>> v(5);//���ֻ��ȴ���5���յ����ݷŽ�ȥ��һ�㲻����д��
	cout << "sizeof(v):" << sizeof(v) << endl;//������ռ�Ŀռ䶼��32B
	cout << "v.size():" << v.size() << endl;
	cout << "sizeof(vector<vector<int>>):" << sizeof(vector<vector<int>>) << endl;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;
	cout << "v1.size():" << v1.size() << endl;


	cout << "sizeof(v1):" << sizeof(v1) << endl;
	cout << "sizeof(vector<int>):" << sizeof(vector<int>) << endl;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
		v5.push_back(i + 5);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	for (vector<vector<int>>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		for (vector<int>::iterator qBegin = pBegin->begin(); qBegin != pBegin->end(); qBegin++) {
			cout << *qBegin << " ";
		}
		cout <<"����һ������" << endl;
	}
}


//void main() {
//	test_22_4();
//}