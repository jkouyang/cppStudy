/* 案例--制作饮品
制作饮品的大致流程为：煮水 -  冲泡 - 倒入杯中 - 加入辅料

*/



#include<iostream>
#include<string>

using namespace std;

//抽象制作饮品
class AbstractDrinking_19_4 {
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//规定流程
	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffee_19_4 : public AbstractDrinking_19_4 {
public:
	//烧水
	virtual void Boil() {
		cout << "煮农夫山泉!" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡咖啡!" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "将咖啡倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加入牛奶!" << endl;
	}
};

//制作茶水
class Tea_19_4 : public AbstractDrinking_19_4 {
public:
	//烧水
	virtual void Boil() {
		cout << "煮自来水!" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "冲泡茶叶!" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "将茶水倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "加入枸杞!" << endl;
	}
};

//业务函数
void DoWork_19_4(AbstractDrinking_19_4* drink) {
	drink->MakeDrink();
	delete drink;
}

void test_19_4() {
	DoWork_19_4(new Coffee_19_4);
	cout << "--------------" << endl;
	DoWork_19_4(new Tea_19_4);
}


//void main() {
//	test_19_4();
//	system("pause");
//
//}