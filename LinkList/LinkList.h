#pragma once
#include<iostream>
using namespace std;
#define  Pause  999
//using namespace std;
//链表结点
 struct LNode{
	int data;//数据
	LNode * next;//指针
};
 //重命名
 typedef  LNode* LinkList;

//带头结点单链表初始化
void  LinkListInit(LinkList & L) {
	L = new LNode();//分配头结点
    L->next = NULL;//指针为空
}
//头插法建立链表
LinkList LinkList_HeadInsert(LinkList & L) {
	LNode * p = L;
	LNode* newNode;
	int data = 0;
	cin >> data;
	
	while (data != Pause) {
		
		newNode = new LNode();


		newNode->data = data;
		//头插法
		newNode->next = p->next;
		p->next = newNode;
		cin >> data;

	}
	return L;

}

//尾插法建立链表
LinkList  LinkList_TailInsert(LinkList & L) {
	LNode * p = L;
	LNode * newNode = NULL;
	int data = 0;
	cin >> data;
	while (data != Pause) {
		newNode = new LNode();
		newNode->data = data;
		newNode->next = NULL;

		 p->next = newNode;
		 p = newNode;

		 cin >> data;

	}

	return L;
}

//销毁链表

void  LinkList_Destory(LinkList & L) {
	LNode * p = NULL;
	while (L->next!= NULL) {
		p = L;
		L = L->next;
		delete p;
	}
	delete L;
	L = NULL;
}

//查询链表(按位查找）

LNode * LinkList_Search(LinkList L, int i) {
	
	LNode * p = L;
	int j = 0;

	for (j = 0; j < i; j++) {
		if (p->next != NULL) {
			p = p->next;
		}
		else {
			break;
		}
	}
	if (j == i) {
		return p;
	}
	return NULL;
}

//尾插
bool  LinkList_TailInsert(LinkList & L , int i , int e) {
	LNode* p, * newNode;
	p = LinkList_Search(L, i - 1);
	if(p){
		newNode = new LNode();
		newNode->data = e;
		newNode->next = p->next;
		p->next = newNode;
	}
	else {
		return false;
	}
	return true;
	
}

//链表指定结点前插操作

bool  LinkList_PreInsert(LNode * node, int e) {
	//采用交换数据的方法
	if (node == NULL) {
		return false;
	}
	LNode* newNode = new LNode();;
	newNode->data = e;
	//插入结点
	newNode->next = node->next;
	node->next = newNode;
	//交换数据
	node->data = node->data + newNode->data;
	newNode->data = node->data - newNode->data;
	node->data = node->data - newNode->data;

	return true;
}

//按值查找

int  LinkList_LocateElem(LinkList  L, int value) {
	int i = 0;
	
	while (L) {
		if ( i && L->data == value) {
			break;
		}
		L = L->next;
		i++;
	}
	if (!L) {
		i = 0;
	}
	return i;
}

//打印链表
void LinkList_Display(LinkList L) {
	L = L->next;
	while (L) {
		cout << L->data << " ";
		L = L->next;
	}

}

//求表长
int  LinkList_Length(LinkList L) {
	int length = 0; 
	while (L) {
		length++;
		L = L->next;
	}
	return length - 1;
}
//链表的升序排序
//按节点排序
bool LinkList_LNodeSort(LinkList  &L) {
	LinkList  list;
	LNode * min = NULL , *p = NULL ,* q = NULL,*premin = NULL;
	//建立一个新链表
	LinkListInit(list);
	//判断链表是否为空
	if (L->next == NULL) {
		return false;
	}
	//对表进行排序
	while (L->next) {
		//遍历寻找最小结点
		premin = L;//premin存放min的上一个结点的指针
		q = min = L->next;//q存放遍历结点的上一个结点,	
		p = min->next;//用于遍历的指针
		while (p) {	
			if (min->data < p->data) {
				premin = q;
				min = p;
				}
			q = p;
			p = p->next;

		}
		//从原来的链表中删除最小的元素
			premin->next = min->next;
		
		//将元素头插法插入新的排序表
		min->next = list->next;
		list->next = min;
	
	}
	//销毁旧的表
	LinkList_Destory(L);
	L = list;
	return false;
}
//尾插法
void  TailInsert(LNode* p1 , LNode * p) {
	while (p1) {
		LNode * newNode = new LNode();
		newNode->data = p1->data;
		p1 = p1->next;
		//尾插法
		newNode->next = p->next;
		p->next = newNode;
		p = newNode;
	}


}
//链表的简单选择排序

void   SelectSort(LinkList & L) {
	     
	LNode* head = L->next;

	LNode* move = NULL;

	LNode* min = NULL;

	if (head == NULL) {
		return ;
	}
	for (; head!= NULL; head = head->next) {
		min = head;
		for (move = head->next; move != NULL; move = move->next) {//找最小
			if (min->data > move->data) {
				min = move;
			 }
		}
		if (min != head) {//交换结点值，不交换结点指针
			int var = min->data;
			min->data = head->data;
			head->data = var;
		}


	}

}







//两个升序链表的合并
LinkList  LinkList_Combine(LinkList L1, LinkList L2) {
	int data = 0;
	
	LinkList L = NULL;//合成的新表
	LNode* p1 = L1->next;//用于遍历L1
	LNode* p2 = L2->next;//用于遍历L2
	LNode* newNode = NULL;
	LinkListInit(L);
	LNode* p = L;

	while (p1 && p2) {
		if (p1->data > p2->data) {
			data = p2->data;
			p2 = p2->next;
		}
		else {
			data = p1->data;
			p1 = p1->next;
		}
		newNode = new LNode();
		newNode->data = data;
		//尾插法
		newNode->next = p->next;
		p->next = newNode;
		p = newNode;
	}
	if (p1) {
		TailInsert(p1, p);
	}
	if (p2) {
		TailInsert(p2, p);
	}

	return L;
}