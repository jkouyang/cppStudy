/*Map容器排序

- map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
- 利用仿函数，可以改变排序规则
- 对于自定义数据类型，map必须要指定排序规则,同set容器

*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

class myCompareMap_5 {
public:
	bool operator()(int v1,int v2) const{//map里面是按键值排序，所以比较的是键值的数据类型
		return v1 > v2;
	}
};

void testMap_5() {
	map<int, string> m1;//默认排序，按键值的升序，只用传仿函数名，不用加()
	m1[3] = "Tom";
	m1[1] = "Yang";
	m1[2] = "Mary";
	m1[5] = "Job";
	m1[4] = "Ken";
	for (map<int, string>::iterator pBegin = m1.begin(); pBegin != m1.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
	cout << "=========================" << endl;

	map<int, string, myCompareMap_5> m2;//自定义，降序排列，只用传仿函数名，不用加()
	m2[3] = "Tom";
	m2[1] = "Yang";
	m2[2] = "Mary";
	m2[5] = "Job";
	m2[4] = "Ken";
	for (map<int, string, myCompareMap_5>::iterator pBegin = m2.begin(); pBegin != m2.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
}

//void main() {
//	testMap_5();
//}