/*	�����Ƶķ�ʽ���ļ����ж�д����
�򿪷�ʽҪָ��Ϊ	ios::binary

д�ļ���
	�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
	����ԭ�� ��`ostream& write(const char * buffer,int len);`
	�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���
	�ļ���������� ����ͨ��write�������Զ����Ʒ�ʽд����

���ļ���
	�����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
	����ԭ�ͣ�`istream& read(char *buffer,int len);`
	�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䡣len�Ƕ�д���ֽ���
	�ļ����������� ����ͨ��read�������Զ����Ʒ�ʽ������
*/

#include<iostream>
#include <fstream>
#include<string>
#include<vector>

using namespace std;

class Person_20_2{
public:
	char m_Name[64];
	int m_Age;
};

//�������ļ�	д�ļ�
void test_20_2a(){
	//д�ļ�
	//1������ͷ�ļ�
	//2���������������
	ofstream ofs("person.txt", ios::out | ios::binary);
	//3�����ļ�
	//ofs.open("person.txt", ios::out | ios::binary);
	Person_20_2 p = { "����"  , 18 };
	//4��д�ļ�
	ofs.write((const char*)&p, sizeof(p));
	//5���ر��ļ�
	ofs.close();

	//���ļ�
}

//�������ļ�	���ļ�
void test_20_2b() {

	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	Person_20_2 p;
	ifs.read((char*)&p, sizeof(p));
	cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
}


//void main() {
//	test_20_2a();
//	system("pause");
//	test_20_2b();
//	system("pause");
//}