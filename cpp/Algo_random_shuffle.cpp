/*random_shuffle()�������������ڵ�Ԫ�أ�ϴ�ƣ�C++11��д����C++17֮�Ͳ���֧��
 *shuffle()�������������ڵ�Ԫ�أ�ϴ��
* ������ʽ
	1.void random_shuffle(beg, end);��[beg,end)�����ڵ�Ԫ�ش���
	random_shuffleϴ���㷨�Ƚ�ʵ�ã�ʹ��ʱ�ǵü����������

	???
	2.void random_shuffle(beg, end, _RngFunc);��֪���Ǹ����
	ͨ���Դ���ĺ���������ϴ��
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <random>
#include <ctime>
using namespace std;

void testRandomShuffle() {
	vector<int> vect{ 2,1,5,3,7,6,4,9,8,0 };
	sort(vect.begin(), vect.end());
	for (auto i : vect) { cout << i << " "; }
	cout << endl;
	
	srand((unsigned int)time(NULL));//����ʱ�䣬��֤ÿ�δ��ҵ�˳�򶼲�һ��
	//Random_shuffle(vect.begin(), vect.end());//C++11��д����C++17֮�Ͳ���֧��Random_shuffle()������shuffle()
	default_random_engine defaultEngine;//�����������
	shuffle(vect.begin(), vect.end(), defaultEngine);//�����������ϴ��
	for (auto i : vect) { cout << i << " "; }
	cout << endl;
}

//void main() {
//	testRandomShuffle();
//}