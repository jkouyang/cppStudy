/*vector预留空间——减少vector在动态扩展容量时的扩展次数
	reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问
*/

#include<iostream>
#include<vector>
using namespace std;

void testVect_7() {
	vector<int> v;
	v.reserve(100000);//利用reserve()可以给容器预留空间
	int* p = NULL;
	int num = 0;//统计开辟的次数
	for (int i = 0; i < 100000; i++) {
		v.push_back(i + 1);

		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << "统计开辟的次数num=" << num << endl;
}

//void main() {
//	testVect_7();
//}