#pragma once
#include<iostream>
using namespace std;
template< class T>
class  SqStack {

private:
	T * base;

	int top;

	int stackSize;
public:
	SqStack(int m);

	SqStack() {

	}

	~SqStack()

	{
		delete[]base; top = -1;

		stackSize = 0;
	}

	void Push(T x);

	T Pop();

	int StackEmpty()
	{
		if (top == -1) {

			return 1;
		}
		return 0;
	}

	T  Top();//取栈顶元素

	int getCount();//获取栈内元素个数

	int  StackFull() {
		//判断栈是否满了
		if (top == stackSize-1) {
			return 1;
		}

		return 0;
	}
};

template<class T>

int  SqStack<T>::getCount() {

	return top;
}

template<class T>

T   SqStack<T>::Top() {
	T x;
	if (top == -1) {
		cout << "栈空，无法取栈顶！\n";
		exit(1);
	}
	x = base[top];

	return x;
}

template<class T>
SqStack<T>::SqStack(int max)//顺序栈初始化
{

	base = new T[max];

	if (base == NULL)
	{
		cerr << "栈创建失败！退出\n";

		exit(1);
	}

	stackSize = max;

	top = -1;

}


template<class T>

void SqStack<T>::Push(T x)//顺序栈入栈
{
	if (top == stackSize-1) {
		cerr << "栈满，无法入栈\n ";
		exit(1);
	}

	base[++top] = x;

}

template<class T>
T SqStack<T>::Pop(void)//顺序栈出栈
{
	if (top == -1) {
		cerr << "栈空，无法出栈 \n";
		exit(1);
	}
	return base[top--];

}


