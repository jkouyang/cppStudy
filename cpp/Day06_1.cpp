/*Day06
********注意
* 同一个项目不同的cpp文件中不要定义相同的结构体名称，结构体和类相似
*/

#include <iostream>
#include <string>
#include<ctime>
using namespace std;

struct stu_06_1 {
	//成员列表
	string name;
	int age;
	double score;
};

struct tea_06_1 {//老师结构体
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
//	srand((unsigned int)time(NULL));//调用系统时间，生产随机数
//	//rand函数在产生随机数前，需要系统提供的生成伪随机数序列的种子，rand根据这个种子的值产生一系列随机数。
//	//如果系统提供的种子没有变化，每次调用rand函数生成的伪随机数序列都是一样的。
//	//srand(unsigned seed)通过参数seed改变系统提供的种子值，从而可以使得每次调用rand函数生成的伪随机数序列不同，从而实现真正意义上的“随机”。
//	//通常可以利用系统时间来改变系统的种子值，即srand(time(NULL))，可以为rand函数提供不同的种子值，进而产生不同的随机数序列。
//	tea_06_1 tArr[3];
//	int tlen = sizeof(tArr) / sizeof(tArr[0]);
//	int slen = 5;
//	scorein(&tArr[0],tlen,slen);
//	print(&tArr[0], tlen, slen);
//}