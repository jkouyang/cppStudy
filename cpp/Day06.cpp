/*Day06
结构体：用户自定义的数据类型，允许用户存储不同的数据类型
	struct 结构体名称 {结构体成员列表}；

结构体与数组：结构体名称 变量名称[]；

结构体与指针：stu *p1 = &s1; stu *p = &s[0];

结构体嵌套结构体：

结构体和函数：值传递和地址传递
			  值传递会把数据复制一份增加数据量，地址传递效率高但可能导致数据的修改(可配合const使用)
*/

#include <iostream>
#include <string>
using namespace std;

struct stu_06 {
	//成员列表
	string name;
	int age;
	double score;
}s3;

struct tea_06{//老师结构体
	string name;
	int age;
	stu_06 s;
};

void Day06()
{
//创建结构体变量的三种方法，多用1和2
	cout << "==============结构体" << endl;
	//1
	//struct stu s1;
	stu_06 s1;//创建结构体变量时struct可以省略
	s1.name = "Job";
	s1.age = 18;
	s1.score = 98.2;
	cout << "name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;

	//2
	struct stu_06 s2 = { "Tim" ,19,85.2};
	cout << "name:" << s2.name << "  age:" << s2.age << "  score:" << s2.score << endl;

	//3 在定义结构体时顺便创建结构体变量
	s3.name = "May";
	s3.age = 17;
	s3.score = 92.1;
	cout << "name:" << s3.name << "  age:" << s3.age << "  score:" << s3.score << endl;

	
//结构体与数组
	stu_06 s[3] = { 
		{ "Job" ,18, 98.2 }, 
		{ "Tim" ,19, 85.2 },
		{ "May" ,17, 92.1 }
	};
	cout << endl << "==============结构体与数组" << endl;
	for (int i = 0; i <= 2; i++) {
		cout << "name:" << s[i].name << "  age:" << s[i].age << "  score:" << s[i].score << endl;
	}

	cout << endl << "==============结构体所占内存空间" << endl;
	cout << "sizeof(s:)" << sizeof(s) << endl;
	cout << "sizeof(s1:)" << sizeof(s1) << endl;
	cout << "sizeof(s[1].name:)" << sizeof(s[1].name) << endl;
	cout << "sizeof(s[1].age:)" << sizeof(s[1].age) << endl;
	cout << "sizeof(s[1].score:)" << sizeof(s[1].score) << endl;

//结构体与指针
	stu_06 *p1 = &s1;
	cout << endl << "==============结构体与指针" << endl;
	cout << "name:" << p1->name << "  age:" << p1->age << "  score:" << p1->score << endl;

	stu_06 *p = &s[0];
	cout << endl << "==============结构体数组与指针" << endl;
	for (int i = 0; i <= 2; i++,p++) {
		cout << "name:" << p->name << "  age:" << p->age << "  score:" << p->score << endl;
	}

//结构体嵌套结构体
	tea_06 t;
	t.name = "Kun";
	t.age = 48;
	t.s.name = "Job";
	t.s.age = 18;
	t.s.score = 98.2;
	cout << endl << "==============结构体嵌套结构体" << endl;
	cout << "Teachername:" << t.name << "  Teacherage:" << t.age << "  Stuname:" << t.s.name << endl;
}

void print1(stu_06 s) {//值传递
	s.score = 78;
	cout << "子函数 name:" << s.name << "  age:" << s.age << "  score:" << s.score << endl;
}

void print2(stu_06 *s) {//地址传递
	s->score = 78;
	cout << "子函数 name:" << s->name << "  age:" << s->age << "  score:" << s->score << endl;
}


//void main(){
//	Day06();
//
//	cout << endl << "==============结构体函数传递" << endl;
//	stu_06 s1;//创建结构体变量时struct可以省略
//	s1.name = "Job";
//	s1.age = 18;
//	s1.score = 98.2;
//	cout << "主函数 name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
//	cout << endl << "值传递后" << endl;
//	print1(s1);//值传递
//	cout << "主函数 name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
//	cout << endl << "地址传递后" << endl;
//	print2(&s1);//地址传递
//	cout << "主函数 name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
//}