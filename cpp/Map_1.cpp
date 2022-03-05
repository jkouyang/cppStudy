/*Map����(�õĶ�)����python�ֵ�
map������Ԫ�ض���pair��
	pair�е�һ��Ԫ��Ϊkey����ֵ�������������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
	����Ԫ�ض������Ԫ�صļ�ֵ�Զ�����

���ʣ�
	map/multimap����**����ʽ����**���ײ�ṹ���ö�����ʵ��

�ŵ㣺
	���Ը���keyֵ�����ҵ�valueֵ

map��multimap����
	map���������������ظ�keyֵԪ��
	multimap�������������ظ�keyֵԪ��

���캯����
	1.map<T1, T2> mp;//mapĬ�Ϲ��캯��:
	2.map(const map &mp);//�������캯��

��ֵ��
	map& operator=(const map &mp);//���صȺŲ�����

�ܽ᣺map������Ԫ�ض��ǳɶԳ��֣���������ʱ��Ҫʹ�ö���
	  map�ڲ���Ԫ��ʱ��Ĭ�ϰ���ֵ����
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

void myPrintMap_1(map<int,string>& m) {
	for (map<int, string>::iterator pBegin = m.begin(); pBegin != m.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
}

void testMap_1() {
	//1.map<T1, T2> mp;//mapĬ�Ϲ��캯��:
	map<int, string> m1;
	m1.insert(pair<int, string>(105, "��ɮ"));
	m1.insert(pair<int, string>(102, "�����"));
	m1.insert(pair<int, string>(101, "��˽�"));
	m1.insert(pair<int, string>(104, "ɳɮ"));
	m1.insert(pair<int, string>(103, "������"));
	myPrintMap_1(m1);
	cout<< "=========================" << endl;

	//2.map(const map &mp);//�������캯��
	map<int, string> m2(m1);
	myPrintMap_1(m2);
	cout << "=========================" << endl;

	//��ֵ��map& operator=(const map & mp);//���صȺŲ�����
	map<int, string> m3;
	m3 = m2;
	myPrintMap_1(m3);

}

//void main() {
//	testMap_1();
//}