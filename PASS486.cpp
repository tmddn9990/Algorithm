#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int dat[10000000] = { 0, };

int main()
{
	int c, n, lo, hi;//테스트케이스,약수갯수,최소값,최대값

	for (int i = 1; i <= 10000000; i++)
	{

		for (int j = i; j <= 10000000; j += i)
		{
			dat[j - 1]++;
		}
	}
	freopen("input.txt", "r", stdin);
	cin >> c;
	for (int testNum = 1; testNum <= c; testNum++)
	{
		cin >> n >> lo >> hi;
		int count = 0;
		for (int i = lo; i <= hi; i++)
			if (dat[i - 1] == n)
				count++;
		cout << count << endl;

	}

	return 0;
}
