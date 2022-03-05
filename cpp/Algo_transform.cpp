/*transform()����������������һ�ε����ݽ���_func()��������_func�ķ���ֵ�洢��result��ͷ�ķ�Χ��
*
	������ʽ��
	1.һԪ����
		iterator transform(beg, end, result, _func);
		����beg-end��������һ�ε����ݽ���_func()��������_func�ķ���ֵ�洢��result��ͷ�ķ�Χ��
		����ֵ��Ŀ������result�����һ����ת��Ԫ�ص���һλ�õ�����,Ҳ��δ�����ǵ�Ԫ�ص�λ�õ�����
	
	2.��Ԫ����
		iterator transform(beg1, end1, beg2, result, _func)
		ʹ��[beg1, end1)��Χ�ڵ�ÿ��Ԫ����Ϊ��һ����������_func,
		����beg2��ͷ�ķ�Χ�ڵ�ÿ��Ԫ����Ϊ�ڶ�����������_func,
		ÿ�ε��÷��ص�ֵ���洢����result��ͷ�ķ�Χ��
		����ֵ��Ŀ������result���һ����ת��Ԫ�ص���һλ�õ�����,Ҳ��δ�����ǵ�Ԫ�ص�λ�õ�����

ע�⣺
һ�����ȥʹ��transform()�ķ���ֵ��ע�ⲻҪ�ô�

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int func1Transform(int val) {
	return val + 100;
}

int func2Transform(int val1, int val2) {
	return val1 + val2;
}


void testTransform() {
	vector<int> vect1{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> vect2;
	vect2.resize(vect1.size());
	//1.һԪ����  iterator transform(beg, end, result, _func);
	vector<int>::iterator p1 = transform(vect1.begin(), vect1.end(), vect2.begin(), func1Transform);
	for (int i : vect2) {
		cout << i << " ";
	}
	cout << endl;
	cout << *(p1 - 1) << endl;//����ֵ��Ŀ���������һ��λ�õ���һ��λ�õĵ�����
	vector<int> vect3;
	vect3.resize(vect1.size());
	//2.��Ԫ����  iterator transform(beg1, end1, beg2, result, _func)
	vector<int>::iterator p2 = transform(vect1.begin(), vect1.end(), vect2.begin(), vect3.begin(), func2Transform);
	for (int i : vect3) {
		cout << i << " ";
	}
	cout << endl;
	cout << *(p2 - 1) << endl;//����ֵ��Ŀ���������һ��λ�õ���һ��λ�õĵ�����
}

//void main() {
//	testTransform();
//}

