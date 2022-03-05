/*reverse()——反转区间
* 函数形式
	void reverse(beg, end);
	反转

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testReverse() {
	vector<int> vect{ 2,1,3,5,4 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//void reverse(beg, end) 反转
	reverse(vect.begin(), vect.end());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main(){
//	testReverse();
//}