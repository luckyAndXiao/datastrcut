#include<iostream>
#include"LinkList.h"
#include"algorithm.h"
#define  INFINITY   100
using namespace std;

void SelectSort_Test(void) {

	LinkList L;

	LinkListInit(L);
	cout << "β�巨��������999��Ϊ��ֹ���ţ�\n";
	LinkList_TailInsert(L);
	cout << "����ǰ�������ݣ�\n";
	LinkList_Display(L);
	cout << "\n��ѡ��������������\n";
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