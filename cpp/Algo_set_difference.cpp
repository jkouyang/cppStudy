/*set_difference()�������������еĲ
* ������ʽ
	iterator set_difference(beg1, end1, beg2, end2, result);
	�������ϱ�������������
	���������ϵĲ�ϣ�A-B
	����ֵ��Ŀ������result�����һ��Ԫ�ص���һλ�õ�����
	ע���ȿ��ٿռ�
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include<math.h>
using namespace std;

void testSetDifference() {
	vector<int> vect1{ 1,2,3,4,5,6,7,8 };
	vector<int> vect2{ 4,5,6,7,8,9,10,11 };
	vector<int> vect3;
	vect3.resize(max(vect1.size(), vect2.size()));//���ٿռ�
	vector<int>::iterator p = set_difference(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect3.begin());
	for (int i : vect3) { cout << i << " "; }
	cout << endl;
	cout << *(p - 1) << endl;
}


//void main() {
//	testSetDifference();
//}
