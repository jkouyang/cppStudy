/*vector����
	vector���ݽṹ��**����ǳ�����**��Ҳ��Ϊ**��������**

	vector�����ĵ�������֧��������ʵĵ�����

	vector����ͨ�������𣺲�֮ͬ�����������Ǿ�̬�ռ䣬��vector����**��̬��չ**
				��̬��չ:��������ԭ�ռ�֮�������¿ռ䣬�����Ҹ�����ڴ�ռ䣬Ȼ��ԭ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�
	
	v.begin()	--	ָ���һ������λ�õĵ�����
	v.end()		--	ָ�����һ�����ݵĺ�һ��λ�õĵ�����
	v.rend()	--	ָ���һ�����ݵ�ǰһ��λ�õĵ�����
	v.rbegin()	--	ָ�����һ�����ݵ�λ�õĵ�����
	v.cbegin()	--	const+begin()ָ���һ������λ�õĳ���������
	v.cend()	--	const+end()
	v.crbegin()	--	const+rbegin()
	v.crend()	--	const+rend()

ע�⣺begin��end���صľ��������ɶ����Ƿ��ǳ���������������ǳ�����begin��end����const_iterator;������ǳ���������iterator��
	  cbegin��cend�ǲ����Ƕ������ǲ��ǳ���������ֵ����const_iterator
	  ������const���ԣ����������޸�Ԫ��
	����������������������������������������������������������������
	vector<int> v;
	const vector<int> cv;
	auto it1 = v.begin();   //it1������vector<int>::iterator
	auto it2 = cv.begin();  //it2������vector<int>::const_iterator
	auto it3 = v.cbegin();  //it3������vector<int>::const_iterator
	����������������������������������������������������������������

	vector���캯��
	1.vector<T> v;					//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
	2.vector(v.begin(), v.end());	//��v[begin(), end())�����е�Ԫ�ؿ���������
	3.vector(n, elem);				//���캯����n��elem����������
	4.vector(const vector &vec);	//�������캯��
*/

#include<iostream>
#include<vector>
using namespace std;

void myPrintVect_1(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testVect_1() {
	//1.Ĭ�Ϲ���  �޲ι���
	vector<int> v1;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i + 1);
	}
	myPrintVect_1(v1);

	//2.ͨ������ķ�ʽ���죬��v[begin(), end())�����е�Ԫ�ؿ�������һ������
	vector<int> v2(v1.begin(), v1.end());
	myPrintVect_1(v2);

	//3.���캯����n��elem������һ������
	vector<int> v3(5, 10);//5��10
	myPrintVect_1(v3);

	//4.��������
	vector<int> v4(v3);
	myPrintVect_1(v4);
}

//void main() {
//	testVect_1();
//}