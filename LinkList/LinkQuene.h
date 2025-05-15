#pragma on
#include<iostream>
using namespace std;
//链队结点
struct QNode {
	int data;
	QNode* next;
};
//队尾，队头指针
struct LinkQuene {
	QNode* front, * rear;
};

//初始化链队
void  InitLinkQuene(LinkQuene &q) {
	q.front = q.rear = NULL;
}
//判断队空
bool LinkQueneEmpty(LinkQuene q) {
	if (q.rear==NULL && q.front==NULL) {
		return true;
	}
	return false;
}
//销毁队列
void  DestoryLinkQuene(LinkQuene q) {
	QNode* p = NULL;
	while (q.front) {
		p = q.front;
		q.front = q.front->next;
		delete p;
	}
}
//入队
bool EnLinkQuene(LinkQuene& q , int x) {
	//初始化新结点
	QNode* newNode = new QNode();
	newNode->data = x;
	newNode->next = NULL;
	//判断栈是否为空
	if (LinkQueneEmpty(q) ){
		q.front = q.rear = newNode;
	}
	else {
		q.rear->next = newNode;
		q.rear = newNode;
	}

	return true;
}
//出队
bool  DeLinkQuene(LinkQuene & q, int& x) {
	QNode* p = NULL;
	if ( LinkQueneEmpty(q)) {//栈空
		return false;
	 }
	x = q.front->data;
	p = q.front;

	if (q.front == q.rear) {//只有一个元素时		
		q.front = q.rear = NULL;
	}
	else {
		q.front = q.front->next;
	}	
	delete p;
	return true;
}