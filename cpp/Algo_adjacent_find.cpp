/*adjacent_find()�������ҵ�һ�������ظ�(���)��Ԫ��
*
	������ʽ��
	1.iterator adjacent_find(beg, end);//���������ظ�(���)��Ԫ��	
	�����Ҳ��������ظ���Ԫ�أ��������ظ��ĵ�һ��Ԫ�صĵ��������Ҳ������ؽ���������end()

	2.iterator adjacent_find(beg, end, _Pred);//������������ĳ�ֹ�ϵ��Ԫ��
	�����Ҳ�����������ĳ�ֹ�ϵ��Ԫ�أ�������һ��Ԫ�صĵ��������Ҳ������ؽ���������end()

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectAdjacentIf {
public:
	bool operator()(const int& a, const int& b) const {
		if (b - a <= 5 && b-a>=-5) {//����Ԫ�صĲ�С�ڵ���5
			return true;
		}
		else {
			return false;
		}
	}
};

void tetsAdjacentIf() {
	//1.���������ظ�(���)��Ԫ��	iterator adjacent_find(beg, end);
	vector<int> vect1{ 1,2,3,4,5,5,6,6,7,7,8,8 };
	vector<int>::iterator p1 = adjacent_find(vect1.begin(), vect1.end());
	if (p1 != vect1.end()) {
		cout << "�ҵ��ظ�Ԫ�أ���һ���ظ�Ԫ���±�Ϊ��" << p1 - vect1.begin() << endl;
	}
	else {
		cout << "û�ҵ���" << endl;
	}
	//2.������������ĳ�ֹ�ϵ��Ԫ��	iterator adjacent_find(beg, end, _Pred);
	vector<int> vect2{ 1,100,108,112,150,200};
	vector<int>::iterator p2 = adjacent_find(vect2.begin(), vect2.end(), mySelectAdjacentIf());
	if (p2 != vect2.end()) {
		cout << "�ҵ�����Ԫ�صĲ�С�ڵ���5����һ��Ԫ���±�Ϊ��" << p2 - vect2.begin() << endl;
	}
	else {
		cout << "û�ҵ���" << endl;
	}
}

//void main() {
//	tetsAdjacentIf();
//}