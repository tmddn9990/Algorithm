#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int sudoku[9][9];
int sum;
int num = 1;
int ans;
void check(int a, int b)
{
	bool check1 = 0, check2 = 0, check3 = 0;
	sum = 0;;


	for (int i = 0; i < 9; i++)
	{
		if (i != a)
			if (sudoku[a][b] == sudoku[i][b])
				check1 = 1;

	}
	for (int i = 0; i < 9; i++)
	{
		if (i != b)
			if (sudoku[a][b] == sudoku[a][i])
				check2 = 1;

	}
	for (int i = a / 3 * 3; i < a / 3 * 3 + 3; i++)
		for (int j = b / 3 * 3; j < b / 3 * 3 + 3; j++)
		{
			if (i != a || j != b)
				if (sudoku[a][b] == sudoku[i][j])
					check3 = 1;
		}


	if (check1&&check2&&check3)
	{

		sudoku[a][b] = 0;
		for (int i = 0; i < 9; i++)
		{
			sum = sum + sudoku[i][b];
		}
		ans = 45 - sum;
		cout << "#" << num << " " << a + 1 << " " << b + 1 << " " << ans << endl;

		num++;
	}

}

void main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			check(i, j);
		}
}