/*replace()——将容器内指定范围的旧元素修改为新元素
* 函数形式
	void replace(beg, end, oldvalue, newvalue)
	将容器内指定范围的旧元素修改为新元素
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testReplace() {
	vector<int> vect{ 2,1,3,5,4,3,2,3,3 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//void replace(beg, end, oldvalue, newvalue)
	//将容器内指定范围的旧元素修改为新元素
	replace(vect.begin(), vect.end(), 3, 300);
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main(){
//	testReplace();
//}