#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

bool prime[10000], check[10000];
void eratosthenes()
{
	int start, index;
	prime[0] = prime[1] = false;
	for (int i = 2; i < 10000; i++)
		prime[i] = true;
	for (int i = 2; i < 10000; i++) {
		if (!prime[i])    continue;
		start = i;
		for (int j = start; j*start < 10000; j++)
			prime[j*start] = false;
	}
}
struct stru
{
	int a;
	int b;
};
int main()
{
	eratosthenes();
	freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;

	int first, destination;

	while (testNum--)
	{
		for (int i = 1000; i < 10000; i++)
			check[i] = false;
		cin >> first >> destination;
		queue<stru> que;
		stru st;
		st.a = first;
		st.b = 0;
		que.push(st);
		check[first] = true;
		int ans;

		int a, b, c, d;

		while (!que.empty())
		{
			int num = que.front().a;
			int cnt = que.front().b;

			if (num == destination)
			{
				ans = cnt;
				break;
			}

			a = num / 1000;
			b = (num % 1000) / 100;
			c = (num % 100) / 10;
			d = (num % 10);

			que.pop();

			for (int i = 1; i <= 9; i += 2)
			{
				int temp = a * 1000 + b * 100 + c * 10 + i;
				if (prime[temp] && !check[temp])
				{
					check[temp] = true;
					stru st2;
					st2.a = temp;
					st2.b = cnt + 1;
					que.push(st2);
				}
			}

			for (int i = 0; i <= 9; i++)
			{
				int temp = a * 1000 + b * 100 + i * 10 + d;
				if (prime[temp] && !check[temp])
				{
					check[temp] = true;
					stru st2;
					st2.a = temp;
					st2.b = cnt + 1;
					que.push(st2);
				}

				temp = a * 1000 + i * 100 + c * 10 + d;
				if (prime[temp] && !check[temp])
				{
					check[temp] = true;
					stru st2;
					st2.a = temp;
					st2.b = cnt + 1;
					que.push(st2);
				}

				if (i != 0)
				{
					temp = i * 1000 + b * 100 + c * 10 + d;
					if (prime[temp] && !check[temp])
					{
						check[temp] = true;
						stru st2;
						st2.a = temp;
						st2.b = cnt + 1;
						que.push(st2);
					}
				}
			}
		}
		cout << ans << endl;
	}
}