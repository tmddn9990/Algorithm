#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

int stack[50]; //���� ���� �迭
int stackTop; //������ �Է� ��

void initStack()//�ʱ�ȭ
{
	stackTop = -1;
}

int popStack()//���ÿ��� ����
{
	if (stackTop < 0)
	{
		cout << "����";
		return 1;
	}
	else
		return stack[stackTop--];
}

int pushStack(int item)//�������� ����
{
	if (stackTop >= 50 - 1)
	{
		cout << "����";
		return 1;
	}
	else
		stack[++stackTop] = item;
	return item;

}

int getStackTop()//������ �ֻ��� ���� ȣ��
{
	if (stackTop < 0)
		return -1;
	else
		return stack[stackTop];
}

bool isEmpty()//������ ����ִ��� Ȯ��
{
	return (stackTop < 0);
}

bool isOperator(int op)//�����ȣ������ ���� ���Լ�
{
	return op == '+' || op == '-' || op == '*' || op == '/';

}
int precedence(int op)//�����ȣ�� ���� �켱���� ����
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

void postChange(char *dst, char *src)  //dst������ȸ src������ȸ ������ȸ�� ������ȸ�� �ٲٴ� �Լ� ����
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
	cout << "���� ��ȸ->������ȸ" << endl;
	cout << "������ȸ ����" << endl << endl;
	int testNum;
	cin >> testNum;
	for (int i = 0; i < testNum; i++) {
		cin >> infix;
		cout << "#" << i + 1 << " ";
		cout << "������ȸ��" << infix << endl;
		postChange(postfix, infix);
		cout << "������ȸ��" << postfix << endl << endl;

	}
	return;
}