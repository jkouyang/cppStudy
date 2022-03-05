/*count_if()
* 函数形式
	int count_if(beg, end, _Pred);
	统计[beg,end)区间内满足_Pred()函数的元素个数
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelecttCountIf {
public:
	bool operator()(int val) {//元素值大于3的个数
		return val > 3;
	}
};

void testCountIf() {
	vector<int> vect{ 2,6,3,5,7,2,4,5,2,1 };
	cout << "元素值大于3的个数为：" << count_if(vect.begin(), vect.end(), mySelecttCountIf()) << endl;
}

//void main() {
//	testCountIf();
//}