/*merge()�����ϲ������������У��洢��һ����������
* ������ʽ
	1.iteator merge(beg1, end1, beg2, end2, result)
	�������������ĺϲ����ϲ����������Ȼ�������
	����ֵ��Ŀ������result�����һ��Ԫ�ص���һλ�õ�����
	����2��Ĭ��_Pred=less<T>
	
	2.iteator merge(beg1, end1, beg2, end2, result, _Pred)
	�����Զ�������Ԫ�رȽϴ�С�Ĺ���(�Զ���_Pred)

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectMerge {
public:
	bool operator()(int val1, int val2) {//�Լ�д��������򣬺�less<int>��ͬ
		return val1 < val2;
	}
};

void testMerge() {
	//1.iteator merge(beg1, end1, beg2, end2, result)
	//�������������ĺϲ�,�ϲ�֮��Ҳ�����������
	vector<int> vect1{ 1,3,5,7,9 };
	vector<int> vect2{ 2,4,6,8 };
	vector<int> vect3;
	vect3.resize(vect1.size() + vect2.size());
	vector<int>::iterator p1 =  merge(vect1.begin(),vect1.end(),vect2.begin(),vect2.end(),vect3.begin());
	for (int i : vect3) {cout << i << " ";}
	cout << endl;
	//����ֵ��Ŀ������result�����һ��Ԫ�ص���һλ�õ�����
	cout << *(p1-1) << endl;

	
	//2.iteator merge(beg1, end1, beg2, end2, result, _Pred)
	//�����Զ�������Ԫ�رȽϴ�С�Ĺ���(�Զ���_Pred)
	vector<int> vect4;
	vect4.resize(vect1.size() + vect2.size());
	vector<int>::iterator p2 = merge(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect4.begin(), mySelectMerge());
	for (int i : vect4) { cout << i << " "; }
	cout << endl;
	//����ֵ��Ŀ������result�����һ��Ԫ�ص���һλ�õ�����
	cout << *(p2 - 1) << endl;
}

//void main() {
//	testMerge();
//}