/*set容器排序
**示例一**   set存放内置数据类型

	set容器默认排序规则为从小到大，掌握如何改变排序规则
	利用仿函数，可以改变排序规则
*/

#include<iostream>
#include<set>
using namespace std;

class myCompareSet_6 {//利用仿函数从新制定排序规则
public:
	bool operator()(int v1, int v2) const {//vs2019要在后面加const,常函数
		//降序，第一个数大于第二个数
		return v1 > v2;
	}
};

void testSet_6() {
	set<int> s1;

	s1.insert(10);
	s1.insert(60);
	s1.insert(20);
	s1.insert(40);
	s1.insert(50);
	s1.insert(30);
	//默认从小到大
	for (set<int>::const_iterator pBegin = s1.begin(); pBegin != s1.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;

	set<int,myCompareSet_6> s2;
	s2.insert(10);
	s2.insert(60);
	s2.insert(20);
	s2.insert(40);
	s2.insert(50);
	s2.insert(30);
	for (set<int, myCompareSet_6>::const_iterator pBegin = s2.begin(); pBegin != s2.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

//void main() {
//	testSet_6();
//}