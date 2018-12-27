#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool map[10][10] = { 0 };

void search(bool check[], int num, int now) {
	if (num == now || check[now]) return;
	check[now] = true;
	for (int i = 1; i < 10; i++) {
		if (map[now][i] && !check[i]) {
			search(check, num, i);
		}
	}
}
void main()
{
	freopen("input.txt", "r", stdin);
	for (int n = 0; n < 3; n++)
	{
		string s, t;

		int x;


		cin >> x;
		getchar();
		getline(cin, s);
		for (int i = 0; i < s.size(); i += 4)
		{
			map[s[i] - '1'][s[i + 2] - '1'] = 1;
			map[s[i + 2] - '1'][s[i] - '1'] = 1;
		}

		for (int i = 0; i < 10; i++)
		{
			bool check[10] = { 0 };
			bool imp = 0;
			if (i == 0)
				search(check, i, 1);
			else
				search(check, i, 1);
			for (int j = 0; j < 10; j++)
			{
				if (!check[j] && i != j)imp = 1;
			}
			if (imp)
				cout << i + 1 << " ";
		}

	}
}