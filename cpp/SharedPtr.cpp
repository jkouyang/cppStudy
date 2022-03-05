/*��������ָ��	shared_ptr
* #include <memory>
 
* ����ָ�룺
	�洢ָ��̬���䣨�ѣ�����ָ����࣬���������ڵĿ���
	�ܹ�ȷ�����뿪ָ������������ʱ���Զ������ٶ�̬����Ķ��󣬷�ֹ�ڴ�й¶
	����ָ��ĺ���ʵ�ּ��������ü�����ÿʹ����һ�Σ��ڲ����ü�����1��ÿ����һ���ڲ������ü�����1
	��Ϊ0ʱ��ɾ����ָ��Ķ��ڴ�

* ��������ָ��shared_ptr��
	ָ�������ָ�����ͬʱ����ͬһ����Ч���ڴ棬��������ָ�� shared_ptr ��һ��ģ���࣬
	���Ҫ���г�ʼ�������ַ�ʽ��ͨ�����캯����std::make_shared ���������Լ� reset ������
	��������ָ������ʼ�����֮���ָ��Ҫ������ǿ���ڴ棬
	�����Ҫ�鿴��ǰ�ж��ٸ�����ָ��ͬʱ����������ڴ����ʹ�ù�������ָ���ṩ��һ����Ա���� use_count

* shared_ptr��ʼ����
	Ĭ�Ϲ��캯��	(new ����)
	��������		(ptr)
	�ƶ�����		(move(ptr))
	make_shared		(����)//����new��make_shared�Դ�new
	reset			(new ����)
		ע�⣺�������ͬһ�����������ݣ���Ҫ�����ݵ�ԭʼ��ַȥ�ظ���ʼ������ָ�룬
			  ����һ������ָ��ȥ��ʼ����һ������ָ��
			int* p = new int(0);
			shared_ptr<int> sptr1(p);
			shared_ptr<int> sptr2(p);
			shared_ptr<int> sptr3(p);
		����Ĵ���������ʱ�󱨴�sptr123�ļ�������1�����ظ�����

* shared_ptr��������
	ֱ����������ָ��������ݵĶ�д
	���ù�������ָ�����ṩ��get()�����õ�ԭʼ��ַT* get() const noexcept;������ԭʼ��ַ����

* ɾ����(����ָ����ͷ��ڴ�)
	�뿪ָ���������(ָ�����Ϊ0) ���� ɾ��ָ��ָ��Ķ��ڴ棬�ͷſռ�
	���ú���ָ���Զ���ɾ���� ���� lambda���ʽ�޲����б�ʱ���صľ���һ������ָ��
	��ʹ��lambda���ʽ�Զ���ɾ����
*/

#include<iostream>
#include<string>
#include<vector>
#include <memory>
#include <array>
using namespace std;

class claSharedPtr {
public:
	int a;
	claSharedPtr(int a) :a(a) {
		cout << "claSharedPtr("<< a << ")���캯��" << endl;
	}
	~claSharedPtr() {
		cout << "claSharedPtr(" << a << ")��������" << endl;
	}
};

//��������ָ��shared_ptr����������
void structSharedPtr() {
//1.Ĭ�Ϲ��캯��
	cout << "1.����Ĭ�Ϲ��캯��===========" << endl;
	//shared_ptr<int> ptr1 = new int(10);//�����Ⱥ����߲���ȣ��������ָ�룬�ұ���ָͨ��
	shared_ptr<int> ptr1(new int(10));
	//�����array��vector�������飬���ڰ汾��֧�ֶ�̬���飬��Ҫ�Լ����¶�����������
	//�Զ�������������[](int* p) {delete[] p; }	��	default_delete<int[]>()		��Ҫ��delete��delete[]������
	shared_ptr<int[]> ptrArry(new int[10](), [](int* p) {delete[] p; });
	cout << "ptr1������ڴ����ü���:" << ptr1.use_count() << endl;
	//����ָ��û�б���ʼ�����߱���ʼ��Ϊ nullptr ��ָ�룬���ü������� + 1

//2.��������
	cout << endl << "2.���ÿ�������===============" << endl;
	shared_ptr<int> ptr2 = ptr1;
	//shared_ptr<int> ptr2(ptr1);//���ֿ��������д��������
	cout << "ptr1������ڴ����ü���:" << ptr1.use_count() << endl;
	cout << "ptr2������ڴ����ü���:" << ptr2.use_count() << endl;

//3.�ƶ�����
	cout << endl << "3.�����ƶ�����===============" << endl;
	shared_ptr<int> ptr3 = move(ptr1);
	cout << "ptr1������ڴ����ü���:" << ptr1.use_count() << endl;
	cout << "ptr2������ڴ����ü���:" << ptr2.use_count() << endl;
	cout << "ptr3������ڴ����ü���:" << ptr3.use_count() << endl;

//4.ͨ��make_shared��ʼ��
	cout << endl << "4.ͨ��make_shared��ʼ��======" << endl;
	shared_ptr<array<int, 10>> ptr4 = make_shared<array<int, 10>>(array<int, 10>{0});//����������������
	
	shared_ptr<claSharedPtr> ptr5 = make_shared<claSharedPtr>(claSharedPtr(10));
	//�����࣬��������д����ʵ������ʱ����һ����������������ָ��ָ����������(���Ƽ�����д��)
	//�ɼ�д(��������д��)�����������������
	cout << "ptr4������ڴ����ü���:" << ptr4.use_count() << endl;
	cout << "ptr4������ڴ����ü���:" << ptr4.use_count() << endl;
	shared_ptr<claSharedPtr> ptr6 = make_shared<claSharedPtr>(20);
	cout << "ptr4������ڴ����ü���:" << ptr4.use_count() << endl;
	cout << "ptr5������ڴ����ü���:" << ptr5.use_count() << endl;
	cout << "ptr6������ڴ����ü���:" << ptr6.use_count() << endl;

//5.ʹ��reset�ͷź����³�ʼ��
	cout << endl << "5.ʹ��reset�ͷ�==============" << endl;
	ptr2.reset();
	cout << "ptr1������ڴ����ü���:" << ptr1.use_count() << endl;
	cout << "ptr2������ڴ����ü���:" << ptr2.use_count() << endl;
	cout << "ptr3������ڴ����ü���:" << ptr3.use_count() << endl;

	cout << endl << "5.ʹ��reset��ʼ��============" << endl;
	ptr1.reset(new int[10](), [](int* p) {delete[] p;});//������ʹ�����飬Ҫ���¶���������������C++17ǰ��֧��
	cout << "ptr1������ڴ����ü���:" << ptr1.use_count() << endl;
	cout << "ptr2������ڴ����ü���:" << ptr2.use_count() << endl;
	cout << "ptr3������ڴ����ü���:" << ptr3.use_count() << endl;

//6.shared_ptr��������
	cout << endl << "6.shared_ptr��������=========" << endl;
	//�������������͵Ĳ�������������ָͨ��һ����ʹ������ָ���������
		//Ŀǰptr3ָ��int��ptr4ָ��array<int,10>
		cout << *ptr3 << endl;
		(*ptr4)[3] = 10;
		ptr4->at(4) = 5;//ֱ��ͨ������ָ�����
		array<int, 10>* aa = ptr4.get();//ͨ������ָ���get()��ȡ���ݶ�Ӧ�ĵ�ַ
		aa->at(5) = 2;
		for (auto&& it : *ptr4) { cout << it << " "; }; cout << endl;
	//�Զ���Ĳ���
		//Ŀǰptr5��ptr6ָ��claSharedPtr���͵Ķ���
		cout << "ptr5->a:" << ptr5->a << "\tptr6->a:" << ptr6->a << endl;//ֱ��ͨ������ָ�����
		claSharedPtr* bb = ptr5.get();
		bb->a = 5; //ͨ������ָ���get()��ȡ���ݶ�Ӧ�ĵ�ַ
		cout << "ptr5->a:" << ptr5->a << "\tptr6->a:" << ptr6->a << endl;//ͨ��get()��������
}

//����ָ��shared_ptr�ͷ��ڴ��ʱ��
void delteSharedPtr() {
	shared_ptr<claSharedPtr> ptr1(new claSharedPtr(100), [](claSharedPtr* p) {delete p; cout << "ɾ��claSharedPtr(100)" << endl; });
	claSharedPtr* ptr2 = new claSharedPtr(200);//δɾ�����ڴ�й¶
}

void testSharedPtr() {
	structSharedPtr();
	cout << endl << "7.����ָ��shared_ptr�ͷ��ڴ��ʱ��" << endl;
	delteSharedPtr();
	cout << "���Խ���" << endl;
}

//void main() {
//	testSharedPtr();
//}
