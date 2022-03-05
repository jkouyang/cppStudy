/*
案例描述
	1.公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
	2.员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
	3.随机给10名员工分配部门和工资
	4.通过multimap进行信息的插入  key(部门编号) value(员工)
	5.分部门显示员工信息

实现步骤：
	1.创建10名员工，放到vector中
	2.遍历vector容器，取出每个员工，进行随机分组
	3.分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
	4.分部门显示员工信息
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stdlib.h>
#include <time.h>
using namespace std;

class WorkerCase {//员工类
public:
	string myName;
	int myWage;
	WorkerCase(string name,int wage) {
		this->myName = name;
		this->myWage = wage;
	}
};

void makeWorkerCase(vector<WorkerCase> &v) {//构建员工
	string str = "Worker_";
	string name = "ABCDEFGHIJ";
	
	for (int i = 0; i < 10; i++) {
		WorkerCase worker(str+name[i],rand()%5000+5000);
		v.push_back(worker);
	}
}

void makeDeptCase(vector<WorkerCase>& v, multimap<int, WorkerCase>& m) {//分配部门
	for (vector<WorkerCase>::iterator pBegin = v.begin(); pBegin != v.end(); pBegin++) {
		m.insert(make_pair(rand() % 3, *pBegin));
	}
}

void myPrintWorkerCase(multimap<int, WorkerCase>& m) {//显示信息
	//key=0时为美工部
	multimap<int, WorkerCase>::iterator pBegin = m.find(0);
	int num0 = m.count(0);
	cout << "============美工部(" << num0 << "人)=========== " << endl;
	for (int index = 0; pBegin != m.end() && index < num0; pBegin++, index++) {
		cout << "姓名：" << pBegin->second.myName << "\t工资" << pBegin->second.myWage << endl;
	}
	//key=1时为研发部
	pBegin = m.find(1);
	int num1 = m.count(1);
	cout << "============研发部(" << num1 << "人)=========== " << endl;
	for (int index = 0; pBegin != m.end() && index < num1; pBegin++, index++) {
		cout << "姓名：" << pBegin->second.myName << "\t工资" << pBegin->second.myWage << endl;
	}
	//key=2时为策划部
	pBegin = m.find(2);
	int num2 = m.count(2);
	cout << "============策划部(" << num2 << "人)=========== " << endl;
	for (int index = 0; pBegin != m.end() && index < num2; pBegin++, index++) {
		cout << "姓名：" << pBegin->second.myName << "\t工资" << pBegin->second.myWage << endl;
	}
}

void testWorkerCase() {
	srand((unsigned)time(NULL));
	vector<WorkerCase> v_Worker;
	makeWorkerCase(v_Worker);
	multimap<int, WorkerCase> m__Worker;
	makeDeptCase(v_Worker,m__Worker);
	myPrintWorkerCase(m__Worker);
}

//void main() {
//	testWorkerCase();
//}
