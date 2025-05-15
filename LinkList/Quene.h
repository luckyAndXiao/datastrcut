#pragma once
#include<iostream>
using namespace std;

template<class T>
class Quene {
private:
	T* p;
	int rear , front;
	int size;
public:
	Quene(int size) {
		this->size = size;
		rear = front = 0;
		p = new T[this->size];
	}
	~Quene() {
		rear = front = 0;
		delete[]p;
	}
	T DeQuene() {
		if (rear == front) {
			cout << "队列为空！";
		}
		T e = p[front];
		front = (front + 1) % size;
		return e;
	}
	void EnQuene(T e) {
		if ((rear + 1) % size == front) {
			cout << "队满！";
		}
		p[rear] = e;
		rear = (rear + 1) % size;
	}
	bool isEmpty() {
		if (rear == front) {
			return true;
		}
		return false;
	}
	int length() {
		return size;
	}
};