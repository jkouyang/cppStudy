/*string ��С
*
	int size();
	int length();
	bool empty();
	void resize(n);
	int capacity();
	void reserve();
	int max_size()

* ע�⣺
	length������C���Զ����������ģ�����STL֮��Ϊ�˼����ּ�����size(����STL�ӿ�)����ʵ����һ��
	string���size()/length()�������ص����ֽ����������Ƿ��к��֡�

*/

#include<iostream>
#include<string>
using namespace std;

void testStr_9() {
	string str = "123abc\0abc";
	cout << "str:" << str << endl;
	cout << "str.size():" << str.size() << endl;//size()��length()����һ��
	cout << "str.length():" << str.length() << endl;
	cout << "sizeof(str):" << sizeof(str) << endl;//string��ռ���ֽ�
	cout << "str.capacity():" << str.capacity() << endl;//����STL������capacity()
	bool flag = str.empty();
	str.resize(3);
	cout << "str:" << str << endl;
	str.resize(13,'a');//������Ĭ�����'/0'
	cout << "str:" << str << endl;
}

//void main() {
//	testStr_9();
//}