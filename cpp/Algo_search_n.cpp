/*search_n()——查找序列中value连续出现n次的首位置
*
	函数形式：
		1.iterator search_n(beg, end, n, value);
		查找[beg,end)区间内value连续出现n次的序列，
		指向第一次匹配序列的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
		调用2，默认_Pred()=equal_to<T>

		2.iterator search_n(beg, end, n, value, _Pred);
		查找[beg,end)区间内value并满足_Pred()关系的值连续出现n次的序列，
		指向第一次匹配序列的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectSearchN {
public:
	bool operator()(int a, int b) {
		//a为[beg,end)传进的元素，b为value传进的元素
		//可以自定义它们之间满足某种关系
		return a == b - 1 ? true : false;
	}
};


void testSearchN() {
	vector<int> vect{ 1,2,2,3,3,3,4,4,4,4 };
	
	//1.iterator search_n(beg, end, n, value);
	//查找[beg, end)区间内value连续出现n次的序列，
	//指向第一次匹配序列的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
	vector<int>::iterator p1 = search_n(vect.begin(), vect.end(), 2, 4);
	if (p1 != vect.end()) {
		cout << "找到该序列，该序列第一个元素在vect1中下标为：" << p1 - vect.begin() << endl;
	}
	else {
		cout << "没找到该序列！" << endl;
	}

	//2.iterator search_n(beg, end, n, value, _Pred);
	//查找[beg, end)区间内value并满足_Pred()关系的值连续出现n次的序列，
	//指向第一次匹配序列的第一个元素，并返回该元素的迭代器，找不到返回结束迭代器end1()
	vector<int>::iterator p2 = search_n(vect.begin(), vect.end(), 2, 4, mySelectSearchN());
	if (p2 != vect.end()) {
		cout << "找到该序列，该序列第一个元素在vect1中下标为：" << p2 - vect.begin() << endl;
	}
	else {
		cout << "没找到该序列！" << endl;
	}
}

//void main() {
//	testSearchN();
//}


