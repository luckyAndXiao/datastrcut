#pragma once
#include<iostream>
using namespace std;
#define  Pause  999
//using namespace std;
//������
 struct LNode{
	int data;//����
	LNode * next;//ָ��
};
 //������
 typedef  LNode* LinkList;

//��ͷ��㵥�����ʼ��
void  LinkListInit(LinkList & L) {
	L = new LNode();//����ͷ���
    L->next = NULL;//ָ��Ϊ��
}
//ͷ�巨��������
LinkList LinkList_HeadInsert(LinkList & L) {
	LNode * p = L;
	LNode* newNode;
	int data = 0;
	cin >> data;
	
	while (data != Pause) {
		
		newNode = new LNode();


		newNode->data = data;
		//ͷ�巨
		newNode->next = p->next;
		p->next = newNode;
		cin >> data;

	}
	return L;

}

//β�巨��������
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

//��������

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

//��ѯ����(��λ���ң�

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

//β��
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

//����ָ�����ǰ�����

bool  LinkList_PreInsert(LNode * node, int e) {
	//���ý������ݵķ���
	if (node == NULL) {
		return false;
	}
	LNode* newNode = new LNode();;
	newNode->data = e;
	//������
	newNode->next = node->next;
	node->next = newNode;
	//��������
	node->data = node->data + newNode->data;
	newNode->data = node->data - newNode->data;
	node->data = node->data - newNode->data;

	return true;
}

//��ֵ����

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

//��ӡ����
void LinkList_Display(LinkList L) {
	L = L->next;
	while (L) {
		cout << L->data << " ";
		L = L->next;
	}

}

//���
int  LinkList_Length(LinkList L) {
	int length = 0; 
	while (L) {
		length++;
		L = L->next;
	}
	return length - 1;
}
//�������������
//���ڵ�����
bool LinkList_LNodeSort(LinkList  &L) {
	LinkList  list;
	LNode * min = NULL , *p = NULL ,* q = NULL,*premin = NULL;
	//����һ��������
	LinkListInit(list);
	//�ж������Ƿ�Ϊ��
	if (L->next == NULL) {
		return false;
	}
	//�Ա��������
	while (L->next) {
		//����Ѱ����С���
		premin = L;//premin���min����һ������ָ��
		q = min = L->next;//q��ű���������һ�����,	
		p = min->next;//���ڱ�����ָ��
		while (p) {	
			if (min->data < p->data) {
				premin = q;
				min = p;
				}
			q = p;
			p = p->next;

		}
		//��ԭ����������ɾ����С��Ԫ��
			premin->next = min->next;
		
		//��Ԫ��ͷ�巨�����µ������
		min->next = list->next;
		list->next = min;
	
	}
	//���پɵı�
	LinkList_Destory(L);
	L = list;
	return false;
}
//β�巨
void  TailInsert(LNode* p1 , LNode * p) {
	while (p1) {
		LNode * newNode = new LNode();
		newNode->data = p1->data;
		p1 = p1->next;
		//β�巨
		newNode->next = p->next;
		p->next = newNode;
		p = newNode;
	}


}
//����ļ�ѡ������

void   SelectSort(LinkList & L) {
	     
	LNode* head = L->next;

	LNode* move = NULL;

	LNode* min = NULL;

	if (head == NULL) {
		return ;
	}
	for (; head!= NULL; head = head->next) {
		min = head;
		for (move = head->next; move != NULL; move = move->next) {//����С
			if (min->data > move->data) {
				min = move;
			 }
		}
		if (min != head) {//�������ֵ�����������ָ��
			int var = min->data;
			min->data = head->data;
			head->data = var;
		}


	}

}







//������������ĺϲ�
LinkList  LinkList_Combine(LinkList L1, LinkList L2) {
	int data = 0;
	
	LinkList L = NULL;//�ϳɵ��±�
	LNode* p1 = L1->next;//���ڱ���L1
	LNode* p2 = L2->next;//���ڱ���L2
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
		//β�巨
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