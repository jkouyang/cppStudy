/*partial_sort()������������
* ������ʽ
	1.void partial_sort(beg, mid, end);
	����С������������[beg,mid)�У�[mid,end)�������

	2.void stable_sort(beg, mid, end, _Pred);
	��_Pred��������ǰ��������������[beg,mid)�У�[mid,end)�������

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testPartialSort() {
	vector<int> vect{ 2,1,5,3,7,6,4,9,8,0 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//1.void partial_sort(beg, mid, end);
	//����С������������[beg, mid)�У�[min, end)�������
	partial_sort(vect.begin(), vect.begin()+4, vect.end());
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//2.void stable_sort(beg, end, _Pred);
	//��_Pred��������ǰ��������������[beg, mid)�У�[min, end)�������
	partial_sort(vect.begin(), vect.begin() + 4, vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testPartialSort();
//}
