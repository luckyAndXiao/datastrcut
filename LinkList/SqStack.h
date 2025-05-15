#pragma once
#include<iostream>
using namespace std;

#define  MaxSize 50 //�궨��ջ���������
//˳��ջ
struct  SqStack {
	int  data[MaxSize];//���ջ��Ԫ��
	int top;//ջ��
};
//��ʼ��ջ
void InitStack(SqStack& s) {
	s.top = -1;//��ջ
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack s) {
	if (s.top == -1) {
		return true;
	}

	return false;
}
//��ջ
bool Push(SqStack& s, int x) {
	if (s.top == MaxSize-1) {//�ж��Ƿ�ջ��
		return false;
	 }
	s.data[++s.top] = x;
	return true;
}
bool Pop(SqStack& s , int &x) {
	if (s.top == -1) {
		//�ж��Ƿ�ջ��
		return false;
	}

	x = s.data[s.top--];

	return true;

}
//ȡջ��Ԫ��
bool GetTop(SqStack s, int& x) {
	if (s.top == -1) {
		return false;
	}
	x = s.data[s.top];

	return true;
}
//����ջ
void DestoryStack(SqStack& s) {
	for (int i = 0; i <= s.top; i++) {
		s.data[i] = 0;
	}
	s.top = -1;
}
