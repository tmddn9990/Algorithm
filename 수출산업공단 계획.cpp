#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

char map[15][15];
int map2[15][15];

void check(int size, int a, int b)
{
	int count = 0;
	if (map2[a][b] == 1) {
		if (map2[a - 1][b] == 0 || map2[a][b - 1] == 0 || map2[a + 1][b] == 0 || map2[a][b + 1] == 0);
		else
		{
			for (int i = 0; i < size; i++)
				if (map2[i][b] > 0)
					count++;
			for (int i = 0; i < size; i++)
				if (map2[a][i] > 0)
					count++;
			map2[a][b] = count - 1;

		}
	}

}
void main()
{
	int testNum;
	int size;
	int height;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int n = 0; n < testNum; n++)
	{
		int count = 0;
		int ans = 0;
		cin >> size;
		cin >> height;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'P')
					map2[i][j] = 0;
				else if (map[i][j] == 'B')
					map2[i][j] = 1;
			}


		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				check(size, i, j);

			}

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				ans += map2[i][j];

				if (map2[i][j] >= height)
					count++;
			}

		cout << endl;
		cout << "#" << n + 1 << " " << ans << " " << count << endl;
	}

}