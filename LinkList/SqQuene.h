#pragma once
#include<iostream>
#define MaxSize 50
using namespace std;
//循环队列
struct SqQuene {
	int data[MaxSize];//存放队中元素
	int front, rear;//队头队尾指针
};
//初始化队列
void InitSqQuene(SqQuene& q) {
	q.front = q.rear = 0;
}
//判断队空
bool isEmpty(SqQuene q) {
	if (q.front == q.rear) {
		return true;
	}
	return false;
}
//入队
bool EnSqQuene(SqQuene& q, int x) {
	int rear = (q.rear + 1) % MaxSize;
	//判断栈满
	if (rear == q.front) {
		return false;
	}
	q.data[q.rear] = x;
	q.rear = rear;

	return true;
}
//出队
bool DeSqQuene(SqQuene &q , int &x) {
	//判断队空
	if (isEmpty(q)) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;

	return true;
}
//求队长
bool QueneLength(SqQuene q) {
	
	int length = (q.rear - q.front + MaxSize) % MaxSize;

	return length;
}
