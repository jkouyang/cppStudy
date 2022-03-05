/*equal()�����ж���������Ԫ���Ƿ����
*
	������ʽ��
		1.bool equal(beg1, end1, beg2);
		�Ƚ�[beg1,end1)��[beg2,...)������2��Ĭ��_Pred=equal_to<T>

		2.bool equal(beg1, end1, beg2, _Pred);
		�Ƚ�[beg1,end1)��[beg2,...)�����Զ���_Pred

		3.bool equal(beg1, end1, beg2, end2);
		�Ƚ�[beg1,end1)��[beg2,end2)������4��Ĭ��_Pred=equal_to<T>

		4.bool equal(beg1, end1, beg2, end2, _Pred);
		�Ƚ�[beg1,end1)��[beg2,end2)�����Զ���_Pred

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myEqual {
public:
	bool operator()(int a, int b) {//�Զ���Ƚ�
		return b == a * a;//���ߵ������Ƿ���ǰ�ߵ�ƽ��
	}
};

void testEqual() {
	vector<int> vect1{ 1,2,3,4 };
	vector<int> vect2{ 1,2,3,4,5 };
	vector<int> vect3{ 1,4,9,16 };

	bool set1 = equal(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
	bool set2 = equal(vect1.begin(), vect1.end(), vect2.begin(), vect2.end()-1);
	//�������ݽϳ�ʱ��ֻҪǰ�����Ⱦͷ����棻������ߵ����ݽ϶̾ͻᱨ��
	bool set3 = equal(vect1.begin(), vect1.end(), vect2.begin());
	//�Զ���ıȽ�
	bool set4 = equal(vect1.begin(), vect1.end(), vect3.begin(), myEqual());

	cout << "set1��" << set1 << endl;
	cout << "set2��" << set2 << endl;
	cout << "set3��" << set3 << endl;
	cout << "set4��" << set4 << endl;
}

//void main() {
//	testEqual();
//}