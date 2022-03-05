/*stable_sort()——排序
* 函数形式
	1.void stable_sort(beg, end);默认排序，从小到大

	2.void stable_sort(beg, end, _Pred);按_Pred指定排序

注意：
	sort()不保证相同元素之间的位置关系，不具有稳定性
	stable_sort()保证相同元素之间的位置关系，具有稳定性
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testStableSort() {
	//stable_sort()保证相同元素之间的位置关系，具有稳定性
	//其余和sort()相同
	vector<int> vect{ 2,1,1,1,5,3,7,6,4,9,8,0 };
	stable_sort(vect.begin(), vect.end());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testStableSort();
//}
