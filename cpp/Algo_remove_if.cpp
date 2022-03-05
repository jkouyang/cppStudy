/*remove_if()——剔除区间内满足条件的元素，伪剔除(没有改变序列的size，还有无用的元素)
*
	函数形式：
		iteator remove(beg, end, value, _Pred);
		剔除区间内满足条件的元素

注意：
	并不是真正的剔除，只是将正确的元素放在前面，后面元素与原序列相同，未进行操作
	没有改变序列的size，还有无用的元素
	并返回第一个无用元素的迭代器，有用的下一位置
	可以利用返回值和resize()实现真值的剔除
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myRemoveIf {
public:
	bool operator()(int val) {
		return val >= 3;//移除大于3的元素
	}
};

void testRemoveIf() {
	vector<int> vect{ 4,4,1,4,2,2,3,2,4 };
	cout << "原始：";
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//iteator remove_if(beg, end, _Pred);伪剔除区间内满足条件的元素
	vector<int>::iterator p = remove_if(vect.begin(), vect.end(), myRemoveIf());
	cout << "剔除：";
	for (int i : vect) { cout << i << " "; }
	cout << endl << "返回迭代器位置,下标：" << p - vect.begin() << " 元素：" << *p << endl;
	//利用返回值和resize()实现真值的剔除
	cout << "resize()实现真值的剔除:";
	vect.resize(p - vect.begin());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testRemoveIf();
//}
