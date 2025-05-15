#pragma once
#include<iostream>
#define MaxSize 50
using namespace std;
//ѭ������
struct SqQuene {
	int data[MaxSize];//��Ŷ���Ԫ��
	int front, rear;//��ͷ��βָ��
};
//��ʼ������
void InitSqQuene(SqQuene& q) {
	q.front = q.rear = 0;
}
//�ж϶ӿ�
bool isEmpty(SqQuene q) {
	if (q.front == q.rear) {
		return true;
	}
	return false;
}
//���
bool EnSqQuene(SqQuene& q, int x) {
	int rear = (q.rear + 1) % MaxSize;
	//�ж�ջ��
	if (rear == q.front) {
		return false;
	}
	q.data[q.rear] = x;
	q.rear = rear;

	return true;
}
//����
bool DeSqQuene(SqQuene &q , int &x) {
	//�ж϶ӿ�
	if (isEmpty(q)) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;

	return true;
}
//��ӳ�
bool QueneLength(SqQuene q) {
	
	int length = (q.rear - q.front + MaxSize) % MaxSize;

	return length;
}
