/*stable_sort()��������
* ������ʽ
	1.void stable_sort(beg, end);Ĭ�����򣬴�С����

	2.void stable_sort(beg, end, _Pred);��_Predָ������

ע�⣺
	sort()����֤��ͬԪ��֮���λ�ù�ϵ���������ȶ���
	stable_sort()��֤��ͬԪ��֮���λ�ù�ϵ�������ȶ���
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testStableSort() {
	//stable_sort()��֤��ͬԪ��֮���λ�ù�ϵ�������ȶ���
	//�����sort()��ͬ
	vector<int> vect{ 2,1,1,1,5,3,7,6,4,9,8,0 };
	stable_sort(vect.begin(), vect.end());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testStableSort();
//}
