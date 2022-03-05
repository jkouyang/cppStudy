/*案例：多态案例—— 电脑组装
电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）

将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商

创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口

测试时组装三台不同的电脑进行工作
*/


#include<iostream>
#include<string>

using namespace std;


class CPU_19_6 {//cpu抽象类
public:
	virtual void claculate() = 0;
};

class VideoCard_19_6 {//显卡抽象类
public:
	virtual void dispaly() = 0;
};

class Memory_19_6 {//内存抽象类
public:
	virtual void storage() = 0;
};

//=========具体厂商
//Intel
class IntelCPU_19_6 :public CPU_19_6 {//IntelCPU
public:
	void claculate() {
		cout << "Intel的CPU正在计算" << endl;
	}
};
class IntelVideoCard_19_6 :public VideoCard_19_6 {//Intel显卡
public:
	void dispaly() {
		cout << "Intel的显卡正在显示" << endl;
	}
};
class IntelMemory_19_6 :public Memory_19_6 {//Intel内存
public:
	void storage() {
		cout << "Intel的内存正在存储" << endl;
	}
};

//Lenove
class LenoveCPU_19_6 :public CPU_19_6 {//LenoveCPU
public:
	void claculate() {
		cout << "Lenove的CPU正在计算" << endl;
	}
};
class LenoveVideoCard_19_6 :public VideoCard_19_6 {//Lenove显卡
public:
	void dispaly() {
		cout << "Lenove的显卡正在显示" << endl;
	}
};
class LenoveMemory_19_6 :public Memory_19_6 {//Lenove内存
public:
	void storage() {
		cout << "Lenove的内存正在存储" << endl;
	}
};


class Computer_19_6 {//电脑类
public:
	Computer_19_6(CPU_19_6 *cpu, VideoCard_19_6 *videocard, Memory_19_6 *memory) {
		this->cpu = cpu;
		this->videocard = videocard;
		this->memory = memory;
	}
	CPU_19_6 *cpu;
	VideoCard_19_6 *videocard;
	Memory_19_6 *memory;

	void doWork() {
		this->cpu->claculate();
		this->videocard->dispaly();
		this->memory->storage();
	}

	~Computer_19_6() {//有指针的类都尽量用析构函数释放
		if (this->cpu = NULL) {
			delete this->cpu;
			this->cpu = NULL;
		}
		if (this->videocard = NULL) {
			delete this->videocard;
			this->videocard = NULL;
		}
		if (this->memory = NULL) {
			delete this->memory;
			this->memory = NULL;
		}
	}
};

void test_19_6() {
	cout << "======电脑1正在工作======" << endl;
	LenoveCPU_19_6* cpu = new LenoveCPU_19_6;
	IntelVideoCard_19_6* videocard = new IntelVideoCard_19_6;
	LenoveMemory_19_6* memory = new LenoveMemory_19_6;
	Computer_19_6 *com1=new Computer_19_6(cpu, videocard, memory);
	com1->doWork();
	delete com1;//释放com1指向的Computer_19_6类，现在com1指针为空指针，还是不能重定义，但可以改变指向

	cout << "======电脑2正在工作======" << endl;
	com1 = new Computer_19_6(new IntelCPU_19_6, new IntelVideoCard_19_6, new LenoveMemory_19_6);
	com1->doWork();
	delete com1;

}

//void main() {
//	test_19_6();
//	system("pause");
//}