/*binary_search()——查找序列中是否有value这个元素
*
	函数形式：
	1.bool binary_search(beg, end, value);
	查找是否有value这个值，返回bool型

????	2.bool binary_search(beg, end, value, _Pred);
	????没搞懂
	查找是否有满足value+某种关系(_Pred)的值，返回bool型

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectBinarySearch {
public:
	bool operator()(int a,int b) {
		if (a%10 < b%10) {
			return true;
		}
		else {
			return false;
		}
	}
};

class mySelect1BinarySearch {
public:
	bool operator()(int a, int b) {
		if (a % 10 == b % 10) {
			return true;
		}
		else {
			return false;
		}
	}
};


void testBinarySearch() {
	//1.bool binary_search(beg, end, value);查找是否有value这个值，返回bool型
	vector<int> vect1{ 1,2,3,4,5,6,7,8,9,10 };
	bool ifSearch = binary_search(vect1.begin(), vect1.end(), 6);
	if (ifSearch){
		cout << "找到了" << endl;
	}
	else{
		cout << "未找到" << endl;
	}

	// ????
	//2.bool binary_search(beg, end, value, _Pred);查找是否有满足value + 某种关系(_Pred)的值，返回bool型
	vector<int> vect2{ 12,23,35,44,52,68,78,81,91,100 };
	sort(vect2.begin(), vect2.end(), mySelectBinarySearch());
	for (auto i : vect2) {
		cout << i << " ";
	}
	bool set = binary_search(vect2.begin(), vect2.end(), 8 ,mySelect1BinarySearch());
	if (set) {
		cout << "找到了" << endl;
	}
	else {
		cout << "未找到" << endl;
	}
}

//void main() {
//	testBinarySearch();
//}
