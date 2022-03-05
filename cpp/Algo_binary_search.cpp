/*binary_search()���������������Ƿ���value���Ԫ��
*
	������ʽ��
	1.bool binary_search(beg, end, value);
	�����Ƿ���value���ֵ������bool��

????	2.bool binary_search(beg, end, value, _Pred);
	????û�㶮
	�����Ƿ�������value+ĳ�ֹ�ϵ(_Pred)��ֵ������bool��

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectBinarySearch {
public:
	bool operator()(int a,int b) {
		if (a%10 < b%10) {
			return true;
		}
		else {
			return false;
		}
	}
};

class mySelect1BinarySearch {
public:
	bool operator()(int a, int b) {
		if (a % 10 == b % 10) {
			return true;
		}
		else {
			return false;
		}
	}
};


void testBinarySearch() {
	//1.bool binary_search(beg, end, value);�����Ƿ���value���ֵ������bool��
	vector<int> vect1{ 1,2,3,4,5,6,7,8,9,10 };
	bool ifSearch = binary_search(vect1.begin(), vect1.end(), 6);
	if (ifSearch){
		cout << "�ҵ���" << endl;
	}
	else{
		cout << "δ�ҵ�" << endl;
	}

	// ????
	//2.bool binary_search(beg, end, value, _Pred);�����Ƿ�������value + ĳ�ֹ�ϵ(_Pred)��ֵ������bool��
	vector<int> vect2{ 12,23,35,44,52,68,78,81,91,100 };
	sort(vect2.begin(), vect2.end(), mySelectBinarySearch());
	for (auto i : vect2) {
		cout << i << " ";
	}
	bool set = binary_search(vect2.begin(), vect2.end(), 8 ,mySelect1BinarySearch());
	if (set) {
		cout << "�ҵ���" << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
}

//void main() {
//	testBinarySearch();
//}
