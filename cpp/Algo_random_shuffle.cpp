/*random_shuffle()——打乱区间内的元素，洗牌，C++11的写法，C++17之和不再支持
 *shuffle()——打乱区间内的元素，洗牌
* 函数形式
	1.void random_shuffle(beg, end);将[beg,end)区间内的元素打乱
	random_shuffle洗牌算法比较实用，使用时记得加随机数种子

	???
	2.void random_shuffle(beg, end, _RngFunc);不知道是干嘛的
	通过自传入的函数来打乱洗牌
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <random>
#include <ctime>
using namespace std;

void testRandomShuffle() {
	vector<int> vect{ 2,1,5,3,7,6,4,9,8,0 };
	sort(vect.begin(), vect.end());
	for (auto i : vect) { cout << i << " "; }
	cout << endl;
	
	srand((unsigned int)time(NULL));//加入时间，保证每次打乱的顺序都不一样
	//Random_shuffle(vect.begin(), vect.end());//C++11的写法，C++17之和不再支持Random_shuffle()，请用shuffle()
	default_random_engine defaultEngine;//定义随机种子
	shuffle(vect.begin(), vect.end(), defaultEngine);//利用随机种子洗牌
	for (auto i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testRandomShuffle();
//}