/*generate()������������ڵ�Ԫ��
������ʽ��
		void generate(beg, end, value, func);
		��func�����ķ���ֵ��������ڵ�Ԫ��
ע�⣺
	generate()ͨ��������һ����������������
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class myGenerate {
public:
	int operator()() {
		return rand() % 10;
	}
};

void testGenerate() {
	vector<int> vect;
	vect.resize(10);
	//void generate(beg, end, value, func);
	//ͨ��������һ����������������
	srand((unsigned)time(NULL));
	generate(vect.begin(), vect.end(), myGenerate());

	for (int i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testGenerate();
//}

