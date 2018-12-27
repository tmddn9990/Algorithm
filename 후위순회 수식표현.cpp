#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

int stack[50]; //수식 저장 배열
int stackTop; //마지막 입력 값

void initStack()//초기화
{
	stackTop = -1;
}

int popStack()//스택에서 삭제
{
	if (stackTop < 0)
	{
		cout << "오류";
		return 1;
	}
	else
		return stack[stackTop--];
}

int pushStack(int item)//스택으로 삽입
{
	if (stackTop >= 50 - 1)
	{
		cout << "오류";
		return 1;
	}
	else
		stack[++stackTop] = item;
	return item;

}

int getStackTop()//스택의 최상위 원소 호출
{
	if (stackTop < 0)
		return -1;
	else
		return stack[stackTop];
}

bool isEmpty()//스택이 비어있는지 확인
{
	return (stackTop < 0);
}

bool isOperator(int op)//연산기호인지에 대한 불함수
{
	return op == '+' || op == '-' || op == '*' || op == '/';

}
int precedence(int op)//연산기호에 대한 우선순위 결정
{
	switch (op)
	{
	case'(':
		return 0;
		break;
	case'+':
	case'-':
		return 1;
		break;
	case'*':
	case'/':
		return 2;
		break;
	default:
		return 3;
		break;


	}

}

void postChange(char *dst, char *src)  //dst후위순회 src중위순회 중위순회를 후위순회로 바꾸는 함수 정의
{
	initStack();
	while (*src)
	{
		if (*src == '(')
		{
			pushStack(*src);
			src++;
		}
		else if (*src == ')')
		{
			while (getStackTop() != '(')
			{
				*dst++ = popStack();
				*dst++ = ' ';
			}
			popStack();
			src++;
		}
		else if (isOperator(*src))
		{
			while (!isEmpty() && precedence(getStackTop()) >= precedence(*src))
			{
				*dst++ = popStack();
				*dst++ = ' ';
			}
			pushStack(*src);
			src++;
		}
		else if (*src >= '0' && *src <= '9')
		{
			do
			{
				*dst = *src;
				dst++;
				src++;
			} while (*src >= '0'&&*src <= '9');
			*dst++ = ' ';

		}
		else
			src++;
	}
	while (!isEmpty())
	{
		*dst++ = popStack();
		*dst++ = ' ';
	}
	dst--;
	*dst = 0;
}
void main()
{
	freopen("input.txt", "r", stdin);
	char postfix[256], infix[256];
	cout << "중위 순회->후위순회" << endl;
	cout << "중위순회 수식" << endl << endl;
	int testNum;
	cin >> testNum;
	for (int i = 0; i < testNum; i++) {
		cin >> infix;
		cout << "#" << i + 1 << " ";
		cout << "중위순회식" << infix << endl;
		postChange(postfix, infix);
		cout << "후위순회식" << postfix << endl << endl;

	}
	return;
}