/*Day06
********ע��
* �ṹ������Ҳ����������һ��ֱ�ӽ���
*/

#include <iostream>
#include <string>
#include<ctime>
using namespace std;

struct man {
	//��Ա�б�
	string name;
	int age;
	double atk;
};


void def(man *m,int len) {
	string str = "ABCDE";
	for (int i = 0; i < 5; i++, m++) {
		int hage_rand = rand() % 20 + 20;
		int hatk_rand = rand() % 301 + 700;
		m->name = "Hero_";
		m->name += str[i];
		m->age = hage_rand;
		m->atk = hatk_rand;
	}
}

void bubblesort(man* m, int len) {//ð������
	man *p1;
	man *p2;
	for (int i = 0; i < len; i++) {
		p1 = m + i;
		for (int j = i+1; j < len; j++) {
			p2 = m + j;
			if (p1->atk < p2->atk) {
				man temp = *p2;
				*p2 = *p1;
				*p1 = temp;
			}
		}
	}
}

void print(man* m, int len) {
	for (int i = 0; i < 5; i++, m++) {
		cout << m->name << "  Age:" << m->age << "  ATK:" << m->atk << endl;
	}
}



//void main() {
//	srand((unsigned int)time(NULL));//����ϵͳʱ�䣬���������
//	man m[5];
//	int len = sizeof(m) / sizeof(m[0]);
//	def(&m[0], len);
//	cout << "����ǰ" << endl;
//	print(&m[0], len);
//	bubblesort(&m[0], len);
//	cout << endl << "�����" << endl;
//	print(&m[0], len);
//}