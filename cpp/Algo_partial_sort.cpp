/*partial_sort()——部分排序
* 函数形式
	1.void partial_sort(beg, mid, end);
	将最小的序列排序在[beg,mid)中，[mid,end)是乱序的

	2.void stable_sort(beg, mid, end, _Pred);
	按_Pred规则排序前面的序列排序放在[beg,mid)中，[mid,end)是乱序的

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
	//将最小的序列排序在[beg, mid)中，[min, end)是乱序的
	partial_sort(vect.begin(), vect.begin()+4, vect.end());
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//2.void stable_sort(beg, end, _Pred);
	//按_Pred规则排序前面的序列排序放在[beg, mid)中，[min, end)是乱序的
	partial_sort(vect.begin(), vect.begin() + 4, vect.end(), greater<int>());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testPartialSort();
//}
