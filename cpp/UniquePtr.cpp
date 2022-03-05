/*��ռ����ָ�� unique_qtr
* #include <memory>

*unique_qtr��ʼ��
	1.ͨ�����캯����ʼ��	(new ����)
	2.ͨ���ƶ������ʼ��	(move(ptr))
	3.make_unique			(����)//����new��make_unique�Դ�new
	4.ͨ��reset��ʼ��		(new ����)

* ��������
	��ȡԭָ�� ptr �� get()

*ɾ����
	unique_ptr ָ��ɾ������ shared_ptr ָ��ɾ������������ģ�unique_ptr ָ��ɾ������ʱ����Ҫȷ��ɾ����������
	�뿪ָ��������� ���� ɾ��ָ��ָ��Ķ��ڴ棬�ͷſռ�
	���ú���ָ���Զ���ɾ���� ���� lambda���ʽ�޲����б�ʱ���صľ���һ������ָ��
	��ʹ��lambda���ʽ�Զ���ɾ����
*/


#include<iostream>
#include<string>
#include<vector>
#include <memory>
#include <array>
using namespace std;

void structUniquePtr() {//unique_ptr���캯��
//1.ͨ�����캯����ʼ��
	unique_ptr<int> ptr1(new int(10));
	//unique_ptrû��use_count()��Ա������unique_ptr���ܿ�������
	//cout << "ptr1������ڴ����ü���:" << ptr1.use_count() << endl;//error
	//unique_ptr<int> ptr2 = ptr1;//error,������һ��unique_ptr��ֵ����һ��unique_ptr
	
//2.ͨ���ƶ������ʼ��
	unique_ptr<int> ptr2(move(ptr1));
	if (ptr1 == nullptr) { cout << "�ƶ������ԭָ��ptr1Ϊnullptr" << endl; }

//3.make_unique
	unique_ptr<int> ptr3 = make_unique<int>(20);
	
//4.ͨ��reset��ʼ��
	ptr3.reset();//int(20)���ͷ�
	ptr3.reset(new int(15));//ptr3ָ��new int(15)
	cout << "*ptr3:" << *ptr3 << endl;

//5.��������
	//ptr �� get()
}

class claUniquePtr {
public:
	int a;
	claUniquePtr(int a) :a(a) {
		cout << "claUniquePtr(" << a << ")���캯��" << endl;
	}
	~claUniquePtr() {
		cout << "claUniquePtr(" << a << ")��������" << endl;
	}
};

void deleteUniquePtr() {
	//unique_ptr ָ��ɾ������ shared_ptr ָ��ɾ������������ģ�unique_ptr ָ��ɾ������ʱ����Ҫȷ��ɾ����������
	using func_ptr = void(*)(claUniquePtr* p);
	unique_ptr<claUniquePtr, func_ptr> ptr1(new claUniquePtr(100), [](claUniquePtr* p)->void {delete p; cout << "ɾ��claUniquePtr(100)" << endl; });
	claUniquePtr* ptr2 = new claUniquePtr(200);
}

void testUniquePtr() {
	structUniquePtr();
	deleteUniquePtr();
	cout << "���Խ���" << endl;
}

//void main() {
//	testUniquePtr();
//}