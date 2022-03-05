/*Day06
********注意
* 结构体数组也可以像数组一样直接交换
*/

#include <iostream>
#include <string>
#include<ctime>
using namespace std;

struct man {
	//成员列表
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

void bubblesort(man* m, int len) {//冒泡排序
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
//	srand((unsigned int)time(NULL));//调用系统时间，生产随机数
//	man m[5];
//	int len = sizeof(m) / sizeof(m[0]);
//	def(&m[0], len);
//	cout << "排序前" << endl;
//	print(&m[0], len);
//	bubblesort(&m[0], len);
//	cout << endl << "排序后" << endl;
//	print(&m[0], len);
//}