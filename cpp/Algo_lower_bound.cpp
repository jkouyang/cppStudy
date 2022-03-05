/*lower_bound()
* 
*	函数形式：
		1.iterator lower_bound(beg, end, value)
		寻找有序序列中第一个大于等于value的元素
		调用2，默认_Pred=less<T>，return v1<v2;

		2.iterator lower_bound(beg, end, value,_Pred)
		寻找有序序列中第一个大于等于(value+_Pred关系)的元素
		有序序列中第一个_Pred返回值为**false**的值，即使大于等于(value + 某种关系)的元素

底层是二分法查找，因此要求序列有序
建议使用less<T>()和greater<T>(),不建议自定义仿函数任意把自己绕晕

建议使用：
	默认取大值(要求序列正序)：
	lower_bound(beg, end, value, less<T>())		返回第一个>=value的元素
	upper_bound(beg, end, value, less<T>())		返回第一个>value的元素
	自定义取小值(要求序列倒序)：
	lower_bound(beg, end, value, greater<T>())	返回第一个<=value的元素
	upper_bound(beg, end, value, greater<T>())	返回第一个<value的元素
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectLowerBound {
public:
	bool operator()(int a, int b) {
		//a是序列传进来的，b是value的值
		return a < b * b;
		//对应返回第一个a>=b*b
	}
};

void testLowerBound() {
	vector<int> vect{ 1,2,3,4,5,6,7,8,9 };

	//1.iterator lower_bound(beg, end, value)
	//寻找非递减序列中第一个大于等于value的元素
	vector<int>::iterator p1 = lower_bound(vect.begin(), vect.end(), 4);
	if (p1 != vect.end()) {
		cout << "找到该元素：" << *p1 <<"该元素在vect中下标为" << p1 - vect.begin() << endl;
	}
	else {
		cout << "没找到该序列！" << endl;
	}

	//不建议这样使用
	//2.iterator lower_bound(beg, end, value, _Pred)
	//寻找有序序列中第一个大于等于(value + 某种关系)的元素
	//有序序列中第一个_Pred返回值为false的值，即使大于等于(value + 某种关系)的元素
	vector<int>::iterator p2 = lower_bound(vect.begin(), vect.end(), 3, mySelectLowerBound());
	if (p2 != vect.end()) {
		cout << "找到该元素：" << *p2 << "该元素在vect中下标为" << p2 - vect.begin() << endl;
	}
	else {
		cout << "没找到该序列！" << endl;
	}

	//利用greater<T>()(要求序列倒序)
	vector<int> vect3{ 9,8,7,6,5,4,3,2,1 };
	vector<int>::iterator p3 = lower_bound(vect3.begin(), vect3.end(), 2 * 2, greater<int>());
	if (p3 != vect3.end()) {
		cout << "找到该元素：" << *p3 << "该元素在vect中下标为" << p3 - vect3.begin() << endl;
	}
	else {
		cout << "没找到该序列！" << endl;
	}
}


//void main() {
//	testLowerBound();
//}