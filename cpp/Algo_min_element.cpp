/*min_element()
* 函数形式
	1.iterator min_element(beg, end);
		返回最小元素的迭代器
		调用2，默认_Pred=less<T>

	2.iterator min_element(beg, end, _Pred);
		返回自定义比较的最小元素的迭代器
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myMinElement {
public:
	bool operator()(int a, int b) {
		return a * a < b* b;
	}
};

void testMinElement() {
	vector<int> vect{ -2,-9,8,1,5,3,7 };

	//1.iterator min_element(beg, end);
	//返回最小元素的迭代器
	vector<int>::iterator p1 = min_element(vect.begin(), vect.end());
	cout << "最小元素：" << *p1 << ",下标为：" << p1 - vect.begin() << endl;

	//2.iterator min_element(beg, end, _Pred);
	//返回自定义比较的最小元素的迭代器
	vector<int>::iterator p2 = min_element(vect.begin(), vect.end(), myMinElement());
	cout << "平方最小元素：" << *p2 << ",下标为：" << p2 - vect.begin() << endl;

}

//void main() {
//	testMinElement();
//}
