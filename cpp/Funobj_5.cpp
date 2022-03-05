/*逻辑仿函数——实现逻辑运算

**函数原型：**
	1.template<class T> bool logical_and<T>//逻辑与
	2.template<class T> bool logical_or<T>//逻辑或
	3.template<class T> bool logical_not<T>//逻辑非

总结：逻辑仿函数实际应用较少，了解即可
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void testFunobj_5() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (auto it : v) {
		cout << it << " ";
	}
	cout << endl;

	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());
	//transform()搬运的时候可以进行运算逻辑
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (auto it : v2) {
		cout << it << " ";
	}
	cout << endl;
}

//void main() {
//	testFunobj_5();
//}


