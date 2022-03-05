/*关系仿函数——实现关系对比
**仿函数原型：**
	1.template<class T> bool equal_to<T>//等于
	2.template<class T> bool not_equal_to<T>//不等于
	3.template<class T> bool greater<T>//大于
	4.template<class T> bool greater_equal<T>//大于等于
	5.template<class T> bool less<T>//小于
	6.template<class T> bool less_equal<T>//小于等于

总结：都是二元运算，关系仿函数中最常用的就是greater<>大于
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class MyCompareFunobj_4{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void testFunobj_4() {
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (auto p:v) {
		cout << p << " ";
	}
	cout << endl;

	//自己实现仿函数
	//sort(v.begin(), v.end(), MyCompareFunobj_4());
	//STL内建仿函数  大于仿函数
	sort(v.begin(), v.end(), greater<int>());

	for (auto p : v) {
		cout << p << " ";
	}
	cout << endl;
}


//void main() {
//	testFunobj_4();
//}









