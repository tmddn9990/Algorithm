#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int rvs(int &a)
{
	int res = 0;
	while (a > 0)
	{
		res *= 10;
		res += a % 10;
		a /= 10;
	}
	return res;
}
int main()
{
	int a, b;
	int a2, b2;
	cin >> a >> b;
	a2 = rvs(a);
	b2 = rvs(b);
	if (a2 > b2)
		cout << a2;
	else
		cout << b2;
	return 0;
}