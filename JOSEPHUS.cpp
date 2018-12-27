#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;



int main()
{
	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	while (testNum--)
	{
		int n, k;
		cin >> n >> k;
		queue<int> a;
		for (int i = 0; i < n; i++)
		{
			a.push(i + 1);
		}
		for (int j = 0; j < n - 2; j++)
		{
			a.pop();
			for (int i = 0; i < k - 1; i++)
			{
				a.push(a.front());
				a.pop();
			}
		}
		int x, y;
		x = a.front();
		a.pop();
		y = a.front();

		if (x >= y)
			cout << y << " " << x << endl;
		else
			cout << x << " " << y << endl;


	}
	return 0;
}
