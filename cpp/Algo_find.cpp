/*find()�������ҵ�һ��ָ��Ԫ��
*
	������ʽ��
		iterator find(beg, end, value);
	
	�����Ҳ���ָ��Ԫ�أ��ҵ���һ�����ϵ�Ԫ�أ������ظ�Ԫ�صĵ��������Ҳ������ؽ���������end()

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void testFind() {
	vector<int> vect{ 1,2,3,4,5,6,6,6,6,10 };
	vector<int>::iterator p = find(vect.begin(), vect.end(), 6);
	if (p != vect.end()) {
		cout << "�ҵ���Ԫ�أ��±�Ϊ��" << p - vect.begin() << endl;
	}
	else {
		cout << "û�ҵ���" << endl;
	}
}

//void main() {
//	testFind();
//}


