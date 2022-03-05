

#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class myArray {
private:
	T* pAddress;//指向一个堆空间，这个空间存储真正的数据
	int capacity;//容量
	int size;// 大小
public:
	//构造函数
	myArray(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[capacity];//如果是类，对应的是一个空构造函数
	}
	//拷贝构造
	myArray(const myArray &arr) {//常对象只能调用常函数和类成员，不能调用非常函数
		//同一类的不同对象在类内互为友元，所以可以写为arr.capacity调用私有属性
		this->pAddress = new T[arr.capacity];
		//this->pAddress = new T[arr.getCapacity()];
		//也可用公有的方法调用 getCapacity()，改写为this->pAddress = new T[arr.getCapacity()];
		this->capacity = arr.capacity;
		this->size = arr.size;
		for (int i = 0; i < arr.size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//重载= 操作符  防止浅拷贝问题
	myArray& operator=(const myArray& arr) {
		cout << "重载= 操作符" << endl;
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

	//重载[] 操作符  arr[0]
	T& operator[](int index) {
		return this->pAddress[index];
	}
	//尾插法
	void Push_back(const T& val) {
		if (this->capacity == this->size) {//数据为满直接返回
			return;
		}
		this->pAddress[this->size] = val;
		this->size++;
	}
	//尾删法
	void Pop_back() {
		if (this->size==0) {//数据为空直接返回
			return;
		}
		this->size--;//让用户访问不到，逻辑上的删除
	}
	//获取数组容量
	int getCapacity() const {//常函数
		return this->capacity;
	}
	//获取数组大小
	int	getSize() const {
		return this->size;
	}
	//析构
	~myArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->capacity = 0;
			this->size = 0;
		}
	}
};