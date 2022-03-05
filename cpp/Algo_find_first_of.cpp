/*find_first_of()
*
	函数形式：
		1.iterator find(beg1, end1, beg2, end2);
		查找[beg1,end1)区间内与[beg2，end2)区间内任意元素匹配的元素，
		指向匹配的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()

		2.iterator find(beg1, end1, beg2, end2, _Pred);
		查找[beg1,end1)区间内与[beg2，end2)区间内任意元素满足_Pred()关系的元素，
		指向匹配的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
		类似find_if()
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectFindFirstOf {
public:
	bool operator()(int a, int b) {
		//a为[beg1,end1)传进的元素，b为[beg2,end2)传进的元素
		//可以自定义它们之间满足某种关系，类似find_if
		return a == b + 1 ? true : false;
	}
};


void testFindFirstOf() {
	vector<int> vect1{ 1,2,3,4,5,6,6,6,6,10 };
	vector<int> vect2{ -7,-6,-5,5,10 };

	//1.函数形式：iterator find(beg1, end1, beg2, end2);
	//查找[beg1, end1)区间内与[beg2，end2)区间内任意元素匹配的元素，
	//指向匹配的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
	vector<int>::iterator p1 = find_first_of(vect1.begin(), vect1.end(), vect2.begin(),vect2.end());
	if (p1 != vect1.end()) {
		cout << "找到该元素:" << *p1 << "，在vect1中下标为：" << p1 - vect1.begin() << endl;
	}
	else {
		cout << "没找到！" << endl;
	}

	//2.iterator find(beg1, end1, beg2, end2, _Pred);
	//查找[beg1,end1)区间内与[beg2，end2)区间内任意元素满足_Pred()关系的元素，
	//指向匹配的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
	vector<int>::iterator p2 = find_first_of(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), mySelectFindFirstOf());
	if (p2 != vect1.end()) {
		cout << "找到该元素:" << *p2 << "，在vect1中下标为：" << p2 - vect1.begin() << endl;
	}
	else {
		cout << "没找到！" << endl;
	}
	
}

//void main() {
//	testFindFirstOf();
//}


