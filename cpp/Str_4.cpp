/*�ַ����Ĳ��Һ��滻
* ���ң�����ָ���ַ����Ƿ����
* �滻����ָ����λ���滻�ַ���

==============================================================================================
* int find(const string& str, int pos = 0) const;		//����str��һ�γ���λ��,��pos��ʼ����
* int find(const char* s, int pos = 0) const; 			//����s��һ�γ���λ��,��pos��ʼ����
* int find(const char* s, int pos, int n) const;		//��posλ�ò���s��ǰn���ַ���һ��λ��
* int find(const char c, int pos = 0) const;			//�����ַ�c��һ�γ���λ��
* int rfind(const string& str, int pos = npos) const;	//����str���һ��λ��,��pos��ʼ����
* int rfind(const char* s, int pos = npos) const;		//����s���һ�γ���λ��,��pos��ʼ����
* int rfind(const char* s, int pos, int n) const;		//��pos����s��ǰn���ַ����һ��λ��
* int rfind(const char c, int pos = 0) const;			//�����ַ�c���һ�γ���λ��
* string& replace(int pos, int n, const string& str);	//�滻��pos��ʼn���ַ�Ϊ�ַ���str
* string& replace(int pos, int n,const char* s);		//�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

*/


#include<iostream>
#include<string>
using namespace std;

void testStr_4a() {
	string str1 = "abcdefgde";
	//1.����find()�����������Ҳ��ҵ�һ�����ֵĵط�
	int pos1 = str1.find("de");//����find()�������ң��ҵ������±꣬û�ҵ�����-1
	int pos2 = str1.find("df");//����find()�������ң��ҵ������±꣬û�ҵ�����-1
	cout << "de���±�" << pos1 << endl;
	cout << "df���±�" << pos2 << endl;


	//2.����rfind()��������������ҵ�һ�����ֵĵط�
	int pos3 = str1.rfind("de");
	int pos4 = str1.rfind("df");
	cout << "de���±�" << pos3 << endl;
	cout << "df���±�" << pos4 << endl;
}

void testStr_4b() {
	string str2 = "abcdefg";
	//����replace()�������ַ�����pos�±꿪ʼn���ַ��滻Ϊ�´�
	str2 = str2.replace(1, 3, "12345");
	cout << "str2=" << str2 << endl;
}

//void main() {
//	testStr_4a();
//	testStr_4b();
//}