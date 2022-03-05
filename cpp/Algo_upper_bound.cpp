/*upper_bound()
*
*	������ʽ��
		1.iterator upper_bound(beg, end, value)
		Ѱ�����������е�һ�����ڵ���value��Ԫ��
		����2��Ĭ��_Pred=less<T>��return v1<v2;

		2.iterator upper_bound(beg, end, value,_Pred)
		Ѱ�����������е�һ�����ڵ���(value+_Pred��ϵ)��Ԫ��
		���������е�һ��_Pred����ֵΪ**true**��ֵ����ʹ���ڵ���(value + ĳ�ֹ�ϵ)��Ԫ��

�ײ��Ƕ��ַ����ң����Ҫ����������
����ʹ��less<T>()��greater<T>(),�Զ���º���������Լ�����

����ʹ�ã�
	Ĭ��ȡ��ֵ(Ҫ����������)��
	lower_bound(beg, end, value, less<T>())		���ص�һ��>=value��Ԫ��
	upper_bound(beg, end, value, less<T>())		���ص�һ��>value��Ԫ��
	�Զ���ȡСֵ(Ҫ�����е���)��
	lower_bound(beg, end, value, greater<T>())	���ص�һ��<=value��Ԫ��
	upper_bound(beg, end, value, greater<T>())	���ص�һ��<value��Ԫ��
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class mySelectUpperBound {
public:
	//ע�⣺����ط����κ�lower_bound��һ��
	bool operator()(int b, int a) {
		//b��value��ֵ��a�����д�������
		return a > b * b;
		//��Ӧ���ص�һ��a>b*b
	}
};

void testUpperBound() {
	vector<int> vect{ 1,2,3,4,5,6,7,8,9 };

	//1.iterator upper_bound(beg, end, value)
	//Ѱ�ҷǵݼ������е�һ�����ڵ���value��Ԫ��
	vector<int>::iterator p1 = upper_bound(vect.begin(), vect.end(), 6);
	if (p1 != vect.end()) {
		cout << "�ҵ���Ԫ�أ�" << *p1 << "��Ԫ����vect���±�Ϊ" << p1 - vect.begin() << endl;
	}
	else {
		cout << "û�ҵ������У�" << endl;
	}

	//����������ʹ��
	//2.iterator lower_bound(beg, end, value, _Pred)
	//Ѱ�����������е�һ�����ڵ���(value + ĳ�ֹ�ϵ)��Ԫ��
	//���������е�һ��_Pred����ֵΪfalse��ֵ����ʹ���ڵ���(value + ĳ�ֹ�ϵ)��Ԫ��
	vector<int>::iterator p2 = upper_bound(vect.begin(), vect.end(), 2, mySelectUpperBound());
	if (p2 != vect.end()) {
		cout << "�ҵ���Ԫ�أ�" << *p2 << "��Ԫ����vect���±�Ϊ" << p2 - vect.begin() << endl;
	}
	else {
		cout << "û�ҵ������У�" << endl;
	}

	//����greater<T>()(Ҫ�����е���)
	vector<int> vect3{ 9,8,7,6,5,4,3,2,1 };
	vector<int>::iterator p3 = upper_bound(vect3.begin(), vect3.end(), 2*2, greater<int>());
	if (p3 != vect3.end()) {
		cout << "�ҵ���Ԫ�أ�" << *p3 << "��Ԫ����vect���±�Ϊ" << p3 - vect3.begin() << endl;
	}
	else {
		cout << "û�ҵ������У�" << endl;
	}
}


//void main() {
//	testUpperBound();
//}