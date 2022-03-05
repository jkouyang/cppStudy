/*for_each()
* 
	函数形式：
		template <class _Fn>
		_Fn for_each(beg, end, _Fn _func);

	遍历beg-end，并对这一段的数据进行_func()操作，返回值的类型与函数_func返回值相同

注意：
1._func如果是函数时，不建议使用for_each的返回值，容易混乱
2._func可以是仿函数，会返回一个该类对象，可以用来记录调用情况，可以一次遍历进行多个操作

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void myPrintForEach(int val) {
	cout << val << " ";
}

class myObejctForEach {
public:
	myObejctForEach():count(0),sum(0){}
	void operator()(int val) {	
		this->count++;
		sum += val;
	}
	int count;//记录调用次数
	int sum;//记录遍历数据的和
};

void testForEach() {
	//1._func如果是函数，遍历时对容器内的数据进行某一种操作
	//_func如果是函数时，不建议使用for_each的返回值，容易混乱
	vector<int> vect{ 1,2,3,4,5,6,7,8,9,10 };
	for_each(vect.begin(), vect.end(), myPrintForEach);
	cout << endl;

	//2._func可以是仿函数，会返回一个该类对象，
	//可以在仿函数的类中设置一些成员，用来记录调用情况，一次遍历可以进行多个操作
	myObejctForEach aa=for_each(vect.begin(), vect.end(), myObejctForEach());
	cout << "调用次数：" << aa.count << endl;
	cout << "sum：" << aa.sum << endl;
}

//void main() {
//	testForEach();
//}