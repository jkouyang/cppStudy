/*rotate()����ƽ��
* ������ʽ
	void ratote(beg, mid, end);
		[mid,end)������ǰ��[beg,mid)�����ú�
		����ǰѭ��ƽ��mid-beg��Ԫ��	
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testRotate() {
	vector<int> vect{ 0,1,2,3,4,5,6,7,8,9 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//void ratote(beg, mid, end);
	//[mid, end)������ǰ��[beg, mid)�����ú󣬼���ǰѭ��ƽ��mid - beg��Ԫ��
	rotate(vect.begin(), vect.begin() + 4, vect.end());
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testRotate();
//}
