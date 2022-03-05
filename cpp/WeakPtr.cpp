/*����������ָ�� weak_ptr	ֻ�Ǽ����Դ������������Դ
* #include <memory>
	����ָ��weak_ptr�ɿ���shared_ptr������
	weak_ptrû�����ز����� * �� ->����Ϊ��������ָ�룬���ܲ�����Դ��
	���Ĺ��첻���������ü���������Ҳ����������ü�����
	������Ҫ���þ�����Ϊһ���Թ��߼��� shared_ptr �й������Դ�Ƿ����

* ��ʼ��
	Ĭ�Ϲ��캯��
	��������
	ͨ��shared_ptr������

* weak_ptr�ڵķ���
	use_count();
	reset();
	expired();���жϹ۲����Դ�Ƿ��Ѿ����ͷţ��ͷŷ���true
	lock();����weak_ptr�������Դ�� shared_ptr ����

* weak_ptrӦ��
	�������this��shared_ptr(�����Ƕ������ݵ�ԭʼ��ַ�ظ���ʼ������ָ��)
	���ѭ�����õ�����
*/

#include<iostream>
#include<string>
#include<vector>
#include <memory>
#include <array>
using namespace std;

void structWeakPtr() {
	shared_ptr<int> sptr1(new int(10));

//Ĭ�Ϲ��캯��
	weak_ptr<int> wptr1;

//��������
	weak_ptr<int> wptr2(wptr1);

//ͨ��shared_ptr������
	weak_ptr<int> wptr3(sptr1);
	weak_ptr<int> wptr4 = sptr1;

//use_count();
	cout << "wptr1.use_count(): " << wptr1.use_count() << endl;
	cout << "wptr2.use_count(): " << wptr2.use_count() << endl;
	cout << "wptr3.use_count(): " << wptr3.use_count() << endl;
	cout << "wprt4.use_count(): " << wptr4.use_count() << endl;
	cout << "=====================" << endl;

//reset();
	wptr3.reset();

//expired();���жϹ۲����Դ�Ƿ��Ѿ����ͷţ�δ��ʼ��������ָ��Ϊ�ն���Ϊ�Ѿ��ͷ�
	cout << "wptr1.expired(): " << wptr1.expired() << endl;
	cout << "wptr2.expired(): " << wptr2.expired() << endl;
	cout << "wptr3.expired(): " << wptr3.expired() << endl;
	cout << "wprt4.expired(): " << wptr4.expired() << endl;
	cout << "=====================" << endl;

//lock();����weak_ptr�������Դ�� shared_ptr ����
	shared_ptr<int>	sptr2 = wptr4.lock();
	cout << "wptr1.use_count(): " << wptr1.use_count() << endl;
	cout << "wptr2.use_count(): " << wptr2.use_count() << endl;
	cout << "wptr3.use_count(): " << wptr3.use_count() << endl;
	cout << "wprt4.use_count(): " << wptr4.use_count() << endl;
	cout << "=====================" << endl;
}


//=====================�������this��shared_ptr(�����Ƕ������ݵ�ԭʼ��ַ�ظ���ʼ������ָ��)
//class getThisWeakPtr{
class getThisWeakPtr:public enable_shared_from_this<getThisWeakPtr> {//����ģ����
//�������this��shared_ptr(�����Ƕ������ݵ�ԭʼ��ַ�ظ���ʼ������ָ��)
public:
	shared_ptr<getThisWeakPtr> getThis() {
		//return shared_ptr<proWeakPtr>(this);
		return shared_from_this();//����ģ����ĺ���
	}
	~getThisWeakPtr() {
		cout << "getThisWeakPtr��������" << endl;
	}
};

void thisWeakPtr() {//weak_ptr�������this��shared_ptr
	shared_ptr<getThisWeakPtr> sptr1(new getThisWeakPtr());
	shared_ptr<getThisWeakPtr> sptr2(sptr1->getThis());
	cout << "sptr1.use_count():" << sptr1.use_count() << endl;
	cout << "sptr2.use_count():" << sptr2.use_count() << endl;
}


//=====================���ѭ�����õ�����
class AWeakPtr;//������
class BWeakPtr;//������
class AWeakPtr {
public:
	//shared_ptr<BWeakPtr> Asptr;
	weak_ptr<BWeakPtr> Asptr;
	~AWeakPtr() { cout << "AWeakPtr������" << endl; }
};

class BWeakPtr {
public:
	shared_ptr<AWeakPtr> Bsptr;
	~BWeakPtr() { cout << "BWeakPtr������" << endl; }
};

void loopWeakPtr() {//weak_ptr���ѭ�����õ�����
	cout << "=====================" << endl;
	shared_ptr<AWeakPtr> sptr1(new AWeakPtr());
	shared_ptr<BWeakPtr> sptr2(new BWeakPtr());
	cout << "sptr1.use_count():" << sptr1.use_count() << endl;
	cout << "sptr2.use_count():" << sptr2.use_count() << endl;

	sptr1->Asptr = sptr2;
	sptr2->Bsptr = sptr1;
	cout << "sptr1.use_count():" << sptr1.use_count() << endl;
	cout << "sptr2.use_count():" << sptr2.use_count() << endl;

}


//void main() {
//	structWeakPtr();
//	thisWeakPtr();//weak_ptr�������this��shared_ptr(�����Ƕ������ݵ�ԭʼ��ַ�ظ���ʼ������ָ��)
//	loopWeakPtr();//weak_ptr���ѭ�����õ�����
//}