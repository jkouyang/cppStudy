/*��ϵ�º�������ʵ�ֹ�ϵ�Ա�
**�º���ԭ�ͣ�**
	1.template<class T> bool equal_to<T>//����
	2.template<class T> bool not_equal_to<T>//������
	3.template<class T> bool greater<T>//����
	4.template<class T> bool greater_equal<T>//���ڵ���
	5.template<class T> bool less<T>//С��
	6.template<class T> bool less_equal<T>//С�ڵ���

�ܽ᣺���Ƕ�Ԫ���㣬��ϵ�º�������õľ���greater<>����
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class MyCompareFunobj_4{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void testFunobj_4() {
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (auto p:v) {
		cout << p << " ";
	}
	cout << endl;

	//�Լ�ʵ�ַº���
	//sort(v.begin(), v.end(), MyCompareFunobj_4());
	//STL�ڽ��º���  ���ڷº���
	sort(v.begin(), v.end(), greater<int>());

	for (auto p : v) {
		cout << p << " ";
	}
	cout << endl;
}


//void main() {
//	testFunobj_4();
//}









