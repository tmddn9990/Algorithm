#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
using namespace std;
int n, m, price[20], pref[20];
int c[201];
int sushi()
{
	int ret = 0;
	c[0] = 0;
	for (int budget = 1; budget <= m; ++budget)
	{
		int cand = 0;
		for (int dish = 0; dish < n; ++dish)
			if (budget >= price[dish])
				cand = max(cand, c[(budget - price[dish]) % 201] + pref[dish]);
		c[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;

}



int main() {
	//freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;
	while (testNum--)
	{
		for (int i = 0; i < 201; i++)
			c[i] = -1;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> price[i] >> pref[i];
			price[i] /= 100;
		}
		m /= 100;
		cout << sushi() << endl;
	}
	return 0;
}
