/*谓词
	返回bool类型的仿函数称为**谓词**
	如果operator()接受一个参数，那么叫做一元谓词
	如果operator()接受两个参数，那么叫做二元谓词
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//1.如果operator()接受一个参数，那么叫做一元谓词
class myCompareFunobj_2a {//返回大于5的数
public:
	bool operator()(int val) {
		return val >= 5;
	}
};

//2.如果operator()接受两个参数，那么叫做二元谓词
class myCompareFunobj_2b {//从大到小排序
public:
	bool operator()(int val1,int val2) {
		return val1 > val2;
	}
};

void testFunobj_2() {
	vector<int> vect;
	vect.push_back(1);
	vect.push_back(6);
	vect.push_back(2);
	vect.push_back(4);
	vect.push_back(5);
	vect.push_back(3);
	//find_if(beg,end,op)，从左到右寻找第一个op为真的位置，并返回该位置的迭代器
	auto p1 = find_if(vect.begin(), vect.end(), myCompareFunobj_2a());//一元谓词
	cout << *p1 << endl;

	sort(vect.begin(), vect.end(), myCompareFunobj_2b());//二元谓词

	for (auto p2 : vect) {
		cout << p2 << " ";
	}
	cout << endl;
}

//void main() {
//	testFunobj_2();
//}




