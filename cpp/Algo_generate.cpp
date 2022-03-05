/*generate()——替代区间内的元素
函数形式：
		void generate(beg, end, value, func);
		用func函数的返回值替代区间内的元素
注意：
	generate()通常用来向一个区间内填充随机数
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myGenerate {
public:
	int operator()() {
		return rand() % 10;
	}
};

void testGenerate() {
	vector<int> vect;
	vect.resize(10);
	//void generate(beg, end, value, func);
	//通常用来向一个区间内填充随机数
	srand((unsigned)time(NULL));
	generate(vect.begin(), vect.end(), myGenerate());

	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testGenerate();
//}

