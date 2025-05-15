#include<iostream>
#include"cstack.h"
using namespace std;
/*
栈的应用
1、表达式求值
2、前中后缀表达式的转换
*/

//运算符优先级比较
char  Precede(char pre_op, char ch) {
	int isp = 0;
	int icp = 0;
	
	//当前运算符优先级的安排
	switch (ch) {

	case '+':icp = 2; break;
	case '-':icp = 2; break;
	case '*':icp = 5; break;
	case '/':icp = 5; break;
	case '(':icp = 6; break;
	case ')':icp = 1; break;
	case '@':icp = 0; break;

	}
	//栈内优先级的安排
	switch (pre_op) {

	case '+':isp = 3; break;
	case '-':isp = 3; break;
	case '*':isp = 4; break;
	case '/':isp = 4; break;
	case '(':isp = 1; break;
	case ')':isp = 7; break;
	case '@':isp = 0; break;

	}

	if (isp < icp) {
		return '<';
	}
	else if (isp > icp) {
		return '>';
	}
	
		
	return '=';
	
}
//两个数的运算
float Operate(float a, char op, float b) {
	float r = 0;
	switch (op) {
	case '+':r = a + b; break;
	case '-':r = a - b; break;
	case '*':r = a * b; break;
	case '/':r = a / b; break;
	}
	return r;
}
//输入表达式求值
float  Expression_Eval() {
	float  result = 0;
	char ch = '\0';
	char pre_op = '\0';
	float a, b;
	SqStack<float> OPND(100);//操作数栈
	SqStack<char> OPTR(100);//操作符栈
	//结束符入栈
	OPTR.Push('@');
	
	ch = getchar();

	while (ch != '@'|| OPTR.Top()!='@') {
		//如果是操作数则入栈
		if (ch >= '0' && ch <= '9') {
			OPND.Push(ch-'0');
			ch = getchar();
		   }
		else {
			pre_op = OPTR.Top();
			switch (Precede(pre_op, ch)) {

			case '<':
				OPTR.Push(ch);
				ch = getchar();
				break;
			case '=':
				OPTR.Pop();
				ch = getchar();
				break;
			case '>':
				b = OPND.Pop();
				a = OPND.Pop();
				pre_op = OPTR.Pop();
				OPND.Push(Operate(a, pre_op, b));
				break;
			}
		}


	}
	result = OPND.Top();
	
	return  result;
}

void  Infix_toSuffix() {
	int ch;
	int pre_op;
	SqStack<char> optr(100);
	optr.Push('@');
	ch = getchar();
	while (ch != '@') {

		if (ch >= '0' && ch <= '9') {
			cout << ch;
		}
		else {
			pre_op = optr.Top();
			switch (Precede(pre_op , ch)) {

			case '<':
				cout << ch;
				break;
			case '=':
				optr.Pop();
				break;
			case '>':
				
				break;

			}
			ch = getchar();

		}




	}



}


int main(void) {
	int result = 0;
	cout << "输入中缀表达式进行计算：\n";
	result = Expression_Eval();
	cout << " = " << result << endl;
	return 0;
}