/*replace()������������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
* ������ʽ
	void replace(beg, end, oldvalue, newvalue)
	��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testReplace() {
	vector<int> vect{ 2,1,3,5,4,3,2,3,3 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//void replace(beg, end, oldvalue, newvalue)
	//��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
	replace(vect.begin(), vect.end(), 3, 300);
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main(){
//	testReplace();
//}