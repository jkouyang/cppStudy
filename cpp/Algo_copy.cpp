/*copy()����������ָ����Χ��Ԫ�ؿ�������һ������
* ������ʽ
	iterator copy(beg, end, result)
	������ָ����Χ��Ԫ�ؿ�������һ������
	����ֵ��Ŀ������result�����һ��Ԫ�ص���һλ�õ�����
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testCopy() {
	vector<int> vect1{ 2,1,3,5,4 };
	for (int i : vect1) { cout << i << " "; }
	cout << endl;

	vector<int> vect2;
	//Ҫ���ٿռ�(resize)��������Ԥ���ռ�(reserve)
	//vect2.reserve(vect1.size());//����
	vect2.resize(vect1.size());
	vector<int>::iterator p = copy(vect1.begin(), vect1.end(), vect2.begin());
	for (int i : vect2) { cout << i << " "; }
	cout << endl;
	//����ֵ��Ŀ������result�����һ��Ԫ�ص���һλ�õ�����
	cout << *(p - 1) << endl;
}

//void main() {
//	testCopy();
//}