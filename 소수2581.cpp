#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

bool sosu(int num)
{
	int count = 0;
	for (int i = 1; i < num; i++)
	{
		if (num%i == 0)
			count++;
	}
	if (count == 1)
		return true;
	else
		return false;
}

int main()
{
	queue<int> a;
	int m, n;
	int sum = 0;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		if (sosu(i) == true)
		{
			sum += i;
			a.push(i);
		}
	}
	if (sum > 0)
		cout << sum << endl << a.front();
	else
		cout << -1;
	return 0;
}