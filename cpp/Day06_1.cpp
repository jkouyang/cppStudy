/*Day06
********ע��
* ͬһ����Ŀ��ͬ��cpp�ļ��в�Ҫ������ͬ�Ľṹ�����ƣ��ṹ���������
*/

#include <iostream>
#include <string>
#include<ctime>
using namespace std;

struct stu_06_1 {
	//��Ա�б�
	string name;
	int age;
	double score;
};

struct tea_06_1 {//��ʦ�ṹ��
	string name;
	int age;
	stu_06_1 s[5];
};

void scorein(tea_06_1 *tArr,int tlen, int slen){
	string str = "ABCDE";
	for (int i = 0; i < tlen; i++, tArr++) {
		int tage_rand = rand() % 20 + 40;
		tArr->name = "Teacher_";
		tArr->name += str[i];
		tArr->age = tage_rand;
		for (int j = 0; j < slen; j++) {
			int score_rand = rand() % 61 + 40;
			int sage_rand = rand() % 3 + 17;
			tArr->s[j].name = "Student_";
			tArr->s[j].name += str[j];
			tArr->s[j].age = sage_rand;
			tArr->s[j].score = score_rand;
		}
	}
}

void print(tea_06_1* tArr, int len, int slen){
	for (int i = 0; i < len; i++, tArr++) {
		cout << tArr->name << "  age:" <<tArr->age << endl;
		for (int j = 0; j < slen; j++) {
			cout <<"\tname:" << tArr->s[j].name << "  age:" << tArr->s[j].age << "  score:" << tArr->s[j].score << endl;
		}
	}
}



//void main() {
//	srand((unsigned int)time(NULL));//����ϵͳʱ�䣬���������
//	//rand�����ڲ��������ǰ����Ҫϵͳ�ṩ������α��������е����ӣ�rand����������ӵ�ֵ����һϵ���������
//	//���ϵͳ�ṩ������û�б仯��ÿ�ε���rand�������ɵ�α��������ж���һ���ġ�
//	//srand(unsigned seed)ͨ������seed�ı�ϵͳ�ṩ������ֵ���Ӷ�����ʹ��ÿ�ε���rand�������ɵ�α��������в�ͬ���Ӷ�ʵ�����������ϵġ��������
//	//ͨ����������ϵͳʱ�����ı�ϵͳ������ֵ����srand(time(NULL))������Ϊrand�����ṩ��ͬ������ֵ������������ͬ����������С�
//	tea_06_1 tArr[3];
//	int tlen = sizeof(tArr) / sizeof(tArr[0]);
//	int slen = 5;
//	scorein(&tArr[0],tlen,slen);
//	print(&tArr[0], tlen, slen);
//}