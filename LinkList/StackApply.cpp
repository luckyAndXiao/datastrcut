#include<iostream>
#include"cstack.h"
using namespace std;
/*
ջ��Ӧ��
1�����ʽ��ֵ
2��ǰ�к�׺���ʽ��ת��
*/

//��������ȼ��Ƚ�
char  Precede(char pre_op, char ch) {
	int isp = 0;
	int icp = 0;
	
	//��ǰ��������ȼ��İ���
	switch (ch) {

	case '+':icp = 2; break;
	case '-':icp = 2; break;
	case '*':icp = 5; break;
	case '/':icp = 5; break;
	case '(':icp = 6; break;
	case ')':icp = 1; break;
	case '@':icp = 0; break;

	}
	//ջ�����ȼ��İ���
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
//������������
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
//������ʽ��ֵ
float  Expression_Eval() {
	float  result = 0;
	char ch = '\0';
	char pre_op = '\0';
	float a, b;
	SqStack<float> OPND(100);//������ջ
	SqStack<char> OPTR(100);//������ջ
	//��������ջ
	OPTR.Push('@');
	
	ch = getchar();

	while (ch != '@'|| OPTR.Top()!='@') {
		//����ǲ���������ջ
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
	cout << "������׺���ʽ���м��㣺\n";
	result = Expression_Eval();
	cout << " = " << result << endl;
	return 0;
}