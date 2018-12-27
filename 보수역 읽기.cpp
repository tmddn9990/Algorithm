#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main()
{
	int testNum;
	int num;
	string num_2;

	fflush(stdin);
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int t = 1; t <= testNum; t++)
	{
		int ans = 0;
		num_2 = "";
		cin >> num;
		while (num > 0) {
			num_2 += (char)((num % 2) + '0');
			num /= 2;
		}
		int len = num_2.length();
		for (int i = 0; i < len; i++)
		{
			if (num_2[i] == '0')
				num_2[i] = '1';
			else
				num_2[i] = '0';
			ans += (num_2[i] - '0') * pow(2, len - i - 1);
		}
		cout << "#" << t << " " << ans << endl;
	}
}
