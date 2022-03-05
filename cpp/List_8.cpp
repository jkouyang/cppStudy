/*List 自定义数据类型的排序
	通过sort()实现

案例：
	将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
	排序规则：按照年龄进行降序，年龄相同时按身高升序

实现方法：在类外实现（注意于List_7.cpp(类内实现)对比）
		这种方法可以实现任何想要的排序方式
*/


#include<iostream>
#include<string>
#include<list>
using namespace std;

class PersonList_8 {
public:
	string myName;
	int myAge;
	int myHeight;
	PersonList_8(string name, int age, int height) {
		this->myName = name;
		this->myAge = age;
		this->myHeight = height;
	}
};

void myPrintList_8(const list<PersonList_8>& L) {
	for (list<PersonList_8>::const_iterator pBegin = L.begin(); pBegin != L.end(); pBegin++) {
		cout << pBegin->myName << "\t" << pBegin->myAge << "\t" << pBegin->myHeight << endl;
	}
}

bool myCompareList_8(PersonList_8 p1, PersonList_8 p2) {//指定规则，这种方法可以实现任何想要的排序方式
	if (p1.myAge == p2.myAge) {
		return p1.myHeight < p2.myHeight;//年龄相等时，按身高升序（第一个数据小于第二个数据）
	}
	else {
		return p1.myAge > p2.myAge;//先按年龄降序（第一个数据大于第二个数据）
	}
}

void testList_8() {
	PersonList_8 p1("Tom", 17, 178);
	PersonList_8 p2("Mary", 18, 175);
	PersonList_8 p3("Job", 25, 172);
	PersonList_8 p4("Kim", 21, 168);
	PersonList_8 p5("Yang", 17, 188);
	PersonList_8 p6("Tian", 17, 168);
	PersonList_8 p7("Mei", 17, 175);
	PersonList_8 p8("Zhen", 17, 171);

	list<PersonList_8> L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);
	L.push_back(p8);
	cout << "============原始数据============" << endl;
	myPrintList_8(L);
	//默认排序会报错，因为没有重写"<"号，无法对比两个自定义数据类型的大小
	/*cout << "========sort默认排序后==========" << endl;
	L.sort();
	myPrintList_8(L);*/
	cout << "===========sort排序后===========" << endl;
	L.sort(myCompareList_8);//自定义的数据类型一定要自己指定排序规则，只用传函数名，不用加()带参数
	myPrintList_8(L);
}

//void main() {
//	testList_8();
//}