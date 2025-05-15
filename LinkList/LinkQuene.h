#pragma on
#include<iostream>
using namespace std;
//���ӽ��
struct QNode {
	int data;
	QNode* next;
};
//��β����ͷָ��
struct LinkQuene {
	QNode* front, * rear;
};

//��ʼ������
void  InitLinkQuene(LinkQuene &q) {
	q.front = q.rear = NULL;
}
//�ж϶ӿ�
bool LinkQueneEmpty(LinkQuene q) {
	if (q.rear==NULL && q.front==NULL) {
		return true;
	}
	return false;
}
//���ٶ���
void  DestoryLinkQuene(LinkQuene q) {
	QNode* p = NULL;
	while (q.front) {
		p = q.front;
		q.front = q.front->next;
		delete p;
	}
}
//���
bool EnLinkQuene(LinkQuene& q , int x) {
	//��ʼ���½��
	QNode* newNode = new QNode();
	newNode->data = x;
	newNode->next = NULL;
	//�ж�ջ�Ƿ�Ϊ��
	if (LinkQueneEmpty(q) ){
		q.front = q.rear = newNode;
	}
	else {
		q.rear->next = newNode;
		q.rear = newNode;
	}

	return true;
}
//����
bool  DeLinkQuene(LinkQuene & q, int& x) {
	QNode* p = NULL;
	if ( LinkQueneEmpty(q)) {//ջ��
		return false;
	 }
	x = q.front->data;
	p = q.front;

	if (q.front == q.rear) {//ֻ��һ��Ԫ��ʱ		
		q.front = q.rear = NULL;
	}
	else {
		q.front = q.front->next;
	}	
	delete p;
	return true;
}