/*sort()��������
* ������ʽ
	1.void sort(beg, end);Ĭ�����򣬴�С����

	2.void sort(beg, end, _Pred);��_Predָ������

ע�⣺
	sort()����֤��ͬԪ��֮���λ�ù�ϵ���������ȶ���
	stable_sort()��֤��ͬԪ��֮���λ�ù�ϵ�������ȶ���

bool cmp(int a, int b) {
	return a >= b;
}
��Ҫ��
	���洫��Ĳ���a��b���ʱ�������ķ���ֵ��true������C++��׼���ǲ��������
	C++��׼�涨������������ģ������ݽṹ�ϵ��ȶ���������ͬ��
	��������ȵ���������ǰ�������λ�ò��䣬��ֵ���ʱֻ�ܷ���false

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myPrintSort {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

class mySelectSor {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};

vector<int> lambdaSort(vector<int>& score) {
	vector<int> order;
	for (int i = 0; i < score.size(); i++) {
		order.push_back(i);
	}
	sort(order.begin(), order.end(), [&score](const int& a, const int& b) {return score[a] > score[b]; });
	//order������˳��0,1,2...���൱���±꣬score���±갴score��ֵ�Ӵ�С�����������±��¼��order��
	//��һ���
	return order;
}

void testSort() {
	vector<int> vect{ 2,1,5,3,7,6,4,9,8,0 };
	//1.void sort(beg, end);Ĭ�����򣬴�С����
	sort(vect.begin(), vect.end());
	for_each(vect.begin(), vect.end(), myPrintSort());
	cout << endl;

	//2.void sort(beg, end, _Pred);��_Predָ������
	sort(vect.begin(), vect.end(), mySelectSor());
	for_each(vect.begin(), vect.end(), myPrintSort());

	//3.����lambda
	//vect���±갴vect��ֵ�Ӵ�С�����������±��¼��order�У���һ���
	vector<int> order = lambdaSort(vect);
}

//void main() {
//	testSort();
//}

