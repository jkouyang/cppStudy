/*Day06
�ṹ�壺�û��Զ�����������ͣ������û��洢��ͬ����������
	struct �ṹ������ {�ṹ���Ա�б�}��

�ṹ�������飺�ṹ������ ��������[]��

�ṹ����ָ�룺stu *p1 = &s1; stu *p = &s[0];

�ṹ��Ƕ�׽ṹ�壺

�ṹ��ͺ�����ֵ���ݺ͵�ַ����
			  ֵ���ݻ�����ݸ���һ����������������ַ����Ч�ʸߵ����ܵ������ݵ��޸�(�����constʹ��)
*/

#include <iostream>
#include <string>
using namespace std;

struct stu_06 {
	//��Ա�б�
	string name;
	int age;
	double score;
}s3;

struct tea_06{//��ʦ�ṹ��
	string name;
	int age;
	stu_06 s;
};

void Day06()
{
//�����ṹ����������ַ���������1��2
	cout << "==============�ṹ��" << endl;
	//1
	//struct stu s1;
	stu_06 s1;//�����ṹ�����ʱstruct����ʡ��
	s1.name = "Job";
	s1.age = 18;
	s1.score = 98.2;
	cout << "name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;

	//2
	struct stu_06 s2 = { "Tim" ,19,85.2};
	cout << "name:" << s2.name << "  age:" << s2.age << "  score:" << s2.score << endl;

	//3 �ڶ���ṹ��ʱ˳�㴴���ṹ�����
	s3.name = "May";
	s3.age = 17;
	s3.score = 92.1;
	cout << "name:" << s3.name << "  age:" << s3.age << "  score:" << s3.score << endl;

	
//�ṹ��������
	stu_06 s[3] = { 
		{ "Job" ,18, 98.2 }, 
		{ "Tim" ,19, 85.2 },
		{ "May" ,17, 92.1 }
	};
	cout << endl << "==============�ṹ��������" << endl;
	for (int i = 0; i <= 2; i++) {
		cout << "name:" << s[i].name << "  age:" << s[i].age << "  score:" << s[i].score << endl;
	}

	cout << endl << "==============�ṹ����ռ�ڴ�ռ�" << endl;
	cout << "sizeof(s:)" << sizeof(s) << endl;
	cout << "sizeof(s1:)" << sizeof(s1) << endl;
	cout << "sizeof(s[1].name:)" << sizeof(s[1].name) << endl;
	cout << "sizeof(s[1].age:)" << sizeof(s[1].age) << endl;
	cout << "sizeof(s[1].score:)" << sizeof(s[1].score) << endl;

//�ṹ����ָ��
	stu_06 *p1 = &s1;
	cout << endl << "==============�ṹ����ָ��" << endl;
	cout << "name:" << p1->name << "  age:" << p1->age << "  score:" << p1->score << endl;

	stu_06 *p = &s[0];
	cout << endl << "==============�ṹ��������ָ��" << endl;
	for (int i = 0; i <= 2; i++,p++) {
		cout << "name:" << p->name << "  age:" << p->age << "  score:" << p->score << endl;
	}

//�ṹ��Ƕ�׽ṹ��
	tea_06 t;
	t.name = "Kun";
	t.age = 48;
	t.s.name = "Job";
	t.s.age = 18;
	t.s.score = 98.2;
	cout << endl << "==============�ṹ��Ƕ�׽ṹ��" << endl;
	cout << "Teachername:" << t.name << "  Teacherage:" << t.age << "  Stuname:" << t.s.name << endl;
}

void print1(stu_06 s) {//ֵ����
	s.score = 78;
	cout << "�Ӻ��� name:" << s.name << "  age:" << s.age << "  score:" << s.score << endl;
}

void print2(stu_06 *s) {//��ַ����
	s->score = 78;
	cout << "�Ӻ��� name:" << s->name << "  age:" << s->age << "  score:" << s->score << endl;
}


//void main(){
//	Day06();
//
//	cout << endl << "==============�ṹ�庯������" << endl;
//	stu_06 s1;//�����ṹ�����ʱstruct����ʡ��
//	s1.name = "Job";
//	s1.age = 18;
//	s1.score = 98.2;
//	cout << "������ name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
//	cout << endl << "ֵ���ݺ�" << endl;
//	print1(s1);//ֵ����
//	cout << "������ name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
//	cout << endl << "��ַ���ݺ�" << endl;
//	print2(&s1);//��ַ����
//	cout << "������ name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
//}