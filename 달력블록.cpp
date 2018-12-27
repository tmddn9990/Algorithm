#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


void main()
{

	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int n = 1; n <= testNum; n++)
	{
		int a, num, ans;
		cin >> a >> num;
		if (num % 9 != 0)
			ans = -1;
		else
		{
			num /= 9;
			ans = a + ((29 - (num - 8)) % 7);
			if (ans > 6)
				ans %= 7;
		}
		cout << "#" << n << " " << ans << endl;

	}
}