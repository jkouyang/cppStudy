/*List 自定义数据类型的排序
	通过sort()实现

案例：
	将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
	排序规则：按照年龄进行拍序

实行方法：在类的里面完成"<"号和">"号的重载
*/


#include<iostream>
#include<string>
#include<list>
using namespace std;

class PersonList_7 {
public:
	string myName;
	int myAge;
	int myHeight;
	PersonList_7(string name,int age,int height) {
		this->myName = name;
		this->myAge = age;
		this->myHeight = height;
	}
	bool operator<(PersonList_7 per) {//重载<号，使得list可以使用sort()默认排序
		return this->myAge < per.myAge;
	}
	bool operator>(PersonList_7 per) {//重载<号，使得list可以使用sort()降序排序
		return this->myAge > per.myAge;
	}
};

void myPrintList_7(const list<PersonList_7>& L) {
	for (list<PersonList_7>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {
		cout << pBegin->myName << "\t" << pBegin->myAge << "\t" << pBegin->myHeight << endl;
	}
}

bool myCompareList_7(PersonList_7 p1, PersonList_7 p2) {//指定规则，从大到小
	//降序：就让第一个数大于第二个数
	return p1 > p2;
}

void testList_7() {
	PersonList_7 p1("Tom", 17, 178);
	PersonList_7 p2("Mary", 18, 175);
	PersonList_7 p3("Job", 25, 172);
	PersonList_7 p4("Kim", 21, 168);
	PersonList_7 p5("Yang", 17, 188);
	list<PersonList_7> L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	cout << "============原始数据============" << endl;
	myPrintList_7(L);
	cout << "========sort默认排序后==========" << endl;
	L.sort();
	myPrintList_7(L);
	cout << "========sort降序排序后==========" << endl;
	L.sort(myCompareList_7);
	myPrintList_7(L);
}

//void main() {
//	testList_7();
//}