/*unique()——剔除相邻相同的元素，伪剔除(没有改变序列的size，还有无用的元素)
*
	函数形式：
		1.iterator unique(beg, end);
		剔除相邻相同的元素
		调用2，默认_Pred=equal<T>()

		2.iterator unique(beg, end, _Pred);
		剔除相邻相同的元素
		自定义_Pred，即自定义两个数据相等的规则
		少用，对只定义数据，重载==或者equal<T>()都可

注意：
	相邻相同的元素，而不是重复出现的元素
	并不是真正的剔除，只是将相邻相异的元素放在前面，后面元素与原序列相同，未进行操作
	没有改变序列的size，还有无用的元素
	并返回第一个无用元素的迭代器，有用的下一位置
	可以利用返回值和resize()实现真值的剔除
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myUnique {
public:
	bool operator()(int a, int b) {
		return a == b + 1;
	}
};


void testUnique() {
	vector<int> vect{ 4,4,1,4,2,2,3,2,4,5 };
	cout << "原始：";
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//1.iterator unique(beg, end);
	//剔除相邻相同的元素
	vector<int>::iterator p1 = unique(vect.begin(), vect.end());
	cout << "剔除：";
	for (int i : vect) { cout << i << " "; }
	cout << endl << "返回迭代器位置,下标：" << p1 - vect.begin() << " 元素：" << *p1 << endl;
	//利用返回值和resize()实现真值的剔除
	cout << "resize()实现真值的剔除:";
	vect.resize(p1 - vect.begin());
	for (int i : vect) { cout << i << " "; }
	cout << endl;


	//2.iterator unique(beg, end, _Pred);
	//自定义_Pred，即自定义两个数据相等的规则
	vector<int>::iterator p2 = unique(vect.begin(), vect.end(), myUnique());
	cout << "剔除：";
	for (int i : vect) { cout << i << " "; }
	cout << endl << "返回迭代器位置,下标：" << p2 - vect.begin() << " 元素：" << *p2 << endl;

}

//void main() {
//	testUnique();
//}
