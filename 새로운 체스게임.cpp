#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int get(int i, int j, char** board, int num) //범위 체크함수
{
	if (i < 0 || i >= num || j >= num)
		return 0;
	return 1;
}
int matrix(char **board, int num) // 퀸의 범위 계산 
{
	int i, j;
	int k = 0;
	int remainder = 0; //빈칸의 수

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			switch (board[i][j])
			{
			case'C':  // C형 퀸의 범위만큼 1로 변환
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

			case'B': // B형 퀸의 범위만큼 1로 변환
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

			case'A': // A형 퀸의 범위만큼 1로 변환
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
	char strNum[50], str[100]; //파일 입출력
	char **chessBoard; //2차원 배열
	char *cutStr[3]; //파일 입출력
	int num, size[3]; //2차원 배열의 크기, A, B, C형 퀸의 수
	int pt[3][8] = { 0, }, ptx, pty; //좌표변수
	int i, j, k; //반복문에 사용
	int remainder, testNum; //남은 영역 수, 테스트케이스
	scanf("%s", str);
	testNum = atoi(str);   //배열 크기할당
	(k = 0; k < testNum; k++)
	{
		printf("#%d\n", k + 1);
		fgets(strNum, 50, in); //파일 입력
		fgets(str, 100, in); // 파일 입력
		num = atoi(strNum); // 배열 크기 할당
		chessBoard = (char**)malloc(sizeof(char*)*num);
		for (i = 0; i < num; i++)
			chessBoard[i] = (char*)malloc(sizeof(char)*num);
		for (i = 0; i < num; i++)
			for (j = 0; j < num; j++)
				chessBoard[i][j] = '0';
		cutStr[0] = strtok(str, ",");  // A형 퀸
		cutStr[1] = strtok(NULL, ","); // B형 퀸
		cutStr[2] = strtok(NULL, ","); // C형 퀸

		for (i = 0; i < 3; i++)
			size[i] = strlen(cutStr[i]);
		for (i = 0; i < 3; i++) //좌표
		{
			pt[i][0] = atoi(strtok(cutStr[i], " "));
			for (j = 1; j <= (size[i] - 1) / 2; j++)
				pt[i][j] = atoi(strtok(NULL, " "));
		}
		for (i = 0; i < 3; i++)
		{
			printf("%c형 퀸 위치 : ", 65 + i);
			for (j = 0; j <= (size[i] - 1) / 2; j++)
				printf("%d", pt[i][j]);
			printf("\n");
		}
		for (i = 0; i < 3; i++) //입력받은 좌표에 퀸 배치
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
						chessBoard[ptx][pty] = 'A'; //A형 배치
					}
				}
				else if (i == 1)
				{
					if ((i + j) % 2 == 0)
					{
						pty = pt[i][j];
						chessBoard[ptx][pty] = 'B'; //B형 배치
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
						chessBoard[ptx][pty] = 'C'; //C형 배치
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
		printf("빈칸의 개수 : %d \n\n", remainder);
		fprintf(out, "#%d %d \n", k + 1, remainder);
	}
	fclose(in);
	fclose(out);
	return 0;
}