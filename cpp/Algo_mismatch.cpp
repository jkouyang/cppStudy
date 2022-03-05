/*mismatch()——寻找两个序列中第一个不匹配的元素，返回一对迭代器
* 函数形式
	1.<iterator, iterator> mismatch(beg1, end1, beg2);
		返回一对迭代器，指向两个序列不匹配的地方
		调用2，默认_Pred=equal_to<T>

	2.<iterator, iterator> mismatch(beg1, end1, beg2, _Pred);
		自定义比较规则

	3.<iterator, iterator> mismatch(beg1, end1, beg2, end2);
		调用4，默认_Pred=equal_to<T>

	4.<iterator, iterator> mismatch(beg1, end1, beg2, end2, _Pred);
		自定义比较规则
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
	cout << "两序列第一个不同的位置:" << pair.first - vect1.begin() << " " << pair.second - vect2.begin() << endl;
}

//void main() {
//	testMismatch();
//}