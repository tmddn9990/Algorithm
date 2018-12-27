#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<queue>

using namespace std;
bool map[10][10];
int non_size = 0;

void check(int i, int j, int size)
{
	non_size++;
	map[i][j] = 0;
	if (i - 1 >= 0)
		if (map[i - 1][j] == 1)
			check(i - 1, j, size);
	if (i + 1 < size)
		if (map[i + 1][j] == 1)
			check(i + 1, j, size);
	if (j - 1 >= 0)
		if (map[i][j - 1] == 1)
			check(i, j - 1, size);
	if (j + 1 < size)
		if (map[i][j + 1] == 1)
			check(i, j + 1, size);
}


void main()
{
	int testNum, size, non;
	queue<int> num;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int n = 0; n < testNum; n++)
	{
		cin >> size;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> map[i][j];

		non = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (map[i][j] == 1)
				{
					non++;
					check(i, j, size);
					num.push(non_size);
					non_size = 0;
				}
			}
		}

		cout << "#" << n + 1 << " " << non;
		while (!num.empty())
		{
			cout << " " << num.front();
			num.pop();
		}
		cout << endl;
	}
}
