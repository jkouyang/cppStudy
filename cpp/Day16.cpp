/*Day16  ��Ԫ
�ڳ������Щ˽������ Ҳ�������������һЩ������������з��ʣ�����Ҫ�õ���Ԫ�ļ���
��Ԫ��Ŀ�ľ�����һ������������ ������һ������˽�г�Ա
��Ԫ�Ĺؼ���Ϊ  ==friend==

��Ԫ������ʵ��
	1.ȫ�ֺ�������Ԫ	friend void myfriend_16();
	2.������Ԫ			friend class friend_16a;
	3.��Ա��������Ԫ	friend void friend_16b::visit1();

****ע�⣺	1.��ָ��(������)�����࣬���Խ����δ���������(������)
			2.���������еĺ�������������������壬���Խ��δ���������
*/

#include<iostream>
#include<string>
using namespace std;
class Building_16;
class friend_16a;
class friend_16b;

class friend_16a {//��Ԫ��
public:
	friend_16a();
	void visit();
private:
	Building_16 *b;
};

class friend_16b {//��Ԫ��������
public:
	friend_16b();
	void visit1();//��Ԫ����
	void visit2();//����Ԫ����
private:
	Building_16 *b;
};


class Building_16 {//����
	//1.ȫ�ֺ�������Ԫ�����߱����� myfriend_16ȫ�ֺ����� Building�����Ԫ�����Է������е�˽������
	friend void myfriend_16();
	//2.������Ԫ����Ԫ���ڵĺ������Է��ʸ����˽����
	friend class friend_16a;
	//3.��Ա��������Ԫ���ó�Ա�������Է��ʸ����˽����
	friend void friend_16b::visit1();
public:
	string sittingroom;
private:
	string bedroom;
public:
	Building_16();
};

friend_16a::friend_16a() {
	b = new Building_16;
}

friend_16b::friend_16b() {
	b = new Building_16;
}
Building_16::Building_16() {
	sittingroom = "����";
	bedroom = "����";
}
void friend_16a::visit() {//2.������Ԫ
	cout << "�ҵ��������ڷ��ʣ�" << b->sittingroom << endl;
	cout << "�ҵ��������ڷ��ʣ�" << b->bedroom << endl;//friend_16���� Building�����Ԫ�����Է������е�˽������
}

void friend_16b::visit1() {
	cout << "�ҵ��������ڷ��ʣ�" << b->sittingroom << endl;
	cout << "�ҵ��������ڷ��ʣ�" << b->bedroom << endl;//friend_16b::visit1()��Ա������Building�����Ԫ�����Է������е�˽������
}
void friend_16b::visit2() {
	cout << "�ҵ��������ڷ��ʣ�" << b->sittingroom << endl;
	//cout << "�ҵ��������ڷ��ʣ�" << b->bedroom << endl;//friend_16b::visit2()��Ա��������Building�����Ԫ�������Է������е�˽������
}


void myfriend_16() {//1.ȫ�ֺ�������Ԫ
	Building_16 see;
	cout << "�ҵ��������ڷ��ʣ�" << see.sittingroom << endl;
	cout << "�ҵ��������ڷ��ʣ�" << see.bedroom << endl;//myfriend_16ȫ�ֺ����� Building�����Ԫ�����Է������е�˽������
}


//void main() {
//	myfriend_16();
//	friend_16a fria;
//	fria.visit();
//	friend_16b frib;
//	frib.visit1();
//	frib.visit2();
//}