/*copy()——容器内指定范围的元素拷贝到另一容器中
* 函数形式
	iterator copy(beg, end, result)
	容器内指定范围的元素拷贝到另一容器中
	返回值：目标区间result内最后一个元素的下一位置迭代器
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testCopy() {
	vector<int> vect1{ 2,1,3,5,4 };
	for (int i : vect1) { cout << i << " "; }
	cout << endl;

	vector<int> vect2;
	//要开辟空间(resize)，而不是预留空间(reserve)
	//vect2.reserve(vect1.size());//报错
	vect2.resize(vect1.size());
	vector<int>::iterator p = copy(vect1.begin(), vect1.end(), vect2.begin());
	for (int i : vect2) { cout << i << " "; }
	cout << endl;
	//返回值：目标区间result内最后一个元素的下一位置迭代器
	cout << *(p - 1) << endl;
}

//void main() {
//	testCopy();
//}