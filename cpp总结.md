# 基础

### 数据类型

- **注释**://	/**/

- **变量**: 字母数字下划线

- **常量**：define,const

- **关键字** 

- **标识符**：标识符（identifier）是指用来标识某个实体的一个符号，在不同的应用环境下有不同的含义。
          在计算机编程语言中，标识符是用户编程时使用的名字，用于给变量、常量、函数、语句块等命名，
          以建立起名称与使用之间的关系。标识符通常由字母和数字以及其它字符构成。

- **数据类型**（意义：给变量分配合适的内存空间）

  > - 整型：**short** 2B (-32768`32767)	 **int** 4B	**long** 4B	 **long long** 8B
  > - 浮点型：**float** 4B (7为有效数字)  	**double** 8B （15-16位有效数字）
  > - 字符型：**char** 1B （内存中存储的是ASCII编码），单引号‘’创建，(int)char,输出ASCII码，A:65,a:97
  >   			转义字符：\n 换行，\t 水平制表符(作用：输出水平对齐)，\\ 反斜杠
  > - 字符串型：char 变量名[]="字符串值"；(C语言风格)
  >    			**string** 变量名= "字符串值"；(C++风格)，要导入头文件：#include<string>
  > - 布尔类型：**bool** 1B，true(本质是1)，false(本质是0)
  > - sizeof：**sizeof**(数据类型/变量)，统计数据类型所占内存大小

```c++
#include <iostream>//预处理指令，告诉编译器在程序中要包含C++标准输入输出流头文件
#include <string>//字符串头文件
using namespace std;//标准命名空间，将一些实体（变量，函数，对象，类）放入其中，以解决同名冲突问题

#define Month 12 //define定义宏常量，不可修改

void typeData(){//主函数
    const int Day = 7; //const修饰的变量也为常量，不可修改
    cout << "一年有" << Month << "个月，一周有" << Day << "天" << endl;
    //cout为标准输出流，<<为流插入运算符，endl为流操纵算子，它发送一个换行符并刷新输出缓冲区

    //整型
    int a = 0;
    cout << "请输入整型a：" << endl;
    cin >> a;
    cout << "整型a=" << a << endl;

    //浮点型
    float f = 3.14f;//定义单精度数时后面加个f，防止编译器认为它是一个双精度数后再强制转换成单精度
    cout << "请输入浮点型f：" << endl;
    cin >> f;
    cout << "浮点型f=" << f << endl;

    //字符型
    char ch = 97;//ch='a';
    cout << "ch的初始值：" <<ch<< endl;
    cout << "请输入字符型ch：" << endl;
    cin >> ch;
    cout << "浮点型ch=" << ch << endl;

    //字符串型
    char str0[] = "Hello";
    string str = "hello";
    cout << "str的初始值：" << str << endl;
    cout << "请输入字符串型str：" << endl;
    cin >> str;
    cout << "字符串型str=" << str << endl;
    cout << "字符串型str所占内存空间(B)：" << sizeof(str) << endl;


    //布尔型
    bool flag = false;
    cout << "bool类型初始值 flag："  << flag << endl;
    cout << "请输入bool类型 flag：" << endl;
    cin >> flag;//任意非零的数都视为1，true
    cout << "bool类型 flag=" << flag << endl;

    system("pause");
}

int main(){
    typeData();
    return 0;
}
```

### 运算符类型

- **算术运算符**：+，-，*，/(两个数中只要有一个是浮点数，结果就算浮点数)
                  %取模(取余)	(只有整型可以进行取模，浮点数不能进行取模运算)
                  ++(自加)，	--(自减)
- **赋值运算符**：=，+=，-=，*=，/=，%=
- **比较运算符**：==，！=，<，>，<=，>=  (关系运算符)
- **逻辑运算符**：！，&&，||   （真为1，假为0）
- **位运算符**：

```c++
void typeOperator(){
    int a = 10;
    int b = 3;
    double c = 10;
    double d = 3;

    cout << a / b << endl;
    cout << a / d << endl;
    cout << c / b << endl;
    cout << c / d << endl;

    cout << a % b << endl;

}

int main(){
    //调用另一个cpp文件的函数有两种方法
    /*方法1
    首先创建一个xxx.h头文件，声明函数aaa(int x,int y)
    然后再创建一个与头文件同名的源文件xxx.cpp，在该文件中实现函数max(int x,int y)的功能
    最后在需要调用的cpp文件中导入头文件 #inclued"xxx.h"

    */
    /*方法2
    调用前声明一下typeData()函数
    因为在同一个project里面的源文件之间的函数一般情况下是可以互相调用的，前提是要声明以及不限制它的作用域！
    */
    //void typeData();
    //typeData();

    typeOperator();
	return 0;
}
```

### 程序流程结构

**顺序结构**

**选择结构**
            if，else if，else

- **三目运算：表达式1?表达式2:表达式3**     如果表达式1为真，执行表达式2并返结果，如果表达式1为假，执行表达式3并返回结果
- **switch**：注意不加break时switch语句会从第一个正确的case往下依次执行。
  switch执行时判断的只能是整型或者字符型，不能是一个区间
  switch的执行效率比if高
  switch(表达式){
  	case 结果1：执行语句;break;
  	case 结果2：执行语句;break;
  	case 结果3：执行语句;break;
  	default:执行语句;break;
  }

**循环结构**

- **while**(循环条件){
  	循环语句}  //循环条件为真时就一直执行
- **do**{
  	循环语句
  	}**while**(循环条件)；//先执行循环语句，再判断循环条件，注意while后要加分号；
- **for**(起始表达式；循环条件；末尾循环体){循环语句}
- 跳转语句：**break**; 跳出循环结构或switch选择结构
          			**continue**;在循环语句中跳出本次循环中余下尚未执行的语句，继续执行下一次循环
                    			**goto**;如果标记的名称存在，执行到goto语句时，会跳转到标记的位置

### 数组

- 放在一块连续的内存空间中
- 数组中每个元素都是相同的数据类型
- 初始话时要定义数组长度，未赋值的数组元素为0
- 通过sizeof(数组名)可以统计数组占的内存，通过数组名查看数组的首地址
- 数组名是数组的首地址

```c++
int main(){
	int arr1[5] = { 1,2,3,4,5 };
	cout << "一维数组空间" << sizeof(arr1) << endl;
	cout << "一维数组首地址" << arr1 << endl;
	cout << "一维数组首个元素地址" << &arr1[0] << endl;
	cout << "一维数组第2个元素地址" << &arr1[1] << endl;

	int arr2[5][4];//二维数组按行先存
	cout << "二维数组行数" << sizeof(arr2)/sizeof(arr2[0]) << endl;
	cout << "二维数组列数" << sizeof(arr2[0])/sizeof(arr2[0][0]) << endl;

	cout << "二维数组空间" << sizeof(arr2) << endl;
	cout << "二维数组首地址" << arr2 << endl;
	cout << "二维数组第一行首地址" << &arr2[0] << endl;
	cout << "二维数组第二行首地址" << &arr2[1] << endl;
	
	return 0;
}
```

###  函数

- 返回类型  函数名称（参数列表）{
  	执行语句；
  	return 表达式；
  }

- **函数声明**：viod funcname();  函数声明后，可以把函数定义写在main函数后面，**函数声明可以写多次，函数定义只能写一次**
- **函数的分文件编写**：创建同名的xxx.h和xxx.cpp，在xxx.h中写函数声明，在xxx.cpp中写函数定义

### 指针

> 定义 数据类型 *p；
>
> 声明  p=地址，p为地址，*p为地址对应的值
>
> 定义并声明 数据内心 *p=地址；

- **空指针**：指针变量指向内存中编号为0的空间，用于初始化指针变量，空指针指向的内存是不可以访问的
  		int *p = NULL;
- **野指针**：指针变量指向非法的内存空间，程序中避免用野指针
- **常量指针**：const int *p = &a; //指针的指向可以改，但不能通过该指针来修改指向内存的值
- **指针常量**：int * const p = &a; //指针的指向不能改，但指针指向的内存的值可以改
- **常量指针常量**：const int * const p = &a; //指针的指向和指针指向内存的值都不改

------

- 注意：指针的p++,不是地址的地址(p值)单纯的+1，是加一个指针指向数据类型的长度，即下移一位元素

- 指针与数组：可以用指针表示数组中的元素

- 指针与函数：**地址传递**
  			void funcname(int *p1, int *p2){}
    			funcname(&a,&b)

```c++
#include <iostream>
#include <string>
using namespace std;

void main()(){
	int num = 10;//数
	double arr1[5] = { 1,2,3,4,5 };//一维
	int arr2[5][4] = { { 1,2,3,4 }, {6,7,8,9} };//二维
	
	int *p= &num;
	double *p1 = arr1;
	int *p2 = arr2[0];
	cout << arr2 << endl;
	cout << &arr2[0] << endl;

	cout << "p:" << p << endl ;
	cout << "*p:" << *p << endl;
	cout << "&num:" << &num << endl;
	cout << "num:" << num << endl << endl;
	

	cout << "p1:" << p1 << endl;
	cout << "++p1:" << ++p1 << endl;
	cout << "*p1:" << *p1 << endl;
	cout << "arr1:" << arr1 << endl;
	cout << "arr1[0]:" << arr1[0] << endl << endl;

	cout << "p2:" << p2 << endl;
	cout << "*p2:" << *p2 << endl;
	cout << "arr2:" << arr2 << endl;
	cout << "arr2[0]:" << arr2[0] << endl;
	cout << "arr2[0][0]:" << arr2[0][0]<< endl << endl;


	//32位下(x86)指针都是占4B，64位(x64)指针都是占8B
	cout << "int*所占空间:" << sizeof(int*) << endl;
	cout << "double*所占空间:" << sizeof(double*) << endl;
	cout << "char*所占空间:" << sizeof(char*) << endl;
	cout << "string*所占空间:" << sizeof(string*) << endl;
}
```

### 结构体

- 结构体：**用户自定义的数据类型**，允许用户存储不同的数据类型
  	struct 结构体名称 {结构体成员列表}；
- 结构体与数组：结构体名称 变量名称[]；

- 结构体与指针：stu *p1 = &s1; stu *p = &s[0];

- 结构体嵌套结构体：

- 结构体和函数：值传递和地址传递
  			  值传递会把数据复制一份增加数据量，地址传递效率高但可能导致数据的修改(可配合const使用)

```c++
//同一个项目不同的cpp文件中不要定义相同的结构体名称，结构体和类相似
#include <iostream>
#include <string>
using namespace std;

struct stu {
	//成员列表
	string name;
	int age;
	double score;
}s3;

struct tea{//老师结构体
	string name;
	int age;
	stu  s;
};

void Test(){
//创建结构体变量的三种方法，多用1和2
	cout << "==============结构体" << endl;
	//1
	//struct stu s1;
	stu  s1;//创建结构体变量时struct可以省略
	s1.name = "Job";
	s1.age = 18;
	s1.score = 98.2;
	cout << "name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;

	//2
	struct stu  s2 = { "Tim" ,19,85.2};
	cout << "name:" << s2.name << "  age:" << s2.age << "  score:" << s2.score << endl;

	//3 在定义结构体时顺便创建结构体变量
	s3.name = "May";
	s3.age = 17;
	s3.score = 92.1;
	cout << "name:" << s3.name << "  age:" << s3.age << "  score:" << s3.score << endl;

	
//结构体与数组
	stu  s[3] = { 
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
	stu  *p1 = &s1;
	cout << endl << "==============结构体与指针" << endl;
	cout << "name:" << p1->name << "  age:" << p1->age << "  score:" << p1->score << endl;

	stu  *p = &s[0];
	cout << endl << "==============结构体数组与指针" << endl;
	for (int i = 0; i <= 2; i++,p++) {
		cout << "name:" << p->name << "  age:" << p->age << "  score:" << p->score << endl;
	}

//结构体嵌套结构体
	tea t;
	t.name = "Kun";
	t.age = 48;
	t.s.name = "Job";
	t.s.age = 18;
	t.s.score = 98.2;
	cout << endl << "==============结构体嵌套结构体" << endl;
	cout << "Teachername:" << t.name << "  Teacherage:" << t.age << "  Stuname:" << t.s.name << endl;
}

void print1(stu s) {//值传递
	s.score = 78;
	cout << "子函数 name:" << s.name << "  age:" << s.age << "  score:" << s.score << endl;
}

void print2(stu *s) {//地址传递
	s->score = 78;
	cout << "子函数 name:" << s->name << "  age:" << s->age << "  score:" << s->score << endl;
}


void main(){
	Test();

	cout << endl << "==============结构体函数传递" << endl;
	stu  s1;//创建结构体变量时struct可以省略
	s1.name = "Job";
	s1.age = 18;
	s1.score = 98.2;
	cout << "主函数 name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
	cout << endl << "值传递后" << endl;
	print1(s1);//值传递
	cout << "主函数 name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
	cout << endl << "地址传递后" << endl;
	print2(&s1);//地址传递
	cout << "主函数 name:" << s1.name << "  age:" << s1.age << "  score:" << s1.score << endl;
}
```

**结构体数组也可以像数组一样直接交换**

```c++
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

void main() {
	srand((unsigned int)time(NULL));//调用系统时间，生产随机数
	man m[5];
	int len = sizeof(m) / sizeof(m[0]);
	def(&m[0], len);
	cout << "排序前" << endl;
	print(&m[0], len);
	bubblesort(&m[0], len);
	cout << endl << "排序后" << endl;
	print(&m[0], len);
}
```

### 内存分区模型

C++程序在执行时，将内存大方向划分为4个区域

> **代码区**：存放函数体的二进制代码，由操作系统进行管理的
> **全局区**：存放全局变量和静态变量以及常量(const修饰的常量，包含字符串常量)，该区域的数据在程序结束后由操作系统释放（生命周期长）
> **栈	区**：由编译器自动分配释放, 存放函数的参数值,局部变量等
> **堆	区**：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收

分区的意义：不同区域存放的数据，赋予不同的生命周期, 给我们更大的灵活编程

程序运行前：代码区，全局区		程序运行后：栈区，堆区

```c++
#include <iostream>
#include <string>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

void main() {
	//创建局部变量,函数内部定义的变量(存放栈区)
	int a = 10;
	int b = 10;

	cout << "局部变量a地址为： \t" << (int)&a << endl;
	cout << "局部变量b地址为： \t" << (int)&b << endl;

	//局部常量(存放栈区)
	const int c_l_a = 10;
	const int c_l_b = 10;
	
	cout << "局部常量c_l_a地址为： \t" << (int)&c_l_a << endl;
	cout << "局部常量c_l_b地址为： \t" << (int)&c_l_b << endl;

	//全局变量(存放全局区)
	cout << "全局变量g_a地址为： \t" << (int)&g_a << endl;
	cout << "全局变量g_b地址为： \t" << (int)&g_b << endl;

	//静态变量(存放全局区)
	static int s_a = 10;
	static int s_b = 10;
	
	cout << "静态变量s_a地址为： \t" << (int)&s_a << endl;
	cout << "静态变量s_b地址为： \t" << (int)&s_b << endl;

	//字符串常量(存放全局区)
	cout << "字符串常量地址为： \t" << (int)&"hello world" << endl;
	cout << "字符串常量地址为： \t" << (int)&"你好世界" << endl;

	//全局常量(存放全局区)
	cout << "全局常量c_g_a地址为： \t" << (int)&c_g_a << endl;
	cout << "全局常量c_g_b地址为： \t" << (int)&c_g_b << endl;
}
```

栈区：
	栈区由编译器自动分配释放, 存放函数的参数值,局部变量等
	注意事项：**不要返回局部变量的地址，栈区开辟的数据由编译器自动释放**

堆区：
	**new可用在堆区开辟数据**

利用new操作符在堆区开辟数据
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete

```c++
#include <iostream>
#include <string>

using namespace std;

int* func1(){
	int a = 10;
	return &a;//栈区开辟的数据由编译器自动释放,局部变量的地址不要返回
}

int* func2()
{
	// new可用在堆区开辟数据
	int *a = new int(10);//new返回的是该数据类型的指针
	//指针a是局部变量放在栈区，指针a指向的数据int(10)放在了堆区
	return a;
}

void test1_new() {
	int* p = func2();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete
	delete p;
	//cout << *p << endl;//内存已被释放，再次访问就算非法操作，会报错
}
void test2_new() {
	//创建10整型数组，存放堆区
	int *arr = new int[10];
	for (int i = 0; i < 10; i++) {//赋值
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {//赋值
		cout << arr[i] << endl;
	}
	//释放数组的时候要加[]
	delete[] arr;
}

void main() {
	int* p1 = func1();

	//*p并不是a的值，func()函数完成后，p指向的空间被释放
	cout << "栈区开辟的数据由编译器自动释放,局部变量的地址不要返回" << endl;
	cout << *p1 << endl;
	cout << *p1 << endl;
	cout << *p1 << endl;
	cout << *p1 << endl;

	cout << endl << "堆区开辟的数据，由程序员手动开辟，手动释放" << endl;
	int *p2 = func2();//指针a存放的地址传给了p2，现在指针p2指向的数据int(10)放在了堆区
	cout << *p2 << endl;
	cout << *p2 << endl;
	cout << *p2 << endl;
	cout << *p2 << endl;

	cout << endl << "测试new和delete" << endl;
	test1_new();
	cout << endl << "测试new创建数组" << endl;
	test2_new();

	system("pause");
}
```

### 引用

​	引用：**给变量起一个别名**
​	语法：数据类型 &别名=原名；

1. 引用一定要初始化
   	int &c;//错误，要让b初始化引用指向a
2. **引用初始化后，不能更改**
   	int &c=a;
   	int &c=b;//错误，不能更改引用的指向
3. 不要返回局部变量的引用，值会改变
4. 函数的返回值为引用的时候，函数调用可以作为左值（等式左边）
5. **引用本质：指针常量**；指向不可以修改，指向的值可以修改
   	int &ref = a;//自动转换 int* const ref = & a;//指针常量
   	ref = 20;//内部发现ref是引用，自动转化为*ref = 20;
6. 常量引用 const int& ref =10;

**C++推荐使用引用，因为语法方便，引用本质是指针常量，但是所有的指针操作编译器都帮我们做了**

```c++
#include <iostream>
#include <string>

using namespace std;

//创建引用
int g_a = 10;
int g_b = 10;
int& c = g_a;
//int& c = g_b;///错误，不能更改引用的指向

void swap(int &a, int &b) {//引用传递，形参会修饰实参
	int temp = b;
	b = a;
	a = temp;
}

int& test01() {//不要返回局部变量的引用
	int l_a = 10;
	return l_a;
}

int& test02() {//不要返回局部变量的引用
	static int static_b = 10;
	return static_b;
}

void showValue(const int& ref) {//使用常量引用，让变量只能被访问，不能修改
	//ref += 10;//只能被访问，不能修改
	cout << "打印g_a="<< ref << endl;
}

void main() {

	cout << "原始a,b的值" << endl;
	cout << "g_a=" << g_a << endl;
	cout << "g_b=" << g_b << endl;
	c = 20;
	cout << endl << "修改引用c后（c引用a），g_a,g_b的值" << endl;
	cout << "g_a=" << g_a << endl;
	cout << "g_b=" << g_b << endl;

	swap(g_a, g_b);//引用传递，形参会修饰实参
	cout << endl << "引用传递后（swap(int &a, int &b)），g_a,g_b的值" << endl;
	cout << "g_a=" << g_a << endl;
	cout << "g_b=" << g_b << endl;

	cout << endl << "不要返回局部变量的引用，值会改变，因为数据存放在栈区" << endl;
	int &return_l_a = test01();
	cout << "l_a=" << return_l_a << endl;
	cout << "l_a=" << return_l_a << endl;
	cout << "l_a=" << return_l_a << endl;

	int& return_l_b = test02();
	cout << endl << "全局变量的引用，值会不会变，因为数据存放在全局区" << endl;
	cout << "static_b=" << return_l_b << endl;
	cout << "static_b=" << return_l_b << endl;
	cout << "static_b=" << return_l_b << endl;

	test02() = 123;//函数的返回值为引用的时候，函数调用可以作为左值（等式左边），修改static_b=1123；
	cout << endl << "函数调用作为左值（等式左边），修改static_b" << endl;
	cout << "static_b=" << return_l_b << endl;

	//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
	const int& ref = 10;

	//ref = 100;  //加入const后不可以修改变量
	cout << endl << "常量引用ref="<< ref << endl;

	showValue(g_a);
}
```

### 常量指针、指针常量

* 语法：
	常量指针：const int* p = &a;
	指针常量：int* const p = &a;
	常量指针常量：const int* const p = &a;

总结：
	常量指针：本质指针，指向的对象是常量，不能通过指针来修改指向对象，但是其本身是一个变量，因此可以被重新赋值
	指针常量：本质常量，常量的值是一个指针，指向不能变，指向的内容可变
	常量指针常量：常量指针+指针常量

```c++
#include<iostream>
using namespace std;
void main() {
	int a = 100;
	int b = 200;

	const int* p1 = &a;
	int* const p2 = &a;
	const int* const p3 = &a;

	//1.常量指针
	//*p = 200;//错误，不能通过指针来修改指向对象
	p1 = &b;//但是其本身是一个变量，因此可以被重新赋值
	cout << *p1 << endl;

	//2.指针常量
	//p2 = &b; //错误，指向不能变，指向的内容可变
	*p2 = 150;
	cout << *p2 << endl;
	cout << a << endl;

	//3.常量指针常量：常量指针 + 指针常量
	//*p3 = 200;//错误，指向的内容不能变
	//p3 = &b;//错误，指向不能变
}
```

### 指针函数、函数指针

- **指针函数：返回值为指针的函数**
- **函数指针：指向函数的指针**

总结：
	函数名本身就是一个地址，就是一个函数指针
	函数指针可以作为参数进行传递

```c++
#include<iostream>
using namespace std;

int* ptr_a(int& val) {//返回指针，指针函数
	val = val + 1;
	return &val;
}

int& ptr_b(int& val) {//返回引用，指针函数
	val = val + 1;
	return val;
}

int ptr_c(int& val) {//普通函数
	val = val + 1;
	return val;
}

void test() {
	int value = 1;
	//返回指针，指针函数
	int* p1 = ptr_a(value);
	cout << "value:" << value << "\t\t*p1:" << *p1 << endl;

	//返回引用，指针函数
	int& p2 = ptr_b(value);
	p2++;
	cout << "value:" << value << "\t\tp2:" << p2 << endl;

	//普通函数，来定义成函数指针
	// 直接定义
	int (*func_ptr)(int&);//定义一个指针，指向函数(返回值为int，参数为int&)
	func_ptr = ptr_c;//赋值
	func_ptr(value);
	cout << "value:" << value << endl;

	//typedef
	typedef int(*func_ptr2)(int&);//用typedef给函数指针(返回值为int，参数为int&)别名func_ptr2
	func_ptr2 ptr1 = ptr_c;//定义一个函数指针，并赋值
	ptr1(value);//利用函数指针调用函数
	cout << "value:" << value << endl;

	//using，推荐使用
	using func_ptr3 = int(*)(int&);//用using给函数指针(返回值为int，参数为int&)别名func_ptr3
	func_ptr3 ptr2 = ptr_c;//定义一个函数指针，并赋值
	ptr2(value);//利用函数指针调用函数
	cout << "value:" << value << endl;

}

void main() {
	test();
}
```

### 函数高级

1. **函数默认参数**  返回值类型 函数名(参数= 默认值){}
   		//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
      		//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数(函数声明和实现只能有一个有默认参数)
      			int func(int a=10; int b=10);//函数声明
      			int func(int a=10; int b=10){return a+b;}//函数实现
      			//上述例子错误，函数声明和实现只能有一个有默认参数
      			int func(int a; int b);//函数声明
      			int func(int a=10; int b=10){return a+b;}//函数实现
      		//3. 有传入的参数就用传入的参数，没有就要用默认值
2. **函数占位参数**  返回值类型 函数名 (数据类型){}  void func(int a, int) {}
   		//1. C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
      		//2. 函数占位参数 ，占位参数也可以有默认参数  void func(int a, int = 10) {}
      		//3. 在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术
3. **函数重载**  函数名可以相同，提高复用性
   		//1. 满足条件：同一个作用域下；函数名称相同；函数参数类型不同或者个数不同或者顺序不同；
      		//2. 函数返回值不可以作为函数重载条件
      		//3. 注意：	* 引用作为重载条件    函数重载碰到函数默认参数

```c++
#include <iostream>
#include <string>

using namespace std;

//函数默认参数
int sum_3(int a, int b = 10, int c = 10) {//求三数之和
	return a + b + c;
}

//函数占位参数
void placeholder(int a, int) {
	cout << "This is placeholder func." << endl;
}

//引用作为重载条件
void ref_overloading(int& a)
{
	cout << "ref_overloading (int &a) 调用 " << endl;
}
void ref_overloading(const int& a)
{
	cout << "ref_overloading (const int &a) 调用 " << endl;
}

//默认参数碰到函数重载
void def_overloading(int a,int b = 10) {
	cout << "def_overloading (int a; int b = 10) 调用 " << endl;
}
void def_overloading(int a) {
	cout << "def_overloading (int a) 调用 " << endl;
}

void main() {
	//调用有默认参数的函数时，默认的参数位置可以传值也可不传
	cout << "默认参数" << endl;
	cout << "sum_3 = " << sum_3(20, 20) << endl;
	cout << "sum_3 = " << sum_3(100) << endl;
	
	//调用有占位参数(非默认)的函数时，占位参数必须填补，占位参数为默认参数时可填补可不填补
	cout << endl << "占位参数" << endl;
	placeholder(10, 10); //占位参数必须填补

	//引用作为重载条件,根据传入的类型调用，指针常量(调用无const)，常量指针常量(调用const)
	int a = 10;
	const int b = 10;
	cout << endl << "引用作为重载条件" << endl;
	ref_overloading(a); //a为变量，调用无const
	ref_overloading(b); //b为常量，调用const
	ref_overloading(10);//int &a = 10 不合法，const int &a = 10 合法；所以调用有const

	//默认参数碰到函数重载
	cout << endl << "默认参数碰到函数重载" << endl;
	//def_overloading(10);//报错，不知道调用哪个
	def_overloading(10, 10);
}
```

# 类和对象

### 类的创建、赋值、权限

> C++面向对象的三大特性为：==**封装、继承、多态**==
> 语法：class 类名{ 访问权限： 属性 / 行为  };
>
> **访问权限**
> 			公共权限 public		成员 类内可以访问，类外可以访问
> 			保护权限 protected	成员 类内可以访问，类外不可访问		子类可以访问父类中的保护内容
> 			私有权限 private	成员 类内可以访问，类外不可访问		子类不以访问父类中的私有内容
>
> **stuct和class的比较**
> 			在C++中 struct和class唯一的区别就在于默认的访问权限不同
>
> ​				struct 默认权限为公共
> ​				class  默认权限为私有
>
> 封装：成员属性设置为私有
> 			优点：将所有成员属性设置为私有，可以自己控制读写权限
> 						对于写权限，我们可以检测数据的有效性
>
> 注意：同一个项目下结构体之间，类之间，结构体和类之间的命名都要不同

```c++
#include<iostream>
#include<string>
using namespace std;

class stu {
public:
	//属性  成员属性  成员变量
	string sName;
	int sId;

	//行为  成员函数  成员方法
	void set_sName(string name) {
		sName = name;
	}
	void set_sId(int id) {
		sId = id;
	}
	void showprint() {
		cout << "name:" << sName << "\tid:" << sId << endl;
	}
};

class tea {
	//属性
public:
	string tName;
protected:
	int tId;
private:
	int tWage;

	//方法
public:
	void set_tea(string name, int id, int wage) {
		this->tName = name;
		this->tId = id;
		this->tWage = wage;
	}
	void showprint() {
		cout << "name:" << tName << "\tid:" << tId << "\t\twage:" << tWage << endl;
	}
};

struct test1 {
	int struct_test = 10;//struct 默认权限为公共
};

class test2 {
	int class_test = 10;//class  默认权限为私有
};

void main() {
	stu tony;
	//public类可以这样赋值
	//tony.sName = "tony";
	//tony.sId = 123;

	tony.set_sName("tony");
	tony.set_sId(123);
	tony.showprint();

	tea mary;
	mary.set_tea("mary",101,1000);
	mary.showprint();
	

	test1 a;
	a.struct_test = 0;//可访问
	test2 b;
	//b.struct_test = 0;//不可访问
}
```

### 类和对象:初始化和清理

> **构造函数**：类名(){数据类型 参数}
> 	1. 构造函数，没有返回值也不写void
> 	2. 函数名称与类名相同
> 	3. 构造函数可以有参数，因此可以发生重载
> 	4. 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次
>
> **析构函数**：~类名(){}
> 	1. 析构函数，没有返回值也不写void
> 	2. 函数名称与类名相同,在名称前加上符号  ~
> 	3. 析构函数不可以有参数，因此不可以发生重载
> 	4. 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次

**如果不提供构造函数和析构函数，编译器会提供空实现的构造函数和析构函数**。

```c++
class Person {
public://构造函数和析构函数默认是私有的，所以要加public
	Person(){//程序在调用对象时候会自动调用构造
		cout << "我是Person的构造函数" << endl;
	}

	~Person() {//程序在对象销毁前会自动调用析构
		cout << "我是Person的析构函数" << endl;
	}
};

void test(){
	Person p;
}

void main(){
	test();
	system("pause");
	Person person;
	system("pause");
}
```

**构造函数的分类及调用**

> 两种分类方式：
> 	按参数分为： 有参构造和无参构造
> 	按类型分为： 普通构造和拷贝构造
>
> 三种调用方式：
> 	括号法
> 	显示法
> 	隐式转换法

注意1：**调用无参构造函数不能加括号**，如果加了编译器认为这是一个函数声明（返回类型  函数名()，Person p()——错误;）
注意2：不能利用拷贝构造函数初始化匿名对象编译器认为是对象声明

```c++
#include<iostream>
using namespace std;

class Person {
public:
	int age;
	int score;

	//普通构造
	Person() {//无参构造
		cout << "无参构造函数!" << endl;
		this->age = 0;
		this->score = 0;		
	}

	Person(int age, int score) {//有参构造
		cout << "有参构造函数!" << endl;
		this->age = age;
		this->score = score;		
	}

	//拷贝构造
	Person(const Person  &p) {
		cout << "拷贝构造函数!" << endl;
		this->age = p.age;
		this->score = p.score;
	}

	void Show() {
		cout << "age:" << age << "\tscore:" << score << endl;
	}

	//~Person() {
	//	cout << "析构函数!" << endl;
	//}
};

//调用有参的构造函数
void test() {

	//括号法，常用
	cout << "*****括号法，常用*****" << endl;
	Person p11; 
	p11.Show();
	Person p12(20,80);
	p12.Show();
	Person p13(p12);
	p13.Show();
	//注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明——返回类型  函数名()，Person p()——错误;

	//显式法
	cout << endl << "*****显式法*****" << endl;
	Person p21 = Person();
	p21.Show();
	Person p22 = Person(20,80);
	p22.Show();
	Person p23 = Person(p22);
	p23.Show();
	//Person(10)单独写就是匿名对象  当前行结束之后，马上析构

	//隐式转换法
	cout << endl << "*****隐式转换法*****" << endl;
	Person p31 = {  };//元素为空或者有多个元素时要用{ }，只有一个元素时可以不用{ }直接写元素
	p31.Show();
	Person p32 = { 10, 80 };
	p32.Show();
	Person p33 = p32; 
	p33.Show();

	//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
	//Person p5(p4);
}

void main() {
	test();	
}
```

### 拷贝构造函数的调用时机

> 1.使用一个已经创建完毕的对象来初始化一个新对象
> 2.值传递的方式给函数参数传值
> 3.以值方式返回局部对象

```c++
#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "无参构造函数!" << endl;
		this->age = 0;
	}
	Person(int age) {
		cout << "有参构造函数!" << endl;
		this->age = age;
	}
	Person(const Person& p) {
		cout << "拷贝构造函数!" << endl;
		this->age = p.age;
	}
	//析构函数在释放内存之前调用
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int age;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test_a() {
	cout << "*****1.使用一个已经创建完毕的对象来初始化一个新对象" << endl;
	Person man(100); //p对象已经创建完毕
	Person newman(man); //调用拷贝构造函数
	Person newman2 = man; //拷贝构造

	//Person newman3;
	//newman3 = man; //不是调用拷贝构造函数，赋值操作
}

//2. 值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person p1) {}
void test_b() {
	cout << endl << "*****2.值传递的方式给函数参数传值" << endl;
	Person p; //无参构造函数
	doWork(p);
}

//3. 以值方式返回局部对象
Person doWork2(){
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test_c(){
	cout << endl << "*****3.以值方式返回局部对象" << endl;
	Person p = doWork2();
	cout << (int*)&p << endl;
}

void main() {
	test_a();
	test_b;
	test_c();
}
```

### 构造函数调用规则

> 创建一个类时，默认情况下，c++编译器至少给一个类添加3个函数
> 	1．默认构造函数(无参，函数体为空)
> 	2．默认析构函数(无参，函数体为空)
> 	3．默认拷贝构造函数，对属性进行值拷贝
>
> 构造函数调用规则如下：
> 	如果**用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造**
> 	如果**用户定义拷贝构造函数，c++不会再提供其他构造函数(无参构造，有参构造，构造函数)**

```c++
#include<iostream>
using namespace std;

class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数
	Person(int a) {
		age = a;
		cout << "有参构造函数!" << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
		age = p.age;
		cout << "拷贝构造函数!" << endl;
	}
	//析构函数
	~Person() {
		cout << "析构函数!" << endl;
	}
public:
	int age;
};

void test_a()
{
	Person p1(18);
	//如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
	Person p2(p1);

	cout << "p2的年龄为： " << p2.age << endl;
}

void test_b()
{
	//如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
	Person p1; //此时如果用户自己没有提供默认构造，会出错
	Person p2(10); //用户提供的有参
	Person p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供

	//如果用户提供拷贝构造，编译器不会提供其他构造函数
	Person p4; //此时如果用户自己没有提供默认构造，会出错
	Person p5(10); //此时如果用户自己没有提供有参，会出错
	Person p6(p5); //用户自己提供拷贝构造
}

void main() {
	test_a();
	test_b();
}
```

### 深拷贝与浅拷贝

> **浅拷贝**：简单的赋值拷贝操作
> 			**不管对象的属性是什么数据类型，都是直接拷贝一份，如果是指针的话，其实只拷贝了地址，并没有复制数据**
> 			对于指针，直接复制指针，没有复制数据(两个对象中的height指针存放的地址相同，指向同一个内存空间)
> **深拷贝**：在堆区重新申请空间，进行拷贝操作
> 			对于指针，先在堆区域复制一个原对象指针指向的数据，再将新对象的指针指向该数据(两个对象中的height指针存放的地址不同，但两个地址的数据相同)

**对象中成员含指针时，建议用深拷贝**

```c++
#include<iostream>
using namespace std;

class Person {
public:
	int age;
	int *height;

	Person() {
		cout << "无参构造" << endl;
	}

	Person(int age, int height) {
		cout << "有参构造" << endl;
		this->age = age;
		this->height = new int(height);//new是在堆区重新开辟一个空间，并返回的是该数据类型的指针
	}

	Person(const Person &p) {
		cout << "拷贝构造" << endl;
		this->age = p.age;
		
		//浅拷贝，对于指针，直接复制指针，没有复制数据(两个对象中的height指针存放的地址相同，指向同一个内存空间)
		//this->height = p.height;//用浅拷贝的时候，在两个对象的指针都释放的时候会报错
		
		//深拷贝，对于指针，先在堆区域复制一个原对象指针指向的数据，再将新对象的指针指向该数据(两个对象中的height指针存放的地址不同，但两个地址的数据相同)
		this->height = new int(*p.height);//用深拷贝时，对象含指针释放的时候也不会报错
	}

	~Person() {
		cout << "析构函数!" << endl;//析构函数将堆区域的变量释放
		if (height != NULL)
		{
			delete height;
			height = NULL;//置空，防止野指针出现
		}
	}
};

void test() {
	Person person(24, 180);
	cout << "person\t\tage:" << person.age << "\thegiht" << *person.height << endl;
	Person new_person(person);
	cout << "new_person\tage:" << person.age << "\thegiht" << *person.height << endl;
}

void main() {
	test();
}
```

### 初始对象

> 方法一：利用构造函数，写在构造函数里面，一个一个成员的赋值
> 方法二：构造函数()：属性1(值1),属性2（值2）... {}

```c++
#include<iostream>
using namespace std;

class Person {
public:
	int age;
	int height;
	int score;
	Person(int a,int b,int c) :age(a), height(b), score(c) {//方法二初始化列表
	}
	void showprint() {
		cout << "age:" << age << "\t\theight:" << height << "\tscore:" << score << endl;
	}
};

void main() {
	Person person(20,180,85);
	person.showprint();
}
```

### 对象成员

> 类作为另一个类的成员时,我们称该成员为对象成员
> 	构造的顺序是 ：先调用对象成员的构造，再调用本类构造
> 	析构顺序与构造相反

```c++
#include<iostream>
#include<string>
using namespace std;

class Phone {
public:
	string pname;
	int price;
	Phone() {}
	Phone(string a, int b) :pname(a), price(b) {
		cout << "phone构造函数" << endl;
	}
};

class Person {
public:
	string name;
	Phone myphone;
	Person(string a, string b, int c) :name(a), myphone(b, c) {//这里myphone(b, c)是一个隐式转换法，等价Phone myphone={b,c}
		cout << "person构造函数" << endl;
	}
};

void test() {
	Person person("张三", "华为", 3200);
	cout << "name:" << person.name << "\t\tphone:" << person.myphone.pname << "\t\tprice:" << person.myphone.price << endl;
}

void main() {
	test();
}
```

### 静态成员，静态方法

> 静态成员变量
> 	1.所有对象共享同一份数据
> 	2.在编译阶段分配内存
> 	3.类内声明，类外初始化(重点)
>
> 静态成员函数
> 	1.所有对象共享同一个函数
> 	2.静态成员函数只能访问静态成员变量

```c++
#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	static int static_a;
	int nostatic;
	static void fuc_a() {
		cout << "静态方法fuc_a(puplic)" << endl;
		//nostatic = 100;//静态函数只能访问静态成员，非静态成员的静态函数不能访问
	}

private:
	static int static_b;
	static void fuc_b() {
		cout << "静态方法fuc_b(private)" << endl;
	}
};

int Person::static_a = 0;
int Person::static_b = 0;

void test() {
	//静态成员变量和静态成员方法两种访问方式
	//1、通过对象
	Person person;
	person.static_a = 100;
	//person.static_b = 100;//私有的静态成员不可访问
	cout << "static_a = " << person.static_a << endl;
	person.fuc_a();
	//2、通过类名
	cout << "static_a = " << Person::static_a << endl;
	Person::fuc_a();
	//Person::fuc_b();//私有的静态方法不可访问
}

void main() {
	test();
}
```

### 类和对象的大小

> C++中类内的成员变量和成员函数分开存储
>
> **只有非静态成员变量才属于类的对象上、空类1B，非空类(静态成员变量的大小相加)**

```c++
#include<iostream>
using namespace std;

class Person_a {};//1B

class Person_b {//4B
	int a;//非静态成员变量
};

class Person_c {//4B
	int a;//非静态成员变量
	static int static_c;//静态成员变量
};
int Person_c::static_c = 0;

class Person_d {//4B
	int a;//非静态成员变量
	static int static_d;//静态成员变量
	void func_() {}
};

void test() {
	//编译器会给空对象分配一个字节空间，为了区分空对象占内存的位置
	cout << "空类占字节数：" << sizeof(Person_a) << endl;
	//非静态成员变量  属于类的对象上
	cout << "(只含非静态成员变量)类占字节数：" << sizeof(Person_b) << endl;
	//静态成员变量    不属于类的对象上
	cout << "(非静态成员变量+静态成员变量)类占字节数：" << sizeof(Person_c) << endl;
	//成员函数        不属于类的对象上
	cout << "(非静态成员变量+静态成员变量+函数)类占字节数：" << sizeof(Person_d) << endl;
}

void main() {
	test();
}
```

### this指针

> this指针**指向被调用的成员函数所属的对象**
> 	this指针是隐含每一个非静态成员函数内的一种指针
> 	this指针不需要定义，直接使用即可
>
> this指针的用途：
> 	当形参和成员变量同名时，可用this指针来区分
> 	在类的非静态成员函数中返回对象本身，可使用return *this

C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

### const修饰函数和对象

> **常函数**：
> 	成员函数后加const后我们称为这个函数为**常函数**
> 	常函数内不可以修改成员属性
> 	成员属性声明时加关键字mutable后，在常函数中依然可以修改
>
> **常对象**：
> 	声明对象前加const称该对象为常对象
> 	常对象只能调用常函数

```c++
#include<iostream>
using namespace std;

class Person {
public:
public:
	int m_A;
	mutable int m_B; //可修改 可变的

	Person() {
		m_A = 0;
		m_B = 0;
	}

	//this指针的本质是一个指针常量，指针的指向不可修改
	//如果想让指针指向的值也不可以修改，需要声明常函数
	void ShowPerson() const {
		//const Type* const pointer;
		//this = NULL; //不能修改指针的指向 Person* const this;
		//this->mA = 100; //但是this指针指向的对象的数据是可以修改的

		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
		cout << "常函数" << endl;
	}

	void MyFunc() {
		//mA = 10000;
		cout << "普通函数"<< endl;
	}
	//const修饰对象  常对象
};
void test() {
		const Person person; //常量对象  
		cout << person.m_A << endl;
		//person.mA = 100; //常对象不能修改成员变量的值,但是可以访问
		person.m_B = 100; //但是常对象可以修改mutable修饰成员变量

		person.ShowPerson();//常对象只能调用常函数

		//常对象访问成员函数
		//person.MyFunc(); //常对象不能调用普通函数
		Person person11;
}
void main() {
	test();
}
```

### 友元

在程序里，**有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术**
友元的目的就是让一个函数或者类 访问另一个类中私有成员
友元的关键字为  ==friend==

> 友元的三种实现
> 	1.全局函数做友元	friend void myfriend();
> 	2.类做友元			friend class friend_a;
> 	3.成员函数做友元	friend void friend_b::visit1();

注意：	1.用指针(或引用)创建类，可以解决类未定义的问题(先声明)
				2.把类中所有的函数先声明，放在最后定义，可以解决未定义的问题

```c++
#include<string>
using namespace std;
class Building;
class friend_a;
class friend_b;

class friend_a {//友元类
public:
	friend_a();
	void visit();
private:
	Building *b;
};

class friend_b {//友元函数的类
public:
	friend_b();
	void visit1();//友元函数
	void visit2();//非友元函数
private:
	Building *b;
};


class Building {//本类
	//1.全局函数做友元，告诉编译器 myfriend全局函数是 Building类的友元，可以访问类中的私有内容
	friend void myfriend();
	//2.类做友元，友元类内的函数可以访问该类的私有容
	friend class friend_a;
	//3.成员函数做友元，该成员函数可以访问该类的私有容
	friend void friend_b::visit1();
public:
	string sittingroom;
private:
	string bedroom;
public:
	Building();
};

friend_a::friend_a() {
	b = new Building;
}

friend_b::friend_b() {
	b = new Building;
}
Building::Building() {
	sittingroom = "客厅";
	bedroom = "卧室";
}
void friend_a::visit() {//2.类做友元
	cout << "我的朋友正在访问：" << b->sittingroom << endl;
	cout << "我的朋友正在访问：" << b->bedroom << endl;//friend_类是 Building类的友元，可以访问类中的私有内容
}

void friend_b::visit1() {
	cout << "我的朋友正在访问：" << b->sittingroom << endl;
	cout << "我的朋友正在访问：" << b->bedroom << endl;//friend_b::visit1()成员函数是Building类的友元，可以访问类中的私有内容
}
void friend_b::visit2() {
	cout << "我的朋友正在访问：" << b->sittingroom << endl;
	//cout << "我的朋友正在访问：" << b->bedroom << endl;//friend_b::visit2()成员函数不是Building类的友元，不可以访问类中的私有内容
}


void myfriend() {//1.全局函数做友元
	Building see;
	cout << "我的朋友正在访问：" << see.sittingroom << endl;
	cout << "我的朋友正在访问：" << see.bedroom << endl;//myfriend全局函数是 Building类的友元，可以访问类中的私有内容
}


void main() {
	myfriend();
	friend_a fria;
	fria.visit();
	friend_b frib;
	frib.visit1();
	frib.visit2();
}
```

### 运算符重载

**运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型**

**“+”号运算符重载**
		作用：实现两个自定义数据类型相加的运算
			实现：1.成员函数实现“+”号运算符重载
				  2.全局函数实现“+”号运算符重载
			总结：1.对于内置的数据类型的表达式的的运算符是不可能改变的
				  2.不要滥用运算符重载

**“<<”左移运算符重载**
		实现：全局函数

**“++”递增运算符重载**，包括前置递增运算符重载和后置递增运算符重载
		实现：成员函数

```c++
#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	int A;
	int B;

	void show() {
		cout << "A:" << A << "\tB:" << B << endl;
	}
	//Person operator+(Person &p) {//1.成员函数实现“ + ”号运算符重载
	//	Person temp;
	//	temp.A = this->A + p.A;
	//	temp.B = this->B + p.B;
	//	return temp;
	//}

	//我们不用成员函数实现<<运算符重载
	//成员函数 实现不了  p << cout 不是我们想要的效果
	//void operator<<(Person& p){
	//}

	Person& operator++() {//前置递增
		this->A++;//先+
		this->B++;
		return *this;//再返回
		//前置递增可以链式操作，所以返回引用(本体)
	}

	Person operator++(int) {//用占位符实现函数重载，区分前置和后置
		Person temp = *this;//先记录
		A++;//先+
		B++;
		return temp;//再返回
		//后置递增不能链式操作，所以返回类(形参)
	}

	//通过析构函数可以来看变量的释放情况
	//~Person() {
	//	cout << "释放类的变量了" << endl;
	//}

};

Person operator+(Person p1, Person &p2) {//2.全局函数实现“+”号运算符重载
	Person temp;
	temp.A = p1.A + p2.A;
	temp.B = p1.B + p2.B;
	return temp;
}

//全局函数实现“<<”左移运算符重载
ostream& operator<<(ostream &out, Person p) {//cout是标准的数据输出流，只有一个，所以只能用引用，引用是起别名，所以命名可以随便，例：out
	out << "A:" << p.A << "\tB:" << p.B;//为什么这个地方用引用传递Person &p，在91行(cout << "p2++:\t\t" << p2++ << endl;//后置递增)报错
	return out;
}

void test() {
	//“+”号运算符重载
	Person p1;
	p1.A = 10;
	p1.B = 10;
	Person p2;
	p2.A = 15;
	p2.B = 15;
	Person p3 = p1 + p2;

	cout << "p1.A=10\tp1.B = 10" << endl;
	cout << "p2.A=15\tp1.B = 15" << endl;
	cout << "p3=p1+p2\t";
	p3.show();

	//“ << ”左移运算符重载
	cout << "p3:\t\t"<< p3 << "\t链式思想" << endl;

	//“++”递增运算符重载
	cout << "++++++p1:\t"<< ++++++p1 << endl;//前置递增
	cout << "p1:\t\t" << p1 << endl;//前置递增
	cout << "p2++:\t\t" << p2++ << endl;//后置递增
	cout << "p2:\t\t" << p2 << endl;//后置递增
}

void main() {
	test();
	system("pause");
}
```

**"="符号重载**

c++编译器至少给一个类添加4个函数

1. 默认构造函数(无参，函数体为空)
2. 默认析构函数(无参，函数体为空)
3. 默认拷贝构造函数，对属性进行值拷贝
4. 赋值运算符 operator=, 对属性进行值拷贝

**如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题**

```c++
#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	int *age;
	Person(int age) {
		this->age = new int(age);
	}

	~Person() {
		if (this->age != NULL) {
			delete this->age;//delete实际上是释放指针指向的内存空间
			this->age = NULL;//指针置空
		}
		cout << "释放" << endl;
	}

	Person& operator=(Person &p) {
		if (this->age != NULL) {//先检查被赋值的类是否为空
			delete this->age;//delete实际上是释放指针指向的内存空间
			this->age = NULL;//指针置空
		}
		this->age = new int(*p.age);
		return *this;
	}
};

void test() {
	Person p1(18);
	Person p2(20);
	Person p3(30);

	//Person p3 = p2;//不要写这种，这是创建对象，对应的是构造函数，并没有定义这样的构造函数，编译器还是只会复制指针，释放时出错
	p3= p2 = p1;//赋值操作，没有问题
	cout << "p1.age:" << *p1.age << "\t\tp2.age" << *p2.age << "\t\tp3.age" << *p3.age << endl;//值
	cout << "&p1.age:" << p1.age << "\t&p2.age" << p2.age << "\t\t&p3.age" << p3.age << endl;//地址
}

void main() {
	test();
	system("pause");
}
```

**关系运算符重载**：== ， !=

重载关系运算符，可以让两个自定义类型对象进行对比操作

```c++
#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	int age;
	Person(int age) {
		this->age = age;
	}

	bool operator==(Person &p) {
		if (this->age == p.age) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(Person& p) {
		if (this->age == p.age) {
			return false;
		}
		else {
			return true;
		}
	}
};

void test() {
	Person p1(23);
	Person p2(24);

	if (p1 == p2) {
		cout << "p1与p2年龄相同" << endl;
	}
	else {
		cout << "p1与p2年龄不相同" << endl;
	}

	if (p1 != p2) {
		cout << "p1与p2年龄不相同" << endl;
	}
	else {
		cout << "p1与p2年龄相同" << endl;
	}
}

void main() {
	test();
}
```

**函数调用运算符()重载**

> 函数调用运算符()  也可以重载
> 由于重载后使用的方式非常像函数的调用，因此称为仿函数
> 仿函数没有固定写法，非常灵活

==**类当函数用，伪函数**==

```
#include<iostream>
#include<string>
using namespace std;

class class_a {
public:
	void operator()() {
		cout << "函数调用运算符()重载" << endl;
	}
	void showprint() {
		cout << "匿名对象调用普通函数" << endl;
	}
};

class class_b {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

void test() {
	class_a cla;//先创建对象，然后对象当函数用
	cla();//伪函数的调用
	class_b clb;
	cout << "a+b两数之和：" << clb(10,15) << endl;

	//匿名对象，不实例化对象，直接调用类里面的函数
	class_a().showprint();//匿名对象调用普通函数
	cout << "匿名对象调用伪函数：a+b两数之和：" << class_b()(10, 15) << endl;//匿名对象调用伪函数

}

void main() {
	test();
}
```

### 继承

继承的好处：减少重复的代码

> 语法: class 子类名:继承方式  父类名
> 子类(派生类)父类(基类)
> 派生类中的成员，包含两大部分:一类是从基类继承过来的，一类是自己增加的成员。

继承方式一共有三种：
	1.公共继承 public		继承下来的成员属性不改变
	2.保护继承 protected	继承下来的成员属性都变为protected
	3.私有继承 private		继承下来的成员属性都变为private
	==三种继承方式下，父类的私有成员都不可以继承==

创建一个子类时：先调用父类构造函数，再调用子类构造函数
		释放时：先调用子类析构函数，再调用父类析构函数

子类对象反问子类和父类中继承的同名成员的处理方式：

- 访问子类同名成员   直接访问即可
- 访问父类同名成员   需要加作用域

```c++
#include<iostream>
#include<string>
using namespace std;

class Father {
public:
	Father() {
		cout << "父类构造函数" << endl;
	}
	Father(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
		cout << "父类构造函数" << endl;
	}
	~Father() {
		cout << "父类析构函数" << endl;
	}
public:
	int a;
protected:
	int b;
private:
	int c;//私有成员只是被隐藏了，但是还是会继承下去
};

class Son:public Father{
public:
	int a;
	int b;
	Son() {
		cout << "子类构造函数" << endl;
	}
	~Son() {
		cout << "子类析构函数" << endl;
	}
};

void test(){
	Son son;
	//父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到
	cout << "sizeof Son = " << sizeof(Son) << endl;
	son.a = 10; //访问子类同名成员   直接访问即可
	son.Father::a = 20;//访问父类同名成员   需要加作用域
}

void main() {
	test();
}
```

多继承可能会引发父类中有同名成员出现，需要加作用域区分

不建议使用各种交叉继承等，造成混乱和浪费空间(继承了同一个成员)，同一个数据出现两次，造成二歧性
	利用虚继承可以解决二歧性问题  class A : virtual public B {};

```c++
#include<iostream>
#include<string>
using namespace std;

class Per {
public:
	int age;
};

class Pera :virtual public Per {};

class Perb :virtual public Per {};

class Perc :public Pera, public Perb {};

void test() {
	Perc p;

	cout << sizeof(Perc) << endl;

	//Perc下面的age成员其实是共用一块数据，一个改了就全改了
	p.age = 10;
	cout << p.age << endl;
	cout << p.Pera::age << endl;
	cout << p.Perb::age << endl;

	p.Pera::age = 15;
	cout << p.age << endl;
	cout << p.Pera::age << endl;
	cout << p.Perb::age << endl;

}

void main() {
	test();
	system("pause");
}
```

### 多态

==父类指针或引用指向子类对象，可调用子类成员和函数==

多态分为两类
	1.静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
	2.动态多态: 派生类和虚函数实现运行时多态

静态多态和动态多态区别：
	静态多态的函数地址早绑定  -  编译阶段确定函数地址
	动态多态的函数地址晚绑定  -  运行阶段确定函数地址

多态满足条件
	1.有继承关系
	2.子类重写父类中的虚函数

多态使用条件
	1.父类指针或引用指向子类对象
	2.重写：函数返回值类型  函数名 参数列表 完全一致称为重写

注意(重点)：
	1.多态就算提供一个接口，根据传入的对象不同有多种实现的形态
	2.父类指针或引用指向子类对象  Base *p=new Son;(指针)  Base &p=son;(引用)

```c++
#include<iostream>
using namespace std;

class Animal {
public:
	//Speak函数就是虚函数
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	virtual void speak() {
		cout << "动物在说话" << endl;
	}

};

class Cat: public Animal {
public:
	void speak() {
		cout << "小猫在说话" << endl;
	}

};

class Dog: public Animal {
public:
	void speak() {
		cout << "小狗在说话" << endl;
	}
};
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编


//地址早绑定 编译阶段确定函数地址
void dospeak(Animal &animal) {//Animal &animal = cat;父类指针或引用指向子类对象
	animal.speak();
}

void test() {
	Cat cat;
	dospeak(cat);
	Dog dog;
	dospeak(dog);
}

void main() {
	test();
}
```

### 纯虚函数和抽象类

纯虚函数：
	在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
	因此可以将虚函数改为**纯虚函数**
	纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0 ;
	当类中有了纯虚函数，这个类也称为==抽象类==

抽象类特点：
	1.无法实例化对象
	2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类

```c++
#include<iostream>
#include<string>
using namespace std;

class Base {
public:
	virtual void func() = 0;//当类中只要有一个纯虚函数，这个类也称为==抽象类==
};

class Son :public Base {//子类必须重写抽象类中的纯虚函数，否则也属于抽象类
public:
	virtual void func() {
		cout << "子类必须重写抽象类中的纯虚函数" << endl;
	}
};

void test() {
	//Base a;//抽象类无法实例化对象，报错
	//new Base;//抽象类无法使用new开辟空间，报错
	Son a;
	Base* p = new Son;
	p->func();
}

void main() {
	test();
}
```

**虚析构和纯虚析构**
多态使用时，如果子类中有属性开辟到堆区(用 new)，那么父类指针在释放时无法调用到子类的析构代码
	解决方式：将父类中的析构函数改为**虚析构**或者**纯虚析构(要声明也要实现)**

虚析构和纯虚析构共性：
	1.可以解决父类指针释放子类对象
	2.都需要有具体的函数实现
纯虚析构函数和纯虚函数不一样，纯虚析构函数也需要实现(写在类外面)(因为父类也有空间要释放)

虚析构和纯虚析构区别：
	1.如果是纯虚析构，该类属于抽象类，无法实例化对象

总结：
	1.虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
	2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
	3.拥有纯虚析构函数的类也属于抽象类

```c++
#include<iostream>
#include<string>

using namespace std;

class Animal {
public:
	Animal() {
		cout << "父类构造函数" << endl;
	}
	//virtual ~Animal() {//利用虚析构函数可以解决  父类指针无法释放子类对象时不干净的问题
	//	cout << "父类虚析构函数" << endl;
	//}

	virtual ~Animal() = 0;//需要声明，需要实现
	virtual void speak() = 0;	
};

Animal::~Animal() {
	cout << "父类纯虚析构函数" << endl;
}

class Cat:public Animal {
public:
	Cat(string name) {
		this->name = new string(name);//对象属性姓名存储在堆区域
		cout << "子类构造函数" << endl;
	}
	~Cat() {
		cout << "子类析构函数" << endl;
		if (name != NULL) {
			delete name;
			name = NULL;
		}
	}
	virtual void speak() {
		cout << *this->name <<"在说话" << endl;
	}
	string *name;

};

void test() {
	Animal *animal = new Cat("Tom");//实例化的对象存储在堆区域
	animal->speak();
	delete animal;
	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
}

void main() {
	test();
	system("pause");
}
```

### 文件输入输出

C++中对文件操作需要包含头文件&lt; fstream >

文件类型分为两种：

1. **文本文件**     -  文件以文本的**ASCII码**形式存储在计算机中
2. **二进制文件** -  文件以文本的**二进制**形式存储在计算机中，用户一般不能直接读懂它们

操作文件的三大类:

1. ofstream：写操作
2. ifstream： 读操作
3. fstream ： 读写操作

写文件步骤如下：
	1.包含头文件	#include <fstream>
	2.创建流对象	ofstream ofs;
	3.打开文件		ofs.open("文件路径",打开方式);
	4.写数据		ofs << "写入的数据";
	5.关闭文件		ofs.close();

文件的打开方式

| 打开方式    | 解释                       |
| ----------- | -------------------------- |
| ios::in     | 为读文件而打开文件         |
| ios::out    | 为写文件而打开文件         |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在先删除，再创建 |
| ios::binary | 二进制方式                 |

读文件步骤如下：
	1.包含头文件						#include <fstream>
	2.创建流对象						ifstream ifs;
	3.打开文件并判断文件是否打开成功	ifs.open("文件路径",打开方式);
	4.读数据							四种方式读取
	5.关闭文件							ifs.close();

```c++
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void test_a(){
	ofstream ofs;
	ofs.open("test.txt", ios::out);

	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	ofs.close();
}

void test_b()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	////四种读文件的操作
	////第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	////第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

	////第四种
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;
	//}

	ifs.close();
}

void main() {
	test_a();
	system("pause");
	test_b();
	system("pause");
}
```

打开方式要指定为	ios::binary

写文件：
	二进制方式写文件主要利用流对象调用成员函数write
	函数原型 ：`ostream& write(const char * buffer,int len);`
	参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
	文件输出流对象 可以通过write函数，以二进制方式写数据

读文件：
	二进制方式读文件主要利用流对象调用成员函数read
	函数原型：`istream& read(char *buffer,int len);`
	参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
	文件输入流对象 可以通过read函数，以二进制方式读数据

```c++
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

//二进制文件	写文件
void test_20_2a(){
	//写文件
	//1、包含头文件
	//2、创建输出流对象
	ofstream ofs("person.txt", ios::out | ios::binary);
	//3、打开文件
	//ofs.open("person.txt", ios::out | ios::binary);
	Person_20_2 p = { "张三"  , 18 };
	//4、写文件
	ofs.write((const char*)&p, sizeof(p));
	//5、关闭文件
	ofs.close();

	//读文件
}

//二进制文件	读文件
void test_20_2b() {

	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	Person_20_2 p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}


void main() {
	test_20_2a();
	system("pause");
	test_20_2b();
	system("pause");
}
```

### 模板

模板——建立通用的模具，大大提高复用性（泛型编程）
	1.C++两种编程思想：面向对象编程、泛型编程
	2.C++提供两种模板机制:函数模板、类模板

函数模板：
	1.语法：template<typename T\> 函数模板声明，一定就写在函数上面一行
			template  ---  声明创建模板
			typename  --- 表面其后面的符号是一种数据类型，可以用class代替
			T    ---   通用的数据类型，名称可以替换，通常为大写字母
	2.使用：有两种方式使用函数模板
			2.1自动类型推导
			2.2显示指定类型
	3.注意：
			3.1自动类型推导，必须推导出一致的数据类型T,才可以使用
			3.2模板必须要确定出T的数据类型，才可以使用

```c++
#include<iostream>
using namespace std;

//函数模板
//声明一个模板，告诉编译器后面的代码中紧跟着的T不要报错，T是一个通用测数据类型
template<typename T>//一定就写在函数上面一行
void mySwap(T &a,T &b) {//通用的交换函数，不用再将每种数据类型都定义一个函数
	T temp = a;
	a = b;
	b = temp;
}

template<class T>//这里typename和class区别不大，都可
void func() {
	cout << "模板必须要确定出T的数据类型，才可以使用" << endl;
}

void test() {
	int a = 10;
	int b = 20;

	//有两种方式使用函数模板
	//1、自动类型推导
	mySwap(a, b);

	//2、显示指定类型
	mySwap<int>(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//func();//模板必须要确定出T的数据类型，才可以使用，不然报错
	func<int>();//可以随便给它一个数据类型就可以使用模板函数
}

void main() {
	test();
	system("pause");
}
```



