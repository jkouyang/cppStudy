/*Map容器(用的多)——python字典
map中所有元素都是pair：
	pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
	所有元素都会根据元素的键值自动排序

本质：
	map/multimap属于**关联式容器**，底层结构是用二叉树实现

优点：
	可以根据key值快速找到value值

map和multimap区别：
	map不允许容器中有重复key值元素
	multimap允许容器中有重复key值元素

构造函数：
	1.map<T1, T2> mp;//map默认构造函数:
	2.map(const map &mp);//拷贝构造函数

赋值：
	map& operator=(const map &mp);//重载等号操作符

总结：map中所有元素都是成对出现，插入数据时候要使用对组
	  map在插入元素时，默认按键值排序
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

void myPrintMap_1(map<int,string>& m) {
	for (map<int, string>::iterator pBegin = m.begin(); pBegin != m.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
}

void testMap_1() {
	//1.map<T1, T2> mp;//map默认构造函数:
	map<int, string> m1;
	m1.insert(pair<int, string>(105, "唐僧"));
	m1.insert(pair<int, string>(102, "孙悟空"));
	m1.insert(pair<int, string>(101, "猪八戒"));
	m1.insert(pair<int, string>(104, "沙僧"));
	m1.insert(pair<int, string>(103, "白龙马"));
	myPrintMap_1(m1);
	cout<< "=========================" << endl;

	//2.map(const map &mp);//拷贝构造函数
	map<int, string> m2(m1);
	myPrintMap_1(m2);
	cout << "=========================" << endl;

	//赋值：map& operator=(const map & mp);//重载等号操作符
	map<int, string> m3;
	m3 = m2;
	myPrintMap_1(m3);

}

//void main() {
//	testMap_1();
//}