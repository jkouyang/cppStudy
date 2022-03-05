/*set_difference()——两有序序列的差集
* 函数形式
	iterator set_difference(beg1, end1, beg2, end2, result);
	两个集合必须是有序序列
	求两个集合的差集合，A-B
	返回值：目标区间result内最后一个元素的下一位置迭代器
	注意先开辟空间
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
	vect3.resize(max(vect1.size(), vect2.size()));//开辟空间
	vector<int>::iterator p = set_difference(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect3.begin());
	for (int i : vect3) { cout << i << " "; }
	cout << endl;
	cout << *(p - 1) << endl;
}


//void main() {
//	testSetDifference();
//}
