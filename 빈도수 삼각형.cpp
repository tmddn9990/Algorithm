#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<queue>
using namespace std;

queue<char> que;
void main()
{

	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int n = 1; n <= testNum; n++)
	{
		string str;
		cin >> str;
		int check[26] = { 0 };
		for (int i = 0; i < str.size(); i++)
		{
			check[str[i] - 'A']++;
		}
		int count = 0;

		for (int i = 1; i < str.size(); i++)
			for (int j = 0; j < 26; j++)
				if (check[j] == i)
				{
					count++;
					que.push((char)(j + 'A'));
					break;
				}
		cout << "#" << n << " " << count << " ";
		while (!que.empty()) {
			cout << que.front();
			que.pop();
		}
		cout << endl;
	}
}