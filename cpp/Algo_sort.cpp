/*sort()——排序
* 函数形式
	1.void sort(beg, end);默认排序，从小到大

	2.void sort(beg, end, _Pred);按_Pred指定排序

注意：
	sort()不保证相同元素之间的位置关系，不具有稳定性
	stable_sort()保证相同元素之间的位置关系，具有稳定性

bool cmp(int a, int b) {
	return a >= b;
}
重要：
	上面传入的参数a和b相等时，函数的返回值是true，这在C++标准中是不被允许的
	C++标准规定排序函数是弱序的，与数据结构上的稳定的排序相同，
	即对于相等的数，排序前后其相对位置不变，两值相等时只能返回false

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myPrintSort {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

class mySelectSor {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

vector<int> lambdaSort(vector<int>& score) {
	vector<int> order;
	for (int i = 0; i < score.size(); i++) {
		order.push_back(i);
	}
	sort(order.begin(), order.end(), [&score](const int& a, const int& b) {return score[a] > score[b]; });
	//order本来是顺序0,1,2...，相当于下标，score的下标按score的值从大到小排序，排序后的下标记录在order中
	//这一招妙啊
	return order;
}

void testSort() {
	vector<int> vect{ 2,1,5,3,7,6,4,9,8,0 };
	//1.void sort(beg, end);默认排序，从小到大
	sort(vect.begin(), vect.end());
	for_each(vect.begin(), vect.end(), myPrintSort());
	cout << endl;

	//2.void sort(beg, end, _Pred);按_Pred指定排序
	sort(vect.begin(), vect.end(), mySelectSor());
	for_each(vect.begin(), vect.end(), myPrintSort());

	//3.利用lambda
	//vect的下标按vect的值从大到小排序，排序后的下标记录在order中，这一招妙啊
	vector<int> order = lambdaSort(vect);
}

//void main() {
//	testSort();
//}

