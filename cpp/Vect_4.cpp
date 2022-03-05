/*vector�����ɾ��
	1.push_back(ele); //β������Ԫ��ele
	2.pop_back(); //ɾ�����һ��Ԫ��
	3.insert(const_iterator pos, ele);//������ָ��λ��pos����Ԫ��ele
	4.insert(const_iterator pos, int count,ele);//������ָ��λ��pos����count��Ԫ��ele
	5.insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
	6.erase(const_iterator pos);//ɾ��������ָ���Ԫ��
	7.erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
	8.clear();//ɾ������������Ԫ��

*/


#include<iostream>
#include<vector>
using namespace std;

void myPrintVect_4(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}

void testVect_4() {
	vector<int> v1;
	//1.push_back(ele); //β�巨
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	myPrintVect_4(v1);


	//2.pop_back();//βɾ��
	v1.pop_back();
	myPrintVect_4(v1);

	//3.insert(const_iterator pos, ele);//������ָ��λ��pos����Ԫ��ele
	v1.insert(v1.begin() +3, 101);//��һ�������ǵ��������±�Ϊ3�ĵط�����
	myPrintVect_4(v1);

	//4.insert(const_iterator pos, int count, ele);//������ָ��λ��pos����count��Ԫ��ele
	v1.insert(v1.begin() + 3, 5, 100);//��һ�������ǵ��������±�Ϊ3�ĵط�����5��100
	myPrintVect_4(v1);

	//5.insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
	vector<int> v2;
	v2.insert(v2.begin(), v1.begin() + 1, v1.begin() + 3);
	myPrintVect_4(v2);

	//6.erase(const_iterator pos);//ɾ��������ָ���Ԫ��
	v1.erase(v1.begin()+3);//�����ǵ�������ɾ���±�Ϊ3��Ԫ��
	myPrintVect_4(v1);

	//7.erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
	v1.erase(v1.begin() + 1, v1.begin() + 3);//�����ǵ�������ɾ���±�Ϊ1��3֮��(�±�1��2)��Ԫ��
	myPrintVect_4(v1);


	//8.clear();//ɾ������������Ԫ��
	v1.clear();
	myPrintVect_4(v1);
	cout << "v1��������" << v1.capacity() << endl;
	cout << "v1�ĳ��ȣ�" << v1.size() << endl;

}

//void main() {
//	testVect_4();
//}