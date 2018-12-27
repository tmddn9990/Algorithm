#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int get(int i, int j, char** board, int num) //���� üũ�Լ�
{
	if (i < 0 || i >= num || j >= num)
		return 0;
	return 1;
}
int matrix(char **board, int num) // ���� ���� ��� 
{
	int i, j;
	int k = 0;
	int remainder = 0; //��ĭ�� ��

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			switch (board[i][j])
			{
			case'C':  // C�� ���� ������ŭ 1�� ��ȯ
				if (get(i - 3, j, board, num) == 1 && board[i - 3][j] == '0')
					board[i - 3][j] = '1';
				if (get(i, j - 3, board, num) == 1 && board[i][j - 3] == '0')
					board[i][j - 3] = '1';
				if (get(i + 3, j, board, num) == 1 && board[i + 3][i] == '0')
					board[i + 3][i] = '1';
				if (get(i, j + 3, board, num) == 1 && board[i][j + 3] == '0')
					board[i][j + 3] = '1';
				if (get(i - 3, j - 3, board, num) == 1 && board[i - 3][j - 3] == '0')
					board[i - 3][j - 3] = '1';
				if (get(i - 3, j + 3, board, num) == 1 && board[i - 3][j + 3] == '0')
					board[i - 3][j + 3] = '1';
				if (get(i + 3, j - 3, board, num) == 1 && board[i + 3][j - 3] == '0')
					board[i + 3][j - 3] = '1';
				if (get(i + 3, j + 3, board, num) == 1 && board[i + 3][j + 3] == '0')
					board[i + 3][j + 3] = '1';

			case'B': // B�� ���� ������ŭ 1�� ��ȯ
				if (get(i - 2, j, board, num) == 1 && board[i - 2][j] == '0')
					board[i - 2][j] = '1';
				if (get(i, j - 2, board, num) == 1 && board[i][j - 2] == '0')
					board[i][j - 2] = '1';
				if (get(i + 2, j, board, num) == 1 && board[i + 2][i] == '0')
					board[i + 2][i] = '1';
				if (get(i, j + 2, board, num) == 1 && board[i][j + 2] == '0')
					board[i][j + 2] = '1';
				if (get(i - 2, j - 2, board, num) == 1 && board[i - 2][j - 2] == '0')
					board[i - 2][j - 2] = '1';
				if (get(i - 2, j + 2, board, num) == 1 && board[i - 2][j + 2] == '0')
					board[i - 2][j + 2] = '1';
				if (get(i + 2, j - 2, board, num) == 1 && board[i + 2][j - 2] == '0')
					board[i + 2][j - 2] = '1';
				if (get(i + 2, j + 2, board, num) == 1 && board[i + 2][j + 2] == '0')
					board[i + 2][j + 2] = '1';

			case'A': // A�� ���� ������ŭ 1�� ��ȯ
				if (get(i - 1, j, board, num) == 1 && board[i - 1][j] == '0')
					board[i - 1][j] = '1';
				if (get(i, j - 1, board, num) == 1 && board[i][j - 1] == '0')
					board[i][j - 1] = '1';
				if (get(i + 1, j, board, num) == 1 && board[i + 1][i] == '0')
					board[i + 1][i] = '1';
				if (get(i, j + 1, board, num) == 1 && board[i][j + 1] == '0')
					board[i][j + 1] = '1';
				if (get(i - 1, j - 1, board, num) == 1 && board[i - 1][j - 1] == '0')
					board[i - 1][j - 1] = '1';
				if (get(i - 1, j + 1, board, num) == 1 && board[i - 1][j + 1] == '0')
					board[i - 1][j + 1] = '1';
				if (get(i + 1, j - 1, board, num) == 1 && board[i + 1][j - 1] == '0')
					board[i + 1][j - 1] = '1';
				if (get(i + 1, j + 1, board, num) == 1 && board[i + 1][j + 1] == '0')
					board[i + 1][j + 1] = '1';
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%c", board[i][j]);
			if (board[i][j] == '0')
				remainder++;
		}
		printf("\n");
	}
	return remainder;
}
int main() {
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	char strNum[50], str[100]; //���� �����
	char **chessBoard; //2���� �迭
	char *cutStr[3]; //���� �����
	int num, size[3]; //2���� �迭�� ũ��, A, B, C�� ���� ��
	int pt[3][8] = { 0, }, ptx, pty; //��ǥ����
	int i, j, k; //�ݺ����� ���
	int remainder, testNum; //���� ���� ��, �׽�Ʈ���̽�
	scanf("%s", str);
	testNum = atoi(str);   //�迭 ũ���Ҵ�
	(k = 0; k < testNum; k++)
	{
		printf("#%d\n", k + 1);
		fgets(strNum, 50, in); //���� �Է�
		fgets(str, 100, in); // ���� �Է�
		num = atoi(strNum); // �迭 ũ�� �Ҵ�
		chessBoard = (char**)malloc(sizeof(char*)*num);
		for (i = 0; i < num; i++)
			chessBoard[i] = (char*)malloc(sizeof(char)*num);
		for (i = 0; i < num; i++)
			for (j = 0; j < num; j++)
				chessBoard[i][j] = '0';
		cutStr[0] = strtok(str, ",");  // A�� ��
		cutStr[1] = strtok(NULL, ","); // B�� ��
		cutStr[2] = strtok(NULL, ","); // C�� ��

		for (i = 0; i < 3; i++)
			size[i] = strlen(cutStr[i]);
		for (i = 0; i < 3; i++) //��ǥ
		{
			pt[i][0] = atoi(strtok(cutStr[i], " "));
			for (j = 1; j <= (size[i] - 1) / 2; j++)
				pt[i][j] = atoi(strtok(NULL, " "));
		}
		for (i = 0; i < 3; i++)
		{
			printf("%c�� �� ��ġ : ", 65 + i);
			for (j = 0; j <= (size[i] - 1) / 2; j++)
				printf("%d", pt[i][j]);
			printf("\n");
		}
		for (i = 0; i < 3; i++) //�Է¹��� ��ǥ�� �� ��ġ
		{
			for (j = 0; j <= (size[i] - 1) / 2; j++)
			{
				if (i == 0)
				{
					if ((i + j) % 2 == 0)
						ptx = pt[i][j];
					else
					{
						pty = pt[i][j];
						chessBoard[ptx][pty] = 'A'; //A�� ��ġ
					}
				}
				else if (i == 1)
				{
					if ((i + j) % 2 == 0)
					{
						pty = pt[i][j];
						chessBoard[ptx][pty] = 'B'; //B�� ��ġ
					}
					else ptx = pt[i][j];
				}
				else
				{

					if ((i + j) % 2 == 0)
						ptx = pt[i][j];
					else
					{
						pty = pt[i][j];
						chessBoard[ptx][pty] = 'C'; //C�� ��ġ
					}
				}
			}
		}
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
				printf("%c", chessBoard[i][j]);
			printf("\n");
		}
		remainder = matrix(chessBoard, num);
		printf("��ĭ�� ���� : %d \n\n", remainder);
		fprintf(out, "#%d %d \n", k + 1, remainder);
	}
	fclose(in);
	fclose(out);
	return 0;
}