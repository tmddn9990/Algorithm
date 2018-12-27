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
		string str;
		cin >> str;
		int size = str.size();
		int height = sqrt(size) + 1;
		int temp = pow(height, 2);
		int pad = temp - size;
		char c = 'A';
		for (int i = 0; i < pad; i++)
		{

			str.push_back(c);
			c++;
		}
		string ans;
		for (int i = 1; i <= height; i++)
		{
			int x = pow(i, 2) - i;
			ans += str.at(x);
		}
		cout << "#" << n + 1 << " " << height << " " << ans << endl;
	}

}