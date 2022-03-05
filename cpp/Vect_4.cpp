/*vector插入和删除
	1.push_back(ele); //尾部插入元素ele
	2.pop_back(); //删除最后一个元素
	3.insert(const_iterator pos, ele);//迭代器指向位置pos插入元素ele
	4.insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
	5.insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
	6.erase(const_iterator pos);//删除迭代器指向的元素
	7.erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
	8.clear();//删除容器中所有元素

*/


#include<iostream>
#include<vector>
using namespace std;

void myPrintVect_4(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testVect_4() {
	vector<int> v1;
	//1.push_back(ele); //尾插法
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	myPrintVect_4(v1);


	//2.pop_back();//尾删法
	v1.pop_back();
	myPrintVect_4(v1);

	//3.insert(const_iterator pos, ele);//迭代器指向位置pos插入元素ele
	v1.insert(v1.begin() +3, 101);//第一个参数是迭代器，下标为3的地方插入
	myPrintVect_4(v1);

	//4.insert(const_iterator pos, int count, ele);//迭代器指向位置pos插入count个元素ele
	v1.insert(v1.begin() + 3, 5, 100);//第一个参数是迭代器，下标为3的地方插入5个100
	myPrintVect_4(v1);

	//5.insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值
	vector<int> v2;
	v2.insert(v2.begin(), v1.begin() + 1, v1.begin() + 3);
	myPrintVect_4(v2);

	//6.erase(const_iterator pos);//删除迭代器指向的元素
	v1.erase(v1.begin()+3);//参数是迭代器，删除下标为3的元素
	myPrintVect_4(v1);

	//7.erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
	v1.erase(v1.begin() + 1, v1.begin() + 3);//参数是迭代器，删除下标为1到3之间(下标1和2)的元素
	myPrintVect_4(v1);


	//8.clear();//删除容器中所有元素
	v1.clear();
	myPrintVect_4(v1);
	cout << "v1的容量：" << v1.capacity() << endl;
	cout << "v1的长度：" << v1.size() << endl;

}

//void main() {
//	testVect_4();
//}