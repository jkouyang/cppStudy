/*Set���Һ�ͳ��

��set�������в��������Լ�ͳ������

����ԭ�ͣ�
	1.find(key);//����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
	2.count(key);//ͳ��key��Ԫ�ظ���

ע�⣺
	����--- find    �����ص��ǵ�������
	ͳ��--- count  ������set�����Ϊ0����1��

*/


#include<iostream>
#include<set>
using namespace std;

void testSet_4() {
	set<int> s1;
	//����
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//1.find(key);//����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end()){
		cout << "�ҵ���Ԫ�� �� " << *pos << endl;
	}
	else{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//2.count(key);//ͳ��key��Ԫ�ظ���
	int num = s1.count(30);
	cout << "num = " << num << endl;

}

//void main() {
//	testSet_4();
//}