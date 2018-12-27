#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 1000
using namespace std;
bool friends[10][10];
int n;
int partner(bool par[10])
{
	int fir = -1;
	for (int i = 0; i < n; i++)
		if (!par[i])
		{
			fir = i;
			break;
		}
	if (fir == -1)
		return 1;
	int check = 0;
	for (int j = fir + 1; j < n; j++)
	{
		if (!par[j] && friends[fir][j])
		{
			par[fir] = par[j] = true;
			check += partner(par);
			par[fir] = par[j] = false;
		}
	}
	return check;
}

int main() {
	freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;
	while (testNum--)
	{
		int m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				friends[i][j] = false;
		for (int i = 0; i < m; i++)
		{
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			friends[tmp1][tmp2] = friends[tmp2][tmp1] = true;
		}
		bool par[10];
		for (int i = 0; i < n; i++)
			par[i] = false;

		cout << partner(par) << endl;
	}


}