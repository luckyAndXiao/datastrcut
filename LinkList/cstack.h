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

	T  Top();//ȡջ��Ԫ��

	int getCount();//��ȡջ��Ԫ�ظ���

	int  StackFull() {
		//�ж�ջ�Ƿ�����
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
		cout << "ջ�գ��޷�ȡջ����\n";
		exit(1);
	}
	x = base[top];

	return x;
}

template<class T>
SqStack<T>::SqStack(int max)//˳��ջ��ʼ��
{

	base = new T[max];

	if (base == NULL)
	{
		cerr << "ջ����ʧ�ܣ��˳�\n";

		exit(1);
	}

	stackSize = max;

	top = -1;

}


template<class T>

void SqStack<T>::Push(T x)//˳��ջ��ջ
{
	if (top == stackSize-1) {
		cerr << "ջ�����޷���ջ\n ";
		exit(1);
	}

	base[++top] = x;

}

template<class T>
T SqStack<T>::Pop(void)//˳��ջ��ջ
{
	if (top == -1) {
		cerr << "ջ�գ��޷���ջ \n";
		exit(1);
	}
	return base[top--];

}


