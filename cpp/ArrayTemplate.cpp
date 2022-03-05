//ģ��

#include"MyArray.hpp"
//�������������͵����ݽ��д洢
void print1_ArrayTemplate(myArray<int> &arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "�����е�" << i << "��Ԫ��Ϊ��" << arr[i] << endl;
	}
}

void test1_ArrayTemplate() {
	myArray<int> arr(5);
	for (int i = 0; i < 5; i++) {
		arr.Push_back(i);
	}
	print1_ArrayTemplate(arr);
	cout << "arr������" << arr.getCapacity() << endl;
	cout << "arr��С��" << arr.getSize() << endl;
	arr.Pop_back(); arr.Pop_back();
	print1_ArrayTemplate(arr);
	cout << "arr������" << arr.getCapacity() << endl;
	cout << "arr��С��" << arr.getSize() << endl;
}

//���Զ����������͵����ݽ��д洢
class Person_ArrayTemplate {
public:
	string name;
	int age;
	Person_ArrayTemplate() {}
	Person_ArrayTemplate(string name,int age) {
		this->name = name;
		this->age = age;
	}
};

void print2_ArrayTemplate(myArray<Person_ArrayTemplate>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "������" << arr[i].name << "\t���䣺" << arr[i].age << endl;
	}
}

void test2_ArrayTemplate() {
	Person_ArrayTemplate p1("��ɮ",25);
	Person_ArrayTemplate p2("�����", 999);
	Person_ArrayTemplate p3("��˽�", 798);
	Person_ArrayTemplate p4("ɳɮ", 658);
	Person_ArrayTemplate p5("������", 452);

	myArray<Person_ArrayTemplate> arr(10);//�ڴ���myArray����ʱ�ṹ��Person_ArrayTemplate���࣬����Ҫ�ṩ��Ŀչ��캯��
	arr.Push_back(p1);
	arr.Push_back(p2);
	arr.Push_back(p3);
	arr.Push_back(p4);
	arr.Push_back(p5);
	
	print2_ArrayTemplate(arr);
	cout << "arr������" << arr.getCapacity() << endl;
	cout << "arr��С��" << arr.getSize() << endl;
	arr.Pop_back(); arr.Pop_back();

	print2_ArrayTemplate(arr);
	cout << "arr������" << arr.getCapacity() << endl;
	cout << "arr��С��" << arr.getSize() << endl;
}

//void main() {
//	cout << "===============�������������͵����ݽ��д洢=================" << endl;
//	test1_ArrayTemplate();
//	cout << endl << "===============���Զ����������͵����ݽ��д洢===============" << endl;
//	test2_ArrayTemplate();
//}