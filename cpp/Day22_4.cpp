/*
容器中嵌套容器，我们将所有数据进行遍历输出
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void test_22_4() {
	vector<vector<int>> v(5);//这种会先创建5个空的数据放进去，一般不这样写。
	cout << "sizeof(v):" << sizeof(v) << endl;//容器所占的空间都是32B
	cout << "v.size():" << v.size() << endl;
	cout << "sizeof(vector<vector<int>>):" << sizeof(vector<vector<int>>) << endl;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;
	cout << "v1.size():" << v1.size() << endl;


	cout << "sizeof(v1):" << sizeof(v1) << endl;
	cout << "sizeof(vector<int>):" << sizeof(vector<int>) << endl;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
		v5.push_back(i + 5);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	for (vector<vector<int>>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		for (vector<int>::iterator qBegin = pBegin->begin(); qBegin != pBegin->end(); qBegin++) {
			cout << *qBegin << " ";
		}
		cout <<"这有一行数据" << endl;
	}
}


//void main() {
//	test_22_4();
//}