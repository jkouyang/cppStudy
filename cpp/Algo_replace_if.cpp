/*replace_if()——容器内指定范围满足条件的元素替换为新元素
* 函数形式
	void replace(beg, end, _Pred, newvalue)
	容器内指定范围满足条件的元素替换为新元素
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectReplaceIf {
public:
	bool operator()(int val) {
		if (val == 3 || val == 2) {//将3和2换成新元素
			return true;
		}
		else {
			return false;
		}
	}
};

void testReplaceIf() {
	vector<int> vect{ 2,1,3,5,4,3,2,3,3 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//void replace(beg, end, _Pred, newvalue)
	//满足条件的元素替换为新元素
	replace_if(vect.begin(), vect.end(), mySelectReplaceIf(), 0);//将3和2换成新元素0
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testReplaceIf();
//}
