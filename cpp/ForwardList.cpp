/*forward_list	��������

	forward_list ʹ�õ����������ʵ�֣��ṩ�� O(1) ���Ӷȵ�Ԫ�ز��룬
	��֧�ֿ����������(��Ҳ��������ص�)��
	��׼��������Ψһһ�����ṩsize()����������
	������Ҫ˫�����ʱ�����б� list ���ߵĿռ�������
*/

#include<iostream>
#include<string>
#include<vector>
#include<forward_list>
using namespace std;

void testForwardList() {
	forward_list<int> flist{ 1,2,3,4,5,6 };
	forward_list<int> flist1{ 7,8,9,10 };

	flist.push_front(10);
	flist.pop_front();
	//flist.insert_after(++flist.begin(), 99);
	cout << flist.front() << endl;
	for (auto i : flist) {
		cout << i << " ";
	}
	cout << endl;
	flist.splice_after(flist.begin(),flist1);
	for (auto i : flist) {
		cout << i << " ";
	}
}

//void main() {
//	testForwardList();
//}