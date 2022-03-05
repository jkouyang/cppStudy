/*includes()������������a����������b�е�λ��
* ������ʽ
	1.void includes(beg1, end1, beg2, end2);
		�ж�����[beg1,end1)�Ƿ����[beg2,end2)
		����2��Ĭ��_Pred=less<T>

	2..void includes(beg1, end1, beg2, end2, _Pred);

ע�⣺
	�������б�������������
	������������ǵ�����ô��_Pred=greater<T>()
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void testIncludes() {
	vector<int> vect1{ 0,1,2,3,4,5,6,7,8,9 };
	vector<int> vect2{ 0,1,2,3,4 };
	vector<int> vect3{ 5,6,7,8,9 };
	vector<int> vect4{ 5,6,7,8,10 };

	//1.void includes(beg1, end1, beg2, end2);
	//�ж�����[beg1, end1)�Ƿ����[beg2, end2),Ĭ��_Pred = less<T>
	bool set1 = includes(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
	bool set2 = includes(vect1.begin(), vect1.end(), vect3.begin(), vect3.end());
	bool set3 = includes(vect1.begin(), vect1.end(), vect4.begin(), vect4.end());

	cout << "set1:" << set1 << endl;
	cout << "set2:" << set2 << endl;
	cout << "set3:" << set3 << endl;

	//2.������������ǵ�����ô��_Pred=greater<T>()
	vector<int> vect5{ 9,8,7,6,5,4,3,2,1 };
	vector<int> vect6{ 4,3,2,1 };
	bool set4 = includes(vect5.begin(), vect5.end(), vect6.begin(), vect6.end(), greater<int>());
	cout << "set4:" << set4 << endl;
}

//void main() {
//	testIncludes();
//}
