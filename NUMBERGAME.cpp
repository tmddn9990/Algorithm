#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int n, S[50];
int cache[50][50];
int play(int left, int right)
{
	if (left > right)return 0;
	int& ret = cache[left][right];
	if (ret != 10000)return ret;
	ret = max(S[left] - play(left + 1, right), S[right] - play(left, right - 1));
	if (right - left + 1 >= 2)
	{
		ret = max(ret, -play(left + 2, right));
		ret = max(ret, -play(left, right - 2));

	}
	return ret;
}
int main()
{
	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	while (testNum--)
	{
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				cache[i][j] = 10000;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> S[i];
		cout << play(0, n - 1) << endl;


	}

	return 0;
}