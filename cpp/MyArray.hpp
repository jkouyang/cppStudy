

#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class myArray {
private:
	T* pAddress;//ָ��һ���ѿռ䣬����ռ�洢����������
	int capacity;//����
	int size;// ��С
public:
	//���캯��
	myArray(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[capacity];//������࣬��Ӧ����һ���չ��캯��
	}
	//��������
	myArray(const myArray &arr) {//������ֻ�ܵ��ó����������Ա�����ܵ��÷ǳ�����
		//ͬһ��Ĳ�ͬ���������ڻ�Ϊ��Ԫ�����Կ���дΪarr.capacity����˽������
		this->pAddress = new T[arr.capacity];
		//this->pAddress = new T[arr.getCapacity()];
		//Ҳ���ù��еķ������� getCapacity()����дΪthis->pAddress = new T[arr.getCapacity()];
		this->capacity = arr.capacity;
		this->size = arr.size;
		for (int i = 0; i < arr.size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//����= ������  ��ֹǳ��������
	myArray& operator=(const myArray& arr) {
		cout << "����= ������" << endl;
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}
		this->pAddress = new T[arr.capacity];
		this->capacity = arr.capacity;
		this->size = arr.size;
		for (int i = 0; i < arr.size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//����[] ������  arr[0]
	T& operator[](int index) {
		return this->pAddress[index];
	}
	//β�巨
	void Push_back(const T& val) {
		if (this->capacity == this->size) {//����Ϊ��ֱ�ӷ���
			return;
		}
		this->pAddress[this->size] = val;
		this->size++;
	}
	//βɾ��
	void Pop_back() {
		if (this->size==0) {//����Ϊ��ֱ�ӷ���
			return;
		}
		this->size--;//���û����ʲ������߼��ϵ�ɾ��
	}
	//��ȡ��������
	int getCapacity() const {//������
		return this->capacity;
	}
	//��ȡ�����С
	int	getSize() const {
		return this->size;
	}
	//����
	~myArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}
	}
};