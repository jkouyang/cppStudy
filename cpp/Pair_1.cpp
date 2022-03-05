/*Pair���ݳɶԵĳ���
���캯����
	1.pair<type, type> p (value1, value2);
	2.pair<type, type> p = make_pair(value1, value2);

Ƕ��ʹ�ã�
	1.pair<type, pair<type,type>> p(value1, {value2, value3});

*/

#include<iostream>
#include<string>
using namespace std;

void testPair_1() {
	//1.pair<type, type> p(value1, value2);
	pair<string, int> p1("��ɮ", 25);
	cout << "������" << p1.first << "\t���䣺" << p1.second << endl;

	//2.pair<type, type> p = make_pair(value1, value2);
	pair<string, int> p2 = make_pair("�����", 999);
	cout << "������" << p2.first << "\t���䣺" << p2.second << endl;

	//Ƕ��ʹ��
	//1.pair<type, pair<type,type>> p(value1, {value2, value3});
	pair<string, pair<int, int>>p3("��˽�", { 765, 765 });
	cout << "������" << p3.first << "\t���䣺" << p3.second.first << "\t���䣺" << p3.second.second << endl;

}

//void main() {
//	testPair_1();
//}