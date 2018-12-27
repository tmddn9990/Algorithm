#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string str;


void main()
{
	int testNum;

	freopen("input.txt", "r", stdin);
	cin >> testNum;
	cin >> str;
	for (int n = 0; n < testNum; n++)
	{
		int ans = 0;
		string compare;
		cin >> compare;
		cout << "#" << n + 1;
		for (int i = 2; i < compare.size(); i++)//i는 글자수 2,3,4,5...
			for (int j = 0; j < compare.size() - (i - 1); j++)//j는 비교범위 0부터 글자수에따라
			{
				string s = compare.substr(j, i);
				if (0 <= str.find(s) && str.find(s) < str.size())
				{
					if (compare.size() >= i + j + 1)
					{
						string s1 = compare.substr(j, i + 1);
						if (0 <= str.find(s1) && str.find(s1) < str.size())
							continue;
					}
					if (j - 1 >= 0)
					{
						string s2 = compare.substr(j - 1, i + 1);
						if (0 <= str.find(s2) && str.find(s2) < str.size())
							continue;
					}
					ans++;
					cout << " " << s;
				}

			}

		cout << " " << ans << endl;
	}
}