/*for_each()
* 
	������ʽ��
		template <class _Fn>
		_Fn for_each(beg, end, _Fn _func);

	����beg-end��������һ�ε����ݽ���_func()����������ֵ�������뺯��_func����ֵ��ͬ

ע�⣺
1._func����Ǻ���ʱ��������ʹ��for_each�ķ���ֵ�����׻���
2._func�����Ƿº������᷵��һ��������󣬿���������¼�������������һ�α������ж������

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void myPrintForEach(int val) {
	cout << val << " ";
}

class myObejctForEach {
public:
	myObejctForEach():count(0),sum(0){}
	void operator()(int val) {	
		this->count++;
		sum += val;
	}
	int count;//��¼���ô���
	int sum;//��¼�������ݵĺ�
};

void testForEach() {
	//1._func����Ǻ���������ʱ�������ڵ����ݽ���ĳһ�ֲ���
	//_func����Ǻ���ʱ��������ʹ��for_each�ķ���ֵ�����׻���
	vector<int> vect{ 1,2,3,4,5,6,7,8,9,10 };
	for_each(vect.begin(), vect.end(), myPrintForEach);
	cout << endl;

	//2._func�����Ƿº������᷵��һ���������
	//�����ڷº�������������һЩ��Ա��������¼���������һ�α������Խ��ж������
	myObejctForEach aa=for_each(vect.begin(), vect.end(), myObejctForEach());
	cout << "���ô�����" << aa.count << endl;
	cout << "sum��" << aa.sum << endl;
}

//void main() {
//	testForEach();
//}