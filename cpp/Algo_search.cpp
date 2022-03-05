/*search()����������������������ƥ���λ��
*
	������ʽ��
		1.iterator search(beg1, end1, beg2, end2);
		����[beg1,end1)��������[beg2��end2)����ƥ������У�
		ָ���һ��ƥ�����еĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
		����2��Ĭ��_Pred()=equal_to<T>

		2.iterator search(beg1, end1, beg2, end2, _Pred);
		����[beg1,end1)��������[beg2��end2)��������_Pred()��ϵƥ������У�
		ָ���һ��ƥ�����еĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()

search();�����������������е�һ��ƥ���λ�ã�ָ���һ��ƥ�����еĵ�һ��Ԫ��
find_end();  ���������������������һ��ƥ���λ�ã�ָ�����һ��ƥ�����еĵ�һ��Ԫ��
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectSearch {
public:
	bool operator()(int a, int b) {
		//aΪ[beg1,end1)������Ԫ�أ�bΪ[beg2,end2)������Ԫ��
		//�����Զ�������֮������ĳ�ֹ�ϵ
		return a == b - 1 ? true : false;
	}
};


void testSearch() {
	vector<int> vect1{ 3,4,5,3,4,5,6,4,5,6 };
	vector<int> vect2{ 4,5,6 };

	//1.iterator search(beg1, end1, beg2, end2);
	//����[beg1, end1)��������[beg2��end2)����ƥ������У�
	//ָ���һ��ƥ�����еĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
	vector<int>::iterator p1 = search(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
	if (p1 != vect1.end()) {
		cout << "�ҵ������У������е�һ��Ԫ����vect1���±�Ϊ��" << p1 - vect1.begin() << endl;
	}
	else {
		cout << "û�ҵ������У�" << endl;
	}

	//2.iterator search(beg1, end1, beg2, end2, _Pred);
	//����[beg1, end1)��������[beg2��end2)��������_Pred()��ϵƥ������У�
	//ָ���һ��ƥ�����еĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
	vector<int>::iterator p2 = search(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), mySelectSearch());
	if (p2 != vect1.end()) {
		cout << "�ҵ������У������е�һ��Ԫ����vect1���±�Ϊ��" << p2 - vect1.begin() << endl;
	}
	else {
		cout << "û�ҵ������У�" << endl;
	}
}

//void main() {
//	testSearch();
//}


