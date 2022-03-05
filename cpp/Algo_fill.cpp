/*fill()——向容器中填充指定的元素，覆盖原来的元素
* 函数形式
	1.void fill(beg, end, value);
	向容器中填充指定的元素，覆盖原来的元素

	2.void fill_n(beg, n, value);
	从beg开始写入n个元素
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

void tetsFill() {
	vector<int> vect{1,2,3,4,5,6,7,8,9,0};
	for (int i : vect) { cout << i << " "; }
	cout << endl;
	//1.void fill(beg, end, value) 向容器中填充指定的元素，覆盖原来的元素
	fill(vect.begin(), vect.end(), 10);
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//2.void fill_n(beg, n, value) 从beg开始写入n个元素
	fill_n(vect.begin() + 2, 5, 3);
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	tetsFill();
//}

