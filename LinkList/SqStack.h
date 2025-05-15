#pragma once
#include<iostream>
using namespace std;

#define  MaxSize 50 //宏定义栈的最大容量
//顺序栈
struct  SqStack {
	int  data[MaxSize];//存放栈中元素
	int top;//栈顶
};
//初始化栈
void InitStack(SqStack& s) {
	s.top = -1;//空栈
}
//判断栈是否为空
bool StackEmpty(SqStack s) {
	if (s.top == -1) {
		return true;
	}

	return false;
}
//进栈
bool Push(SqStack& s, int x) {
	if (s.top == MaxSize-1) {//判断是否栈满
		return false;
	 }
	s.data[++s.top] = x;
	return true;
}
bool Pop(SqStack& s , int &x) {
	if (s.top == -1) {
		//判断是否栈空
		return false;
	}

	x = s.data[s.top--];

	return true;

}
//取栈顶元素
bool GetTop(SqStack s, int& x) {
	if (s.top == -1) {
		return false;
	}
	x = s.data[s.top];

	return true;
}
//销毁栈
void DestoryStack(SqStack& s) {
	for (int i = 0; i <= s.top; i++) {
		s.data[i] = 0;
	}
	s.top = -1;
}
