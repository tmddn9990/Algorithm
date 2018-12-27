#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1000
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);

	int testNum;
	cin >> testNum;
	while (testNum--)
	{
		int now[16];
		int ans = 0;
		for (int i = 0; i < 16; i++)
			cin >> now[i];

		while (now[8] % 12 != 0)
		{
			ans++;
			now[6] += 3;
			now[7] += 3;
			now[8] += 3;
			now[10] += 3;
			now[12] += 3;
		}
		while (now[6] % 12 != 0)
		{
			ans++;
			now[0] += 3;
			now[4] += 3;
			now[5] += 3;
			now[6] += 3;
			now[7] += 3;
		}
		while (now[10] % 12 != 0)
		{
			ans++;
			now[4] += 3;
			now[10] += 3;
			now[14] += 3;
			now[15] += 3;
		}
		while (now[11] % 12 != 0)
		{
			ans++;
			now[3] += 3;
			now[7] += 3;
			now[9] += 3;
			now[11] += 3;
		}
		while (now[7] % 12 != 0)
		{
			ans++;
			now[4] += 3;
			now[5] += 3;
			now[7] += 3;
			now[14] += 3;
			now[15] += 3;
		}
		while (now[9] % 12 != 0)
		{
			ans++;
			now[3] += 3;
			now[4] += 3;
			now[5] += 3;
			now[9] += 3;
			now[13] += 3;
		}
		while (now[4] % 12 != 0)
		{
			ans++;
			now[1] += 3;
			now[2] += 3;
			now[3] += 3;
			now[4] += 3;
			now[5] += 3;
		}
		while (now[1] % 12 != 0)
		{
			ans++;
			now[1] += 3;
			now[2] += 3;
			now[0] += 3;
		}
		while (now[0] % 12 != 0)
		{
			ans++;
			now[0] += 3;
			now[2] += 3;
			now[14] += 3;
			now[15] += 3;
		}
		while (now[3] % 12 != 0)
		{
			ans++;
			now[3] += 3;
			now[14] += 3;
			now[15] += 3;

		}
		bool che = true;
		for (int i = 0; i < 16; i++)
			if (now[i] % 12 != 0)
			{
				che = false;
				break;
			}
		if (che)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}



}