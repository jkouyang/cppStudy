/*Set容器的插入和删除

函数原型：
	1.insert(elem);//在容器中插入元素
	2.erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器
	3.erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
	4.erase(elem);//删除容器中值为elem的元素
	5.clear();//清除所有元素

注意：set不支持随机访问，不支持[]，at()，"+"
*/

#include<iostream>
#include<set>
using namespace std;

void myPrintSet_3(const set<int>& s) {
	for (set<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}


void testSet_3() {
	set<int> s1;
	//1.insert(elem);//在容器中插入元素
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	myPrintSet_3(s1);

	//2.erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器
	s1.erase(s1.begin());
	myPrintSet_3(s1);

	//3.erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器
	s1.erase(s1.begin(), ++s1.begin());//不支持随机访问

	//4.erase(elem);//删除容器中值为elem的元素
	s1.erase(30);
	myPrintSet_3(s1);

	//5.clear();//清除所有元素
	s1.clear();
		//s1.erase(s1.begin(), s1.end());//这种方式也可以清空
	myPrintSet_3(s1);
}

//void main() {
//	testSet_3();
//}