/*ν��
	����bool���͵ķº�����Ϊ**ν��**
	���operator()����һ����������ô����һԪν��
	���operator()����������������ô������Ԫν��
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//1.���operator()����һ����������ô����һԪν��
class myCompareFunobj_2a {//���ش���5����
public:
	bool operator()(int val) {
		return val >= 5;
	}
};

//2.���operator()����������������ô������Ԫν��
class myCompareFunobj_2b {//�Ӵ�С����
public:
	bool operator()(int val1,int val2) {
		return val1 > val2;
	}
};

void testFunobj_2() {
	vector<int> vect;
	vect.push_back(1);
	vect.push_back(6);
	vect.push_back(2);
	vect.push_back(4);
	vect.push_back(5);
	vect.push_back(3);
	//find_if(beg,end,op)��������Ѱ�ҵ�һ��opΪ���λ�ã������ظ�λ�õĵ�����
	auto p1 = find_if(vect.begin(), vect.end(), myCompareFunobj_2a());//һԪν��
	cout << *p1 << endl;

	sort(vect.begin(), vect.end(), myCompareFunobj_2b());//��Ԫν��

	for (auto p2 : vect) {
		cout << p2 << " ";
	}
	cout << endl;
}

//void main() {
//	testFunobj_2();
//}




