/*accumulate()——求序列元素之和
* 函数形式
	1.T accumulate(beg, end, value)
	计算容器元素累计总和
	返回sum[beg,end)+value


	???
	2.T accumulate(beg, end, value, _Reduce_op)
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

void testAccumulate() {
	vector<int> vect{ 1,2,3,4,5,6,7,8,9,10 };
	//计算容器元素累计总和，返回sum[beg, end) + value
	int sum = accumulate(vect.begin(), vect.end(), 1000);
	cout << "vect里元素之和为：" << sum << endl;
}

//void main() {
//	testAccumulate();
//}