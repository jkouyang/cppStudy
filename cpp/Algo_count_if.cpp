/*count_if()
* ������ʽ
	int count_if(beg, end, _Pred);
	ͳ��[beg,end)����������_Pred()������Ԫ�ظ���
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelecttCountIf {
public:
	bool operator()(int val) {//Ԫ��ֵ����3�ĸ���
		return val > 3;
	}
};

void testCountIf() {
	vector<int> vect{ 2,6,3,5,7,2,4,5,2,1 };
	cout << "Ԫ��ֵ����3�ĸ���Ϊ��" << count_if(vect.begin(), vect.end(), mySelecttCountIf()) << endl;
}

//void main() {
//	testCountIf();
//}