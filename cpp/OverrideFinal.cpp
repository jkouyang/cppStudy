/*override	final
* 
	override��ȷ��������������������д�����������麯������ͬ��ǩ����ͬʱҲ��ȷ����������д������麯��
	final������ĳ���಻�ܱ��̳У�����ĳ���麯�����ܱ���д
*/

#include<iostream>
#include<string>
using namespace std;

class BaseOverrideFinal {
public:
	virtual void func1() final{//final���κ���(ֻ�����麯��)�����麯�����������౻��д(��������)��������ʹ�ø��麯��
	}
	
	virtual void func2(){
	}
};

class SonOverrideFinal final :BaseOverrideFinal {//final�����࣬���಻�ܱ��̳�
	virtual void func2() override {//override���κ�������д���ຯ��
	}
};