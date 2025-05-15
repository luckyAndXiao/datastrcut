#pragma once
#include <iostream>
using namespace std;
//��ջ���
struct SNode {
	int data;//��Ž��Ԫ��
	SNode * next;
};

typedef SNode*   LiStack;

//����ͷ���
void InitLiStack(LiStack& s) {
	s = NULL;//��ջ
}
//�ж�ջ�Ƿ�Ϊ��
bool LiStackEmpty(LiStack s) {
	if (s == NULL) {
		return true;
	}

	return false;
}
//��ջ
bool LiPush(LiStack & s, int x) {
	SNode* newNode = NULL;
	
		newNode = new SNode();
		newNode->data = x;
		//��ջ
		newNode->next = s;
		s = newNode;
	
	return true;
}
bool LiPop(LiStack & s, int& x) {
	SNode* p = NULL;
	if (s==NULL) {
		//�ж��Ƿ�ջ��
		return false;
	}
	x = s->data;
	p = s;
	s = s->next;
	delete p;

	return true;

}
//ȡջ��Ԫ��
bool GetTop(LiStack s, int& x) {
	if (s == NULL) {
		return false;
	}
	x = s->data;

	return true;
}
//����ջ
void DestoryLiStack(LiStack& s) {
	SNode* p = NULL;
	while (s != NULL) {
		p = s;
		s = s->next;
		delete p;
	 }
}
