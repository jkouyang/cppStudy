/*Map插入和删除

函数原型：
	1.insert(elem);//在容器中插入元素
		map[key] = value;//也可插入元素，不建议
	2.erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器
	3.erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
	4.erase(key);//删除容器中值为key的元素
	5.clear();//清除所有元素
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

void myPrintMap_3(map<int, string>& m) {
	for (map<int, string>::iterator pBegin = m.begin(); pBegin != m.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
}

void testMap_3() {
	map<int, string> m;
	//1.insert(elem);//在容器中插入元素
		//insert()有四种方式插入，主要是对的写的方式不同
		// 推荐第1，2种
	//第一种方式插入
	m.insert(pair<int, string>(1, "唐僧"));
	//第二种方式插入
	m.insert(make_pair(2, "孙悟空"));
	//第三种方式插入
	m.insert(map<int, string>::value_type(3, "猪八戒"));
	//第四种方式插入
	m[4] = "沙僧";//不建议使用[]的方式插入，例如map中已有key=4的数据，会覆盖原来的数据
	
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//第二次插入同键值的数据
	//四种插入方式只有第四种会覆盖原来的值，其他的都插入不进去(不报错)
	//[]用来访问数据，最好不要用来插入数据
	//[]用来访问没有该键值的元素时，会插入该键值
	m.insert(pair<int, string>(1, "丫丫"));
	m.insert(make_pair(2, "丫丫"));
	m.insert(map<int, string>::value_type(3, "丫丫"));
	m[4] = "丫丫";
	cout << m[10] << endl;//访问key=10(没有该键值)，插入默认value为空
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//2.erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器
	m.erase(m.begin());
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//3.erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
	m.erase(m.begin(), ++m.begin());
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//4.erase(key);//删除容器中值为key的元素
	m.erase(4);
	myPrintMap_3(m);
	cout << "=========================" << endl;

	//5.clear();//清除所有元素
	m.clear();
	myPrintMap_3(m);
}

//void main() {
//	testMap_3();
//}
