/*Map��������

- map����Ĭ���������Ϊ ����keyֵ���� ��С��������������θı��������
- ���÷º��������Ըı��������
- �����Զ����������ͣ�map����Ҫָ���������,ͬset����

*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

class myCompareMap_5 {
public:
	bool operator()(int v1,int v2) const{//map�����ǰ���ֵ�������ԱȽϵ��Ǽ�ֵ����������
		return v1 > v2;
	}
};

void testMap_5() {
	map<int, string> m1;//Ĭ�����򣬰���ֵ������ֻ�ô��º����������ü�()
	m1[3] = "Tom";
	m1[1] = "Yang";
	m1[2] = "Mary";
	m1[5] = "Job";
	m1[4] = "Ken";
	for (map<int, string>::iterator pBegin = m1.begin(); pBegin != m1.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
	cout << "=========================" << endl;

	map<int, string, myCompareMap_5> m2;//�Զ��壬�������У�ֻ�ô��º����������ü�()
	m2[3] = "Tom";
	m2[1] = "Yang";
	m2[2] = "Mary";
	m2[5] = "Job";
	m2[4] = "Ken";
	for (map<int, string, myCompareMap_5>::iterator pBegin = m2.begin(); pBegin != m2.end(); pBegin++) {
		cout << "key:" << pBegin->first << "\t" << pBegin->second << endl;
	}
}

//void main() {
//	testMap_5();
//}