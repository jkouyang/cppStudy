/*transform()——遍历，并对这一段的数据进行_func()操作，将_func的返回值存储在result开头的范围内
*
	函数形式：
	1.一元操作
		iterator transform(beg, end, result, _func);
		遍历beg-end，并对这一段的数据进行_func()操作，将_func的返回值存储在result开头的范围内
		返回值：目标区间result内最后一个被转换元素的下一位置迭代器,也即未被覆盖的元素的位置迭代器
	
	2.二元操作
		iterator transform(beg1, end1, beg2, result, _func)
		使用[beg1, end1)范围内的每个元素作为第一个参数调用_func,
		并以beg2开头的范围内的每个元素作为第二个参数调用_func,
		每次调用返回的值都存储在以result开头的范围内
		返回值：目标区间result最后一个被转换元素的下一位置迭代器,也即未被覆盖的元素的位置迭代器

注意：
一般很少去使用transform()的返回值，注意不要用错

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int func1Transform(int val) {
	return val + 100;
}

int func2Transform(int val1, int val2) {
	return val1 + val2;
}


void testTransform() {
	vector<int> vect1{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> vect2;
	vect2.resize(vect1.size());
	//1.一元操作  iterator transform(beg, end, result, _func);
	vector<int>::iterator p1 = transform(vect1.begin(), vect1.end(), vect2.begin(), func1Transform);
	for (int i : vect2) {
		cout << i << " ";
	}
	cout << endl;
	cout << *(p1 - 1) << endl;//返回值是目标区间最后一个位置的下一个位置的迭代器
	vector<int> vect3;
	vect3.resize(vect1.size());
	//2.二元操作  iterator transform(beg1, end1, beg2, result, _func)
	vector<int>::iterator p2 = transform(vect1.begin(), vect1.end(), vect2.begin(), vect3.begin(), func2Transform);
	for (int i : vect3) {
		cout << i << " ";
	}
	cout << endl;
	cout << *(p2 - 1) << endl;//返回值是目标区间最后一个位置的下一个位置的迭代器
}

//void main() {
//	testTransform();
//}

