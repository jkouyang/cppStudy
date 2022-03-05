/*merge()——合并两个有序序列，存储到一个新序列中
* 函数形式
	1.iteator merge(beg1, end1, beg2, end2, result)
	两个有序容器的合并，合并后的容器仍然是有序的
	返回值：目标区间result内最后一个元素的下一位置迭代器
	调用2，默认_Pred=less<T>
	
	2.iteator merge(beg1, end1, beg2, end2, result, _Pred)
	可以自定义两个元素比较大小的规则(自定义_Pred)

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectMerge {
public:
	bool operator()(int val1, int val2) {//自己写的排序规则，和less<int>相同
		return val1 < val2;
	}
};

void testMerge() {
	//1.iteator merge(beg1, end1, beg2, end2, result)
	//两个有序容器的合并,合并之和也是有序的容器
	vector<int> vect1{ 1,3,5,7,9 };
	vector<int> vect2{ 2,4,6,8 };
	vector<int> vect3;
	vect3.resize(vect1.size() + vect2.size());
	vector<int>::iterator p1 =  merge(vect1.begin(),vect1.end(),vect2.begin(),vect2.end(),vect3.begin());
	for (int i : vect3) {cout << i << " ";}
	cout << endl;
	//返回值：目标区间result内最后一个元素的下一位置迭代器
	cout << *(p1-1) << endl;

	
	//2.iteator merge(beg1, end1, beg2, end2, result, _Pred)
	//可以自定义两个元素比较大小的规则(自定义_Pred)
	vector<int> vect4;
	vect4.resize(vect1.size() + vect2.size());
	vector<int>::iterator p2 = merge(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect4.begin(), mySelectMerge());
	for (int i : vect4) { cout << i << " "; }
	cout << endl;
	//返回值：目标区间result内最后一个元素的下一位置迭代器
	cout << *(p2 - 1) << endl;
}

//void main() {
//	testMerge();
//}