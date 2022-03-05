/*search_n()��������������value��������n�ε���λ��
*
	������ʽ��
		1.iterator search_n(beg, end, n, value);
		����[beg,end)������value��������n�ε����У�
		ָ���һ��ƥ�����еĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
		����2��Ĭ��_Pred()=equal_to<T>

		2.iterator search_n(beg, end, n, value, _Pred);
		����[beg,end)������value������_Pred()��ϵ��ֵ��������n�ε����У�
		ָ���һ��ƥ�����еĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectSearchN {
public:
	bool operator()(int a, int b) {
		//aΪ[beg,end)������Ԫ�أ�bΪvalue������Ԫ��
		//�����Զ�������֮������ĳ�ֹ�ϵ
		return a == b - 1 ? true : false;
	}
};


void testSearchN() {
	vector<int> vect{ 1,2,2,3,3,3,4,4,4,4 };
	
	//1.iterator search_n(beg, end, n, value);
	//����[beg, end)������value��������n�ε����У�
	//ָ���һ��ƥ�����еĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
	vector<int>::iterator p1 = search_n(vect.begin(), vect.end(), 2, 4);
	if (p1 != vect.end()) {
		cout << "�ҵ������У������е�һ��Ԫ����vect1���±�Ϊ��" << p1 - vect.begin() << endl;
	}
	else {
		cout << "û�ҵ������У�" << endl;
	}

	//2.iterator search_n(beg, end, n, value, _Pred);
	//����[beg, end)������value������_Pred()��ϵ��ֵ��������n�ε����У�
	//ָ���һ��ƥ�����еĵ�һ��Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end1()
	vector<int>::iterator p2 = search_n(vect.begin(), vect.end(), 2, 4, mySelectSearchN());
	if (p2 != vect.end()) {
		cout << "�ҵ������У������е�һ��Ԫ����vect1���±�Ϊ��" << p2 - vect.begin() << endl;
	}
	else {
		cout << "û�ҵ������У�" << endl;
	}
}

//void main() {
//	testSearchN();
//}


