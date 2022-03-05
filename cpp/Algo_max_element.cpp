/*max_element()
* ������ʽ
	1.iterator max_element(beg, end);
		�������Ԫ�صĵ�����
		����2��Ĭ��_Pred=less<T>

	2.iterator max_element(beg, end, _Pred);
		�����Զ���Ƚϵ����Ԫ�صĵ�����
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myMaxElement {
public:
	bool operator()(int a, int b) {
		return a * a < b* b;
	}
};

void testMaxElement() {
	vector<int> vect{ -2,-9,8,1,5,3,7 };

	//1.iterator max_element(beg, end);
	//�������Ԫ�صĵ�����
	vector<int>::iterator p1 = max_element(vect.begin(), vect.end());
	cout << "���Ԫ�أ�" << *p1 << ",�±�Ϊ��" << p1 - vect.begin() << endl;

	//2.iterator max_element(beg, end, _Pred);
	//�����Զ���Ƚϵ����Ԫ�صĵ�����
	vector<int>::iterator p2 = max_element(vect.begin(), vect.end(),myMaxElement());
	cout << "ƽ�����Ԫ�أ�" << *p2 << ",�±�Ϊ��" << p2 - vect.begin() << endl;

}

//void main() {
//	testMaxElement();
//}
