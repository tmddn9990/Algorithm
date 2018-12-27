#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int R, C;
int maxV = 0;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
char map[21][21];
int check[26];
void dfs(int x, int y, int cnt)
{
	if (check[map[y][x] - 'A'] == 0)
	{
		check[map[y][x] - 'A'] = 1;

		cnt > maxV ? maxV = cnt : 0;
		for (int i = 0; i < 4; i++)
		{
			if ((x + dx[i]) <= C && (x + dx[i]) >= 1 && (y + dy[i]) <= R && (y + dy[i]) >= 1)
				dfs(x + dx[i], y + dy[i], cnt + 1);
		}

		check[map[y][x] - 'A'] = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int cnt = 1;
	cin >> R >> C;
	string str;
	for (int i = 1; i <= R; i++)
	{
		cin >> str;
		for (int j = 1; j <= C; j++)
			map[i][j] = str[j - 1];
	}

	dfs(1, 1, cnt);
	cout << maxV << endl;


	return 0;
}
