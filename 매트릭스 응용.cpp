#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get(int i, int j, char **board, int num)//범위 체크함수
{
	if (i < 0 || j < 0 || i >= num || j >= num)
		return 0;
	return 1;
}

int matrix(char **board, int num)//A,B,C형 폭탄의 범위계산
{
	int i, j;
	int remainder = 0;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			switch (board[i][j])
			{
			case'C':
				if (get(i - 3, j, board, num) == 1 && board[i - 3][j] == '0')
					board[i - 3][j] = '1';
				if (get(i, j - 3, board, num) == 1 && board[i][j - 3] == '0')
					board[i][j - 3] = '1';
				if (get(i + 3, j, board, num) == 1 && board[i + 3][j] == '0')
					board[i + 3][j] = '1';
				if (get(i, j + 3, board, num) == 1 && board[i][j + 3] == '0')
					board[i][j + 3] = '1';
			case'B':
				if (get(i - 2, j, board, num) == 1 && board[i - 2][j] == '0')
					board[i - 2][j] = '1';
				if (get(i, j - 2, board, num) == 1 && board[i][j - 2] == '0')
					board[i][j - 2] = '1';
				if (get(i + 2, j, board, num) == 1 && board[i + 2][j] == '0')
					board[i + 2][j] = '1';
				if (get(i, j + 2, board, num) == 1 && board[i][j + 2] == '0')
					board[i][j + 2] = '1';
			case'A':
				if (get(i - 1, j, board, num) == 1 && board[i - 1][j] == '0')
					board[i - 1][j] = '1';
				if (get(i, j - 1, board, num) == 1 && board[i][j - 1] == '0')
					board[i][j - 1] = '1';
				if (get(i + 1, j, board, num) == 1 && board[i + 1][j] == '0')
					board[i + 1][j] = '1';
				if (get(i, j + 1, board, num) == 1 && board[i][j + 1] == '0')
					board[i][j + 1] = '1';
			}

		}
	}
	printf("\n\n");
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%c", board[i][j]);
			if (board[i][j] == '0')
			{
				remainder++;
			}
		}
		printf("\n");
	}
	return remainder;//남은 지역수
}

int main()
{
	FILE *in, *out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	char tempNum[50], temp[100];
	char **arrNum;
	char *cutStr[3];
	int num, size[3];
	int pt[3][8] = { 0, }, ptx, pty;
	int i, j, k;
	int remainder, testNum;
	fgets(temp, 100, in);
	testNum = atoi(temp);
	for (k = 0; k < testNum; k++)
	{
		printf("#%d", k + 1);
		fgets(tempNum, 50, in);
		fgets(temp, 100, in);
		num = atoi(tempNum);
		arrNum = (char**)malloc(sizeof(char*)*num);
		for (i = 0; i < num; i++)
			arrNum[i] = (char*)malloc(sizeof(char)*num);
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
				arrNum[i][j] = '0';
		}
		cutStr[0] = strtok(temp, ",");
		cutStr[1] = strtok(NULL, ",");
		cutStr[2] = strtok(NULL, ",");
		for (i = 0; i < 3; i++)
		{
			size[i] = strlen(cutStr[i]);
		}
		for (i = 0; i < 3; i++)
		{
			pt[i][0] = atoi(strtok(cutStr[i], " "));
			for (j = 1; j <= (size[i] - 1) / 2; j++)
			{
				pt[i][j] = atoi(strtok(NULL, " "));
			}
		}
		printf("지도크기 : %d\n", num);
		printf("폭탄 위치\n");
		for (i = 0; i < 3; i++)
		{
			printf("%c 형폭탄 : ", 65 + i);
			for (j = 0; j <= (size[i] - 1) / 2; j++)
			{
				printf("%d", pt[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for (i = 0; i < 3; i++)
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
						arrNum[ptx][pty] = 'A';
					}
				}
				else if (i == 1)
				{
					if ((i + j) % 2 == 0)
					{
						pty = pt[i][j];
						arrNum[ptx][pty] = 'B';
					}
					else
						ptx = pt[i][j];
				}
				else
				{
					if ((i + j) % 2 == 0)
						ptx = pt[i][j];
					else
					{
						pty = pt[i][j];
						arrNum[ptx][pty] = 'C';
					}
				}
			}
		}
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				printf("%c", arrNum[i][j]);
			}
			printf("\n");
		}
		remainder = matrix(arrNum, num);
		printf("\n빈 지역의 수 : %d \n \n", remainder);
		fprintf(out, "#%d %d\n", k + 1, remainder);




	}
	fclose(in);
	fclose(out);
	return 0;

}
