/*vector容器
	vector数据结构和**数组非常相似**，也称为**单端数组**

	vector容器的迭代器是支持随机访问的迭代器

	vector与普通数组区别：不同之处在于数组是静态空间，而vector可以**动态扩展**
				动态扩展:并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
	
	v.begin()	--	指向第一个数据位置的迭代器
	v.end()		--	指向最后一个数据的后一个位置的迭代器
	v.rend()	--	指向第一个数据的前一个位置的迭代器
	v.rbegin()	--	指向最后一个数据的位置的迭代器
	v.cbegin()	--	const+begin()指向第一个数据位置的常量迭代器
	v.cend()	--	const+end()
	v.crbegin()	--	const+rbegin()
	v.crend()	--	const+rend()

注意：begin和end换回的具体类型由对象是否是常量来决定，如果是常量，begin和end换回const_iterator;如果不是常量，换回iterator；
	  cbegin和cend是不管是对象本身是不是常量，换回值都是const_iterator
	  具有了const属性，不能用于修改元素
	————————————————————————————————
	vector<int> v;
	const vector<int> cv;
	auto it1 = v.begin();   //it1类型是vector<int>::iterator
	auto it2 = cv.begin();  //it2类型是vector<int>::const_iterator
	auto it3 = v.cbegin();  //it3类型是vector<int>::const_iterator
	————————————————————————————————

	vector构造函数
	1.vector<T> v;					//采用模板实现类实现，默认构造函数
	2.vector(v.begin(), v.end());	//将v[begin(), end())区间中的元素拷贝给本身。
	3.vector(n, elem);				//构造函数将n个elem拷贝给本身
	4.vector(const vector &vec);	//拷贝构造函数
*/

#include<iostream>
#include<vector>
using namespace std;

void myPrintVect_1(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testVect_1() {
	//1.默认构造  无参构造
	vector<int> v1;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i + 1);
	}
	myPrintVect_1(v1);

	//2.通过区间的方式构造，将v[begin(), end())区间中的元素拷贝给另一个容器
	vector<int> v2(v1.begin(), v1.end());
	myPrintVect_1(v2);

	//3.构造函数将n个elem拷贝给一个容器
	vector<int> v3(5, 10);//5个10
	myPrintVect_1(v3);

	//4.拷贝构造
	vector<int> v4(v3);
	myPrintVect_1(v4);
}

//void main() {
//	testVect_1();
//}