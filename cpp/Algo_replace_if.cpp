/*replace_if()����������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
* ������ʽ
	void replace(beg, end, _Pred, newvalue)
	������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectReplaceIf {
public:
	bool operator()(int val) {
		if (val == 3 || val == 2) {//��3��2������Ԫ��
			return true;
		}
		else {
			return false;
		}
	}
};

void testReplaceIf() {
	vector<int> vect{ 2,1,3,5,4,3,2,3,3 };
	for (int i : vect) { cout << i << " "; }
	cout << endl;

	//void replace(beg, end, _Pred, newvalue)
	//����������Ԫ���滻Ϊ��Ԫ��
	replace_if(vect.begin(), vect.end(), mySelectReplaceIf(), 0);//��3��2������Ԫ��0
	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testReplaceIf();
//}
