/*find()——查找第一个指定元素
*
	函数形式：
		iterator find(beg, end, value);
	
	从左到右查找指定元素，找到第一个符合的元素，并返回该元素的迭代器，找不到返回结束迭代器end()

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void testFind() {
	vector<int> vect{ 1,2,3,4,5,6,6,6,6,10 };
	vector<int>::iterator p = find(vect.begin(), vect.end(), 6);
	if (p != vect.end()) {
		cout << "找到该元素，下标为：" << p - vect.begin() << endl;
	}
	else {
		cout << "没找到！" << endl;
	}
}

//void main() {
//	testFind();
//}


