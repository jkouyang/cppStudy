/*count()
* ������ʽ
	int count(beg, end, value);
	ͳ��[beg,end)����ֵ����value��Ԫ�ظ���
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testCount() {
	vector<int> vect{ 2,6,3,5,7,2,4,5,2,1 };
	cout << "Ԫ��ֵΪ2�ĸ���Ϊ��" << count(vect.begin(), vect.end(), 2) << endl;
}

//void main() {
//	testCount();
//}