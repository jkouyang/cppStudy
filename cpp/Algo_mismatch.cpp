/*mismatch()����Ѱ�����������е�һ����ƥ���Ԫ�أ�����һ�Ե�����
* ������ʽ
	1.<iterator, iterator> mismatch(beg1, end1, beg2);
		����һ�Ե�������ָ���������в�ƥ��ĵط�
		����2��Ĭ��_Pred=equal_to<T>

	2.<iterator, iterator> mismatch(beg1, end1, beg2, _Pred);
		�Զ���ȽϹ���

	3.<iterator, iterator> mismatch(beg1, end1, beg2, end2);
		����4��Ĭ��_Pred=equal_to<T>

	4.<iterator, iterator> mismatch(beg1, end1, beg2, end2, _Pred);
		�Զ���ȽϹ���
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testMismatch() {
	vector<int> vect1{ 1,5,9,2,7,0,5,8,8,0,9 };
	vector<int> vect2{ 0,1,5,9,2,7,0,2,8,8,0,9 };
	pair<vector<int>::iterator, vector<int>::iterator> pair = mismatch(vect1.begin(), vect1.end(), vect2.begin()+1, vect2.end());
	cout << "�����е�һ����ͬ��λ��:" << pair.first - vect1.begin() << " " << pair.second - vect2.begin() << endl;
}

//void main() {
//	testMismatch();
//}