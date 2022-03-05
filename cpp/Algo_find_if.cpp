/*find_if()——查找满足_Pred()函数关系的第一个元素
*
	函数形式：
		iterator find_if(beg, end, _Pred);

	从左到右查找指定元素，找到第一个符合的元素，并返回该元素的迭代器，找不到返回结束迭代器end()
	_Pred是一个返回值为bool的函数，通常为仿函数

注意：


*/



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class PersonFindIf {
public:
	string myName;
	int myAge;
	PersonFindIf(string name, int age) :myName(name), myAge(age) {}
};

class mySelectFindIf {
public:
	bool operator()(const PersonFindIf& p) {
		if (p.myAge < 30) {//查找年龄30以下的
			return true;
		}
		else {
			return false;
		}
	}
};

void testFindIf() {
	PersonFindIf p1("刘备", 35);
	PersonFindIf p2("关羽", 32);
	PersonFindIf p3("张飞", 31);
	PersonFindIf p4("赵云", 30);
	PersonFindIf p5("诸葛亮", 25);
	PersonFindIf p6("孙尚香", 20);
	vector<PersonFindIf> vect{ p1, p2, p3, p4, p5, p6 };
	vector<PersonFindIf>::iterator p = find_if(vect.begin(), vect.end(), mySelectFindIf());
	if (p != vect.end()) {
		cout << "找到该元素，下标为：" << p - vect.begin() << endl;
		cout << p->myName << "\t" << p->myAge << endl;
	}
	else {
		cout << "没找到！" << endl;
	}
}

//void main() {
//	testFindIf();
//}

