#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MOD = 1000000007;
int F[101];
int fibo(int n)
{
	if (n <= 1)
		F[n] = 1;
	int &ret = F[n];
	if (ret != -1)
		return ret;
	return ret = (fibo(n - 2) + fibo(n - 1)) % MOD;

}

int asym(int n)
{
	if (n % 2 == 1)
		return(fibo(n) - fibo(n / 2) + MOD) % MOD;
	int tmp = (fibo(n) - fibo(n / 2) + MOD) % MOD;
	return (tmp - fibo(n / 2 - 1) + MOD) % MOD;

}
int main()
{
	memset(F, -1, sizeof(F));
	freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;
	while (testNum--)
	{
		int n;
		cin >> n;
		cout << asym(n) << endl;
	}
	return 0;
}
