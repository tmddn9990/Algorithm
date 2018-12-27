#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int D[101][11];
int mod = 1000000000;
int main(void) {

	int N;
	cin >> N;
	D[1][0] = 0;
	for (int i = 1; i <= 10; i++)
		D[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		D[i][0] = D[i - 1][1] % mod;
		for (int j = 1; j <= 8; j++)
			D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) % mod;
		D[i][9] = D[i - 1][8] % mod;
	}
	int a = 0;
	for (int i = 0; i <= 9; i++)
	{
		a += D[N][i];
		a %= mod;
	}
	cout << a;
	return 0;
}