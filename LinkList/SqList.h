#pragma once
#include<iostream>
#define  Maxsize  20
using namespace std;

 struct SqList {
	int data[Maxsize];//˳�������
	int length;//˳�����
};

//��ʼ��˳���

void  ListInit(SqList& L) {
	for (int i = 0; i < Maxsize; i++) {
		L.data[i] = 0;//��ʼ��˳�����ֵΪ0
	}
	L.length = 0;//��Ϊ0
}
//��˳����а�λ����Ԫ��
bool  ListInsert(SqList& L, int i, int e) {
	//�ж�λ�úϷ���
	if (i > L.length + 1 || i < 0) {
		return false;
	}
	if (L.length + 1 > Maxsize) {//�ﵽ�������
		return false;
	}
    //����Ԫ��
	for (int j = L.length; j >= i; j--) {//Ԫ�غ���
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//ɾ��˳����е�Ԫ��
bool  ListDelete(SqList& L, int i , int & e) {
	//�ж�λ�úϷ���
	if (i < 0 && i > L.length) {
		return false;
	}
	//ɾ��Ԫ��
	e = L.data[i - 1];

	for (int  j = i - 1; j < L.length; j++) {
		L.data[j] = L.data[j + 1];
	}
	L.length--;

	return true;
}

//�޸�˳����е�Ԫ��
bool  ListModi(SqList & L, int i , int e) {

	if (i < 0 && i > L.length) {
		return false;
	}
	L.data[i - 1] = e;
	return true;
}

//��λ����

int  ListSearch(SqList L, int i) {
	if (i < 0 && i > L.length) {
		return -1;
	}
	return L.data[i - 1];
}
//��ֵ����

int  LocateElem(SqList L, int e) {

	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		  }
	  }
	return 0;
}

//��ӡ˳���
void  ListDisplay(SqList L) {
	
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}

}

//����

void  ListSort(SqList& L) {
//ð������
	int i, j, k;
	for ( i = 0; i < L.length; i++) {
		k = 1;//��־λ
		for (j = 0; j < L.length - i - 1; j++) {
			
			if (L.data[j] > L.data[j + 1]) {
				k = 0;
				//���ݽ���
				L.data[j] = L.data[j] + L.data[j + 1];
				L.data[j + 1] = L.data[j] - L.data[j + 1];
				L.data[j] = L.data[j] - L.data[j + 1];
			}
			if (k) {
				break;
			}
		}
	}

}

//˳���Ķ��ֲ��ҷ�
int  ListHalfSearch(SqList L , int e) {
	int front = 0;
	int rear = L.length - 1;
	int mid = (front + rear) / 2;
	while (front <= rear) {
		if (L.data[mid] == e) {
			return mid + 1;
		}
		else if (L.data[mid] < e) {
			front = mid + 1;
			
		}
		else {
			rear = mid - 1;
		}

		mid = (front + rear) / 2;
	}

	return  0;

}