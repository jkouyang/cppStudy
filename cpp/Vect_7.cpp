/*vectorԤ���ռ䡪������vector�ڶ�̬��չ����ʱ����չ����
	reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
*/

#include<iostream>
#include<vector>
using namespace std;

void testVect_7() {
	vector<int> v;
	v.reserve(100000);//����reserve()���Ը�����Ԥ���ռ�
	int* p = NULL;
	int num = 0;//ͳ�ƿ��ٵĴ���
	for (int i = 0; i < 100000; i++) {
		v.push_back(i + 1);

		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << "ͳ�ƿ��ٵĴ���num=" << num << endl;
}

//void main() {
//	testVect_7();
//}