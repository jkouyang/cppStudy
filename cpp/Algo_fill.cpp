/*fill()���������������ָ����Ԫ�أ�����ԭ����Ԫ��
* ������ʽ
	1.void fill(beg, end, value);
	�����������ָ����Ԫ�أ�����ԭ����Ԫ��

	2.void fill_n(beg, n, value);
	��beg��ʼд��n��Ԫ��
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

void tetsFill() {
	vector<int> vect{1,2,3,4,5,6,7,8,9,0};
	for (int i : vect) { cout << i << " "; }
	cout << endl;
	//1.void fill(beg, end, value) �����������ָ����Ԫ�أ�����ԭ����Ԫ��
	fill(vect.begin(), vect.end(), 10);
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//2.void fill_n(beg, n, value) ��beg��ʼд��n��Ԫ��
	fill_n(vect.begin() + 2, 5, 3);
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	tetsFill();
//}

