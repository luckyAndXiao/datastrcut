#pragma once
#include <iostream>
using namespace std;
//链栈结点
struct SNode {
	int data;//存放结点元素
	SNode * next;
};

typedef SNode*   LiStack;

//不带头结点
void InitLiStack(LiStack& s) {
	s = NULL;//空栈
}
//判断栈是否为空
bool LiStackEmpty(LiStack s) {
	if (s == NULL) {
		return true;
	}

	return false;
}
//进栈
bool LiPush(LiStack & s, int x) {
	SNode* newNode = NULL;
	
		newNode = new SNode();
		newNode->data = x;
		//入栈
		newNode->next = s;
		s = newNode;
	
	return true;
}
bool LiPop(LiStack & s, int& x) {
	SNode* p = NULL;
	if (s==NULL) {
		//判断是否栈空
		return false;
	}
	x = s->data;
	p = s;
	s = s->next;
	delete p;

	return true;

}
//取栈顶元素
bool GetTop(LiStack s, int& x) {
	if (s == NULL) {
		return false;
	}
	x = s->data;

	return true;
}
//销毁栈
void DestoryLiStack(LiStack& s) {
	SNode* p = NULL;
	while (s != NULL) {
		p = s;
		s = s->next;
		delete p;
	 }
}
