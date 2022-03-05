/*set容器排序
**示例二**   set存放自定义数据类型

注意：
	1.set容器默认排序规则为从小到大，掌握如何改变排序规则
	2.利用仿函数，可以改变排序规则
	3.对于自定义数据类型，set必须指定排序规则才可以插入数据
*/

#include<iostream>
#include<set>
#include<string>
using namespace std;

class PersonSet_7 {
public:
	string myName;
	int myAge;
	PersonSet_7(string name,int age) {
		this->myName = name;
		this->myAge = age;
	}
};

class myCompareSet_7 {//利用仿函数从新制定排序规则
public:
	//vs2019要在后面加const,常函数
	bool operator()(const PersonSet_7 &p1, const PersonSet_7 &p2) const {
		//降序，第一个数大于第二个数
		return p1.myAge > p2.myAge;
	}
};


void testSet_7() {
	set<PersonSet_7, myCompareSet_7> s;
	PersonSet_7 p1("唐僧", 25);
	PersonSet_7 p2("孙悟空", 999);
	PersonSet_7 p3("猪八戒", 758);
	PersonSet_7 p4("沙僧", 625);
	PersonSet_7 p5("白龙马", 422);
	//对自定义的数据类型都要先指定排序方式，才能插入
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	for (set<PersonSet_7, myCompareSet_7>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << pBegin->myName << "\t" << pBegin->myAge << endl;
	}
}

//void main() {
//	testSet_7();
//}