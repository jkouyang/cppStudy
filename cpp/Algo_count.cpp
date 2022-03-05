/*count()
* 函数形式
	int count(beg, end, value);
	统计[beg,end)区间值等于value的元素个数
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testCount() {
	vector<int> vect{ 2,6,3,5,7,2,4,5,2,1 };
	cout << "元素值为2的个数为：" << count(vect.begin(), vect.end(), 2) << endl;
}

//void main() {
//	testCount();
//}