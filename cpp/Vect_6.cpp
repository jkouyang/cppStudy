/*vector������������ʵ������������Ԫ�ؽ��л���,�����Ǹı�ָ��
	swap(vec);// ��vec�뱾���Ԫ�ػ���
*/

#include<iostream>
#include<vector>
using namespace std;
void myPrintVect_6(vector<int>& v) {
	for (vector<int>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		cout << *pBegin << " ";
	}
	cout << endl;
}


void testVect_6a() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	
	vector<int> v2;
	for (int i = 20; i > 0; i--) {
		v2.push_back(i);
	}
	//v1.resize(3);
	//v2.resize(5);
	//swap(vec);// ������������Ԫ�ػ���
	cout << "����ǰ��" << endl;
	cout << "v1��������" << v1.capacity() << endl;
	cout << "v1�Ĵ�С��" << v1.size() << endl;
	cout << "v2��������" << v2.capacity() << endl;
	cout << "v2�Ĵ�С��" << v2.size() << endl;
	myPrintVect_6(v1);
	myPrintVect_6(v2);

	cout << "������" << endl;
	v1.swap(v2);
	cout << "v1��������" << v1.capacity() << endl;
	cout << "v1�Ĵ�С��" << v1.size() << endl;
	cout << "v2��������" << v2.capacity() << endl;
	cout << "v2�Ĵ�С��" << v2.size() << endl;
	myPrintVect_6(v1);
	myPrintVect_6(v2);
	//���Կ���swap()����ʵ�ʾ���ı�����������ָ��

}

//����swap()���������ڴ�ռ�
void testVect_6b() {
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i + 1);
	}
	cout << "v��������" << v.capacity() << endl;
	cout << "v�Ĵ�С��" << v.size() << endl;

	v.resize(3);//��������Զ���������洢�����ݳ��ȣ�����ڴ��˷�
	cout << "δ�����ڴ�ռ�ǰ��" << endl;
	cout << "v��������" << v.capacity() << endl;
	cout << "v�Ĵ�С��" << v.size() << endl;

	//����swap()�����ڴ�ռ�
	vector<int>(v).swap(v);
	//vector<int>(v)�����ÿ������캯������һ����������x������洢����v��Ԫ�أ�x��v����ָ��
	//��һ��������֮��xָ��Ĵ�����������ϵͳ����(��������ǰ��������֮��ͱ�����)
	cout << "swap()�����ڴ�ռ��" << endl;
	cout << "v��������" << v.capacity() << endl;
	cout << "v�Ĵ�С��" << v.size() << endl;
}

//void main() {
//	testVect_6a();
//	cout << endl << "=========����swap()���������ڴ�ռ�==========" << endl << endl;
//	testVect_6b();
//}