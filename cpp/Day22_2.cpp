/*容器
创建容器：	vector<数据类型> 容器名;
迭代器：	vector<数据类型>::iterator 迭代器名(指针)=容器名.begin();//起始迭代器
			vector<数据类型>::iterator 迭代器名(指针)=容器名.end();//终止迭代器
注意：
	1.每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	2.v.begin()返回迭代器，这个迭代器指向容器中第一个数据
	3.v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	4.vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint_22_2(int val) {
	cout << val << " ";
}

void test_22_2() {

	//创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
	vector<int> v1;
	for (int i = 0; i < 5; i++) {//向容器中放数据
		v1.push_back(i+1);
	}
	//创建迭代器
	vector<int>::iterator pBegin = v1.begin();
	vector<int>::iterator pEnd = v1.end();

	//第一种遍历方式：
	while (pBegin != pEnd) {
		cout << *pBegin << " ";
		pBegin++;
	}
	cout << endl;

	//第二种遍历方式：
	for (vector<int>::iterator pBegin = v1.begin(); pBegin != v1.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;

	//第三种遍历方式：
	//使用STL提供标准遍历算法  头文件 algorithm
	for_each(v1.begin(), v1.end(), myPrint_22_2);
	//当v1.begin()!=v1.end()时，把容器中v1.begin()对应的值(*v1.begin())传递给函数，v1.begin()++

}

//void main() {
//	test_22_2();
//}