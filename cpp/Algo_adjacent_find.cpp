/*adjacent_find()——查找第一次相邻重复(相等)的元素
*
	函数形式：
	1.iterator adjacent_find(beg, end);//查找相邻重复(相等)的元素	
	从左到右查找相邻重复的元素，并返回重复的第一个元素的迭代器，找不到返回结束迭代器end()

	2.iterator adjacent_find(beg, end, _Pred);//查找相邻满足某种关系的元素
	从左到右查找相邻满足某种关系的元素，并返第一个元素的迭代器，找不到返回结束迭代器end()

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectAdjacentIf {
public:
	bool operator()(const int& a, const int& b) const {
		if (b - a <= 5 && b-a>=-5) {//相邻元素的差小于等于5
			return true;
		}
		else {
			return false;
		}
	}
};

void tetsAdjacentIf() {
	//1.查找相邻重复(相等)的元素	iterator adjacent_find(beg, end);
	vector<int> vect1{ 1,2,3,4,5,5,6,6,7,7,8,8 };
	vector<int>::iterator p1 = adjacent_find(vect1.begin(), vect1.end());
	if (p1 != vect1.end()) {
		cout << "找到重复元素，第一个重复元素下标为：" << p1 - vect1.begin() << endl;
	}
	else {
		cout << "没找到！" << endl;
	}
	//2.查找相邻满足某种关系的元素	iterator adjacent_find(beg, end, _Pred);
	vector<int> vect2{ 1,100,108,112,150,200};
	vector<int>::iterator p2 = adjacent_find(vect2.begin(), vect2.end(), mySelectAdjacentIf());
	if (p2 != vect2.end()) {
		cout << "找到相邻元素的差小于等于5，第一个元素下标为：" << p2 - vect2.begin() << endl;
	}
	else {
		cout << "没找到！" << endl;
	}
}

//void main() {
//	tetsAdjacentIf();
//}