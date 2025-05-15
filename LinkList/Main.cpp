#include<iostream>
#include"LinkList.h"
#include"algorithm.h"
#define  INFINITY   100
using namespace std;

void SelectSort_Test(void) {

	LinkList L;

	LinkListInit(L);
	cout << "尾插法建立链表，999作为终止符号：\n";
	LinkList_TailInsert(L);
	cout << "排序前链表内容：\n";
	LinkList_Display(L);
	cout << "\n简单选择对链表进行排序：\n";
	SelectSort(L);
	LinkList_Display(L);
	LinkList_Destory(L);


}

int main(void) {

	LNode a;
	a.data = 3;
	a.next = NULL;
	LNode* p = &a;
	cout << (*p).data<<endl;
	cout << p->data << endl;
	return 0;
}