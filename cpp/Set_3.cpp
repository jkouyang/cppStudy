/*Set�����Ĳ����ɾ��

����ԭ�ͣ�
	1.insert(elem);//�������в���Ԫ��
	2.erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
	3.erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�����
	4.erase(elem);//ɾ��������ֵΪelem��Ԫ��
	5.clear();//�������Ԫ��

ע�⣺set��֧��������ʣ���֧��[]��at()��"+"
*/

#include<iostream>
#include<set>
using namespace std;

void myPrintSet_3(const set<int>& s) {
	for (set<int>::const_iterator pBegin = s.begin(); pBegin != s.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}


void testSet_3() {
	set<int> s1;
	//1.insert(elem);//�������в���Ԫ��
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	myPrintSet_3(s1);

	//2.erase(pos);//ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
	s1.erase(s1.begin());
	myPrintSet_3(s1);

	//3.erase(beg, end);//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�����
	s1.erase(s1.begin(), ++s1.begin());//��֧���������

	//4.erase(elem);//ɾ��������ֵΪelem��Ԫ��
	s1.erase(30);
	myPrintSet_3(s1);

	//5.clear();//�������Ԫ��
	s1.clear();
		//s1.erase(s1.begin(), s1.end());//���ַ�ʽҲ�������
	myPrintSet_3(s1);
}

//void main() {
//	testSet_3();
//}