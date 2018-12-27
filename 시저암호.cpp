#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void main()
{
	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int n = 0; n < testNum; n++)
	{
		int key = 0;
		string str = "", temp = "";
		cin >> key;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'a'&&str[i] <= 'z')
				str[i] += ('A' - 'a');

			temp += (str[i] + key);
			if (temp[i] > 'Z')
				temp[i] -= 26;
		}
		cout << "#" << n + 1 << " " << temp << endl;

	}
}
