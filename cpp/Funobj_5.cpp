/*�߼��º�������ʵ���߼�����

**����ԭ�ͣ�**
	1.template<class T> bool logical_and<T>//�߼���
	2.template<class T> bool logical_or<T>//�߼���
	3.template<class T> bool logical_not<T>//�߼���

�ܽ᣺�߼��º���ʵ��Ӧ�ý��٣��˽⼴��
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void testFunobj_5() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (auto it : v) {
		cout << it << " ";
	}
	cout << endl;

	//�߼���  ��v�������˵�v2�У���ִ���߼�������
	vector<bool> v2;
	v2.resize(v.size());
	//transform()���˵�ʱ����Խ��������߼�
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (auto it : v2) {
		cout << it << " ";
	}
	cout << endl;
}

//void main() {
//	testFunobj_5();
//}


