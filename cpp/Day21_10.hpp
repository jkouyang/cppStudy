/*
��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�
	1.��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
	2.��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���

���µ����⣻�������֮ǰ��ͷ�ļ�.h��д�������(������ĳ�Ա�ͺ���)
			��Դ�ļ�.cpp��д��Ķ���(��ĳ�Ա�ͺ�����ʵ��)
			����ʱֻд#include<xxxx.h>
			����������ģ���еĳ�Ա�����ڵ���ʱ�Ŵ��������Բ��ᴴ����ģ�庯��������
����취��
		����1��ֱ�Ӱ���.cppԴ�ļ�����ʱд#include<xxxx.cpp>���ȵ�cpp�ļ���cpp�ļ��ٵ���.h�ļ�
		����2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��
		���÷���2
*/


#pragma once
#include<iostream>
#include<string>
using namespace std;

//����2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��

//������
template<class T1,class T2>
class Person_21_10 {
public:
	T1 name;
	T2 age;
	Person_21_10(T1 name, T2 age);
	void showPerson();
};


//���캯�� ����ʵ��
template<class T1, class T2>
Person_21_10<T1,T2>::Person_21_10(T1 name, T2 age) {
	this->name = name;
	this->age = age;
}

//��Ա���� ����ʵ��
template<class T1, class T2>
void Person_21_10<T1, T2>::showPerson() {
	cout << "Name: " << this->name << "\tAge: " << this->age << endl;
}


