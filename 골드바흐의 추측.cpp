#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

bool check(int i)
{
	bool sosu = true;
	for (int a = 2; a < i; a++)
		if (i%a == 0)
			sosu = false;
	return sosu;


}

void main()
{

	int testNum, num;

	freopen("input.txt", "r", stdin);
	cin >> testNum;

	for (int n = 1; n <= testNum; n++)
	{
		cout << "#" << n << " ";
		cin >> num;

		for (int i = 2; i <= num / 2; i++)
			if (check(i)) {
				if (check(num - i))
				{
					cout << i << " " << num - i;
					break;
				}
			}
		cout << endl;
	}
}