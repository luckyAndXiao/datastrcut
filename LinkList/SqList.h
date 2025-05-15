#pragma once
#include<iostream>
#define  Maxsize  20
using namespace std;

 struct SqList {
	int data[Maxsize];//顺序表容量
	int length;//顺序表长度
};

//初始化顺序表

void  ListInit(SqList& L) {
	for (int i = 0; i < Maxsize; i++) {
		L.data[i] = 0;//初始化顺序表结点值为0
	}
	L.length = 0;//表长为0
}
//向顺序表中按位插入元素
bool  ListInsert(SqList& L, int i, int e) {
	//判断位置合法性
	if (i > L.length + 1 || i < 0) {
		return false;
	}
	if (L.length + 1 > Maxsize) {//达到最大容量
		return false;
	}
    //插入元素
	for (int j = L.length; j >= i; j--) {//元素后移
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

//删除顺序表中的元素
bool  ListDelete(SqList& L, int i , int & e) {
	//判断位置合法性
	if (i < 0 && i > L.length) {
		return false;
	}
	//删除元素
	e = L.data[i - 1];

	for (int  j = i - 1; j < L.length; j++) {
		L.data[j] = L.data[j + 1];
	}
	L.length--;

	return true;
}

//修改顺序表中的元素
bool  ListModi(SqList & L, int i , int e) {

	if (i < 0 && i > L.length) {
		return false;
	}
	L.data[i - 1] = e;
	return true;
}

//按位查找

int  ListSearch(SqList L, int i) {
	if (i < 0 && i > L.length) {
		return -1;
	}
	return L.data[i - 1];
}
//按值查找

int  LocateElem(SqList L, int e) {

	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		  }
	  }
	return 0;
}

//打印顺序表
void  ListDisplay(SqList L) {
	
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}

}

//排序

void  ListSort(SqList& L) {
//冒泡排序
	int i, j, k;
	for ( i = 0; i < L.length; i++) {
		k = 1;//标志位
		for (j = 0; j < L.length - i - 1; j++) {
			
			if (L.data[j] > L.data[j + 1]) {
				k = 0;
				//数据交换
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

//顺序表的二分查找法
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