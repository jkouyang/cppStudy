/*min_element()
* ������ʽ
	1.iterator min_element(beg, end);
		������СԪ�صĵ�����
		����2��Ĭ��_Pred=less<T>

	2.iterator min_element(beg, end, _Pred);
		�����Զ���Ƚϵ���СԪ�صĵ�����
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myMinElement {
public:
	bool operator()(int a, int b) {
		return a * a < b* b;
	}
};

void testMinElement() {
	vector<int> vect{ -2,-9,8,1,5,3,7 };

	//1.iterator min_element(beg, end);
	//������СԪ�صĵ�����
	vector<int>::iterator p1 = min_element(vect.begin(), vect.end());
	cout << "��СԪ�أ�" << *p1 << ",�±�Ϊ��" << p1 - vect.begin() << endl;

	//2.iterator min_element(beg, end, _Pred);
	//�����Զ���Ƚϵ���СԪ�صĵ�����
	vector<int>::iterator p2 = min_element(vect.begin(), vect.end(), myMinElement());
	cout << "ƽ����СԪ�أ�" << *p2 << ",�±�Ϊ��" << p2 - vect.begin() << endl;

}

//void main() {
//	testMinElement();
//}
