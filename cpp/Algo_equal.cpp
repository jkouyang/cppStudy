/*equal()——判断两个区间元素是否相等
*
	函数形式：
		1.bool equal(beg1, end1, beg2);
		比较[beg1,end1)和[beg2,...)，调用2，默认_Pred=equal_to<T>

		2.bool equal(beg1, end1, beg2, _Pred);
		比较[beg1,end1)和[beg2,...)，可自定义_Pred

		3.bool equal(beg1, end1, beg2, end2);
		比较[beg1,end1)和[beg2,end2)，调用4，默认_Pred=equal_to<T>

		4.bool equal(beg1, end1, beg2, end2, _Pred);
		比较[beg1,end1)和[beg2,end2)，可自定义_Pred

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myEqual {
public:
	bool operator()(int a, int b) {//自定义比较
		return b == a * a;//后者的数据是否是前者的平方
	}
};

void testEqual() {
	vector<int> vect1{ 1,2,3,4 };
	vector<int> vect2{ 1,2,3,4,5 };
	vector<int> vect3{ 1,4,9,16 };

	bool set1 = equal(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
	bool set2 = equal(vect1.begin(), vect1.end(), vect2.begin(), vect2.end()-1);
	//后者数据较长时，只要前面的相等就返回真；如果后者的数据较短就会报错
	bool set3 = equal(vect1.begin(), vect1.end(), vect2.begin());
	//自定义的比较
	bool set4 = equal(vect1.begin(), vect1.end(), vect3.begin(), myEqual());

	cout << "set1：" << set1 << endl;
	cout << "set2：" << set2 << endl;
	cout << "set3：" << set3 << endl;
	cout << "set4：" << set4 << endl;
}

//void main() {
//	testEqual();
//}