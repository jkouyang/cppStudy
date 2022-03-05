/*��������̬�������� ������װ
������Ҫ��ɲ���Ϊ CPU�����ڼ��㣩���Կ���������ʾ�����ڴ��������ڴ洢��

��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����������Intel���̺�Lenovo����

�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�

����ʱ��װ��̨��ͬ�ĵ��Խ��й���
*/


#include<iostream>
#include<string>

using namespace std;


class CPU_19_6 {//cpu������
public:
	virtual void claculate() = 0;
};

class VideoCard_19_6 {//�Կ�������
public:
	virtual void dispaly() = 0;
};

class Memory_19_6 {//�ڴ������
public:
	virtual void storage() = 0;
};

//=========���峧��
//Intel
class IntelCPU_19_6 :public CPU_19_6 {//IntelCPU
public:
	void claculate() {
		cout << "Intel��CPU���ڼ���" << endl;
	}
};
class IntelVideoCard_19_6 :public VideoCard_19_6 {//Intel�Կ�
public:
	void dispaly() {
		cout << "Intel���Կ�������ʾ" << endl;
	}
};
class IntelMemory_19_6 :public Memory_19_6 {//Intel�ڴ�
public:
	void storage() {
		cout << "Intel���ڴ����ڴ洢" << endl;
	}
};

//Lenove
class LenoveCPU_19_6 :public CPU_19_6 {//LenoveCPU
public:
	void claculate() {
		cout << "Lenove��CPU���ڼ���" << endl;
	}
};
class LenoveVideoCard_19_6 :public VideoCard_19_6 {//Lenove�Կ�
public:
	void dispaly() {
		cout << "Lenove���Կ�������ʾ" << endl;
	}
};
class LenoveMemory_19_6 :public Memory_19_6 {//Lenove�ڴ�
public:
	void storage() {
		cout << "Lenove���ڴ����ڴ洢" << endl;
	}
};


class Computer_19_6 {//������
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

	~Computer_19_6() {//��ָ����඼���������������ͷ�
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
	cout << "======����1���ڹ���======" << endl;
	LenoveCPU_19_6* cpu = new LenoveCPU_19_6;
	IntelVideoCard_19_6* videocard = new IntelVideoCard_19_6;
	LenoveMemory_19_6* memory = new LenoveMemory_19_6;
	Computer_19_6 *com1=new Computer_19_6(cpu, videocard, memory);
	com1->doWork();
	delete com1;//�ͷ�com1ָ���Computer_19_6�࣬����com1ָ��Ϊ��ָ�룬���ǲ����ض��壬�����Ըı�ָ��

	cout << "======����2���ڹ���======" << endl;
	com1 = new Computer_19_6(new IntelCPU_19_6, new IntelVideoCard_19_6, new LenoveMemory_19_6);
	com1->doWork();
	delete com1;

}

//void main() {
//	test_19_6();
//	system("pause");
//}