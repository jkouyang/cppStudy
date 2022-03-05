/*search()——查找序列中与子序列匹配的位置
*
	函数形式：
		1.iterator search(beg1, end1, beg2, end2);
		查找[beg1,end1)区间内与[beg2，end2)序列匹配的序列，
		指向第一次匹配序列的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
		调用2，默认_Pred()=equal_to<T>

		2.iterator search(beg1, end1, beg2, end2, _Pred);
		查找[beg1,end1)区间内与[beg2，end2)序列满足_Pred()关系匹配的序列，
		指向第一次匹配序列的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()

search();查找序列中与子序列第一次匹配的位置，指向第一次匹配序列的第一个元素
find_end();  查找序列中与子序列最后一次匹配的位置，指向最后一次匹配序列的第一个元素
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectSearch {
public:
	bool operator()(int a, int b) {
		//a为[beg1,end1)传进的元素，b为[beg2,end2)传进的元素
		//可以自定义它们之间满足某种关系
		return a == b - 1 ? true : false;
	}
};


void testSearch() {
	vector<int> vect1{ 3,4,5,3,4,5,6,4,5,6 };
	vector<int> vect2{ 4,5,6 };

	//1.iterator search(beg1, end1, beg2, end2);
	//查找[beg1, end1)区间内与[beg2，end2)序列匹配的序列，
	//指向第一次匹配序列的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
	vector<int>::iterator p1 = search(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
	if (p1 != vect1.end()) {
		cout << "找到该序列，该序列第一个元素在vect1中下标为：" << p1 - vect1.begin() << endl;
	}
	else {
		cout << "没找到该序列！" << endl;
	}

	//2.iterator search(beg1, end1, beg2, end2, _Pred);
	//查找[beg1, end1)区间内与[beg2，end2)序列满足_Pred()关系匹配的序列，
	//指向第一次匹配序列的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
	vector<int>::iterator p2 = search(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), mySelectSearch());
	if (p2 != vect1.end()) {
		cout << "找到该序列，该序列第一个元素在vect1中下标为：" << p2 - vect1.begin() << endl;
	}
	else {
		cout << "没找到该序列！" << endl;
	}
}

//void main() {
//	testSearch();
//}


