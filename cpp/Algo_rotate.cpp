/*rotate()——平移
* 函数形式
	void ratote(beg, mid, end);
		[mid,end)区间置前，[beg,mid)区间置后
		即向前循环平移mid-beg个元素	
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testRotate() {
	vector<int> vect{ 0,1,2,3,4,5,6,7,8,9 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//void ratote(beg, mid, end);
	//[mid, end)区间置前，[beg, mid)区间置后，即向前循环平移mid - beg个元素
	rotate(vect.begin(), vect.begin() + 4, vect.end());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testRotate();
//}
