/*Day20 �ļ��������
C++�ж��ļ�������Ҫ����ͷ�ļ� <fstream>

�ļ����ͷ�Ϊ���֣�
	1.�ı��ļ�   -  �ļ����ı���ASCII����ʽ�洢�ڼ������
	2.�������ļ� -  �ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������

�����ļ���������:
	1.ofstream��д����
	2.ifstream��������
	3.fstream ����д����

д�ļ��������£�
	1.����ͷ�ļ�	#include <fstream>
	2.����������	ofstream ofs;
	3.���ļ�		ofs.open("�ļ�·��",�򿪷�ʽ);
	4.д����		ofs << "д�������";
	5.�ر��ļ�		ofs.close();

�ļ��Ĵ򿪷�ʽ
	| �򿪷�ʽ    | ����                       |
	| ----------- | -------------------------- |
	| ios::in     | Ϊ���ļ������ļ�         |
	| ios::out    | Ϊд�ļ������ļ�         |
	| ios::ate    | ��ʼλ�ã��ļ�β           |
	| ios::app    | ׷�ӷ�ʽд�ļ�             |
	| ios::trunc  | ����ļ�������ɾ�����ٴ��� |
	| ios::binary | �����Ʒ�ʽ                 |


���ļ��������£�
	1.����ͷ�ļ�						#include <fstream>
	2.����������						ifstream ifs;
	3.���ļ����ж��ļ��Ƿ�򿪳ɹ�	ifs.open("�ļ�·��",�򿪷�ʽ);
	4.������							���ַ�ʽ��ȡ
	5.�ر��ļ�							ifs.close();

*/
#include<iostream>
#include<string>
#include<fstream>


using namespace std;

void test_20_1a(){
	ofstream ofs;
	ofs.open("test.txt", ios::out);

	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	ofs.close();
}

void test_20_1b()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}


	////���ֶ��ļ��Ĳ���
	////��һ�ַ�ʽ
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	////�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//������
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	////������
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;
	//}

	ifs.close();

}

//void main() {
//
//	test_20_1a();
//	system("pause");
//	test_20_1b();
//	system("pause");
//
//}