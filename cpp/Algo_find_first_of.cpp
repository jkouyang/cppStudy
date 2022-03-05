/*find_first_of()
*
	������ʽ��
		1.iterator find(beg1, end1, beg2, end2);
		����[beg1,end1)��������[beg2��end2)����������Ԫ��ƥ���Ԫ�أ�
		ָ��ƥ��ĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()

		2.iterator find(beg1, end1, beg2, end2, _Pred);
		����[beg1,end1)��������[beg2��end2)����������Ԫ������_Pred()��ϵ��Ԫ�أ�
		ָ��ƥ��ĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
		����find_if()
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectFindFirstOf {
public:
	bool operator()(int a, int b) {
		//aΪ[beg1,end1)������Ԫ�أ�bΪ[beg2,end2)������Ԫ��
		//�����Զ�������֮������ĳ�ֹ�ϵ������find_if
		return a == b + 1 ? true : false;
	}
};


void testFindFirstOf() {
	vector<int> vect1{ 1,2,3,4,5,6,6,6,6,10 };
	vector<int> vect2{ -7,-6,-5,5,10 };

	//1.������ʽ��iterator find(beg1, end1, beg2, end2);
	//����[beg1, end1)��������[beg2��end2)����������Ԫ��ƥ���Ԫ�أ�
	//ָ��ƥ��ĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
	vector<int>::iterator p1 = find_first_of(vect1.begin(), vect1.end(), vect2.begin(),vect2.end());
	if (p1 != vect1.end()) {
		cout << "�ҵ���Ԫ��:" << *p1 << "����vect1���±�Ϊ��" << p1 - vect1.begin() << endl;
	}
	else {
		cout << "û�ҵ���" << endl;
	}

	//2.iterator find(beg1, end1, beg2, end2, _Pred);
	//����[beg1,end1)��������[beg2��end2)����������Ԫ������_Pred()��ϵ��Ԫ�أ�
	//ָ��ƥ��ĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
	vector<int>::iterator p2 = find_first_of(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), mySelectFindFirstOf());
	if (p2 != vect1.end()) {
		cout << "�ҵ���Ԫ��:" << *p2 << "����vect1���±�Ϊ��" << p2 - vect1.begin() << endl;
	}
	else {
		cout << "û�ҵ���" << endl;
	}
	
}

//void main() {
//	testFindFirstOf();
//}


