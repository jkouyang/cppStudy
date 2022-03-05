/*�ַ���ƴ��
	1.string& operator+=(const char* str);				//����+=������
	2.string& operator+=(const char c);					//����+=������
	3.string& operator+=(const string& str);				//����+=������
	4.string& append(const char *s);						//���ַ�������s���ӵ���ǰ�ַ�����β
	5.string& append(const char *s, int n);				//���ַ�������s��ǰn���ַ����ӵ���ǰ�ַ�����β
	6.string& append(const char *s, int pos, int n);		//���ַ�������s���±�pos��ʼ����β���ַ����ӵ��ַ�����β
	7.string& append(const string &s);					//ͬoperator+=(const string& str)
	8.string& append(const string &s, int pos);			//�ַ���s�д��±�pos��ʼ����β���ַ����ӵ��ַ�����β
	9.string& append(const string &s, int pos, int n);	//�ַ���s�д��±�pos��ʼ��n���ַ����ӵ��ַ�����β

*/


#include<iostream>
#include<string>
using namespace std;

void testStr_3() {
	string str1 = "�ú�ѧϰ";
	string str2 = "��������";
	str1 +=  "Ŷ";//1.����+=��������׷���ַ�������
	cout << "str1=" << str1 << endl;

	str1 = "�ú�ѧϰ";
	str2 = "��������";
	str1 += 'o';//2.����+=��������׷���ַ�����
	cout << "str1=" << str1 << endl;

	str1 = "�ú�ѧϰ";
	str2 = "��������";
	str1 += str2;//3.����+=��������׷���ַ���
	cout << "str1=" << str1 << endl;

	str1 = "�ú�ѧϰ";
	str2 = "��������";
	string str = str1.append("ŶŶ");//4.ʹ��append()�������ַ��������ӵ����ַ�����β��
	cout << "str=" << str << endl;

	str1 = "�ú�ѧϰ";
	str2 = "12345678";
	str = str1.append("12345678", 3);//5.ʹ��append()�������ַ�������ǰn���ַ��ӵ����ַ�����β��
	cout << "str=" << str << endl;

	str1 = "�ú�ѧϰ";
	str2 = "12345678";
	str = str1.append("12345678", 2, 3);//6.ʹ��append()�������ַ����������±�Ϊn1��ʼ��n2���ַ��ӵ����ַ�����β��
	cout << "str=" << str << endl;

	str1 = "�ú�ѧϰ";
	str2 = "12345678";
	str = str1.append(str2);//7.ʹ��append()������һ���ַ����ӵ���һ���ַ�����β��
	cout << "str=" << str << endl;

	str1 = "�ú�ѧϰ";
	str2 = "12345678";
	str = str1.append(str2,2);//8.ʹ��append()������һ���ַ������±�Ϊn��ĩβ���ַ��ӵ���һ���ַ�����β��
	cout << "str=" << str << endl;

	str1 = "�ú�ѧϰ";
	str2 = "12345678";
	str = str1.append(str2, 2, 4);//9.ʹ��append()������һ���ַ������±�Ϊn1��ʼ��n2���ַ��ӵ����ַ�����β��
	cout << "str=" << str << endl;

}

//void main() {
//	testStr_3();
//}