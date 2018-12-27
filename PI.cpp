#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;
int S[10001];
string str;

int score(int start, int end)
{
	string tmp = str.substr(start, end - start + 1);



	bool updown = true;
	for (int i = 0; i < tmp.size() - 1; i++)
		if (tmp[i + 1] - tmp[i] != tmp[1] - tmp[0])
		{
			updown = false;
		}
	bool alternate = true;
	for (int i = 0; i < tmp.size(); i++)
		if (tmp[i] != tmp[i % 2])
			alternate = false;
	if (updown)
		if (abs(tmp[1] - tmp[0]) == 1)
			return 2;
		else if (tmp[1] - tmp[0] == 0)
			return 1;
		else
			return 5;


	if (alternate)
		return 4;


	return 10;

}
int PI(int start)
{
	if (start == str.size())
		return 0;
	int& ret = S[start];
	if (ret != -1)
		return ret;
	ret = 100000;

	for (int i = 3; i <= 5; i++)
		if (start + 1 <= str.size())
			ret = min(ret, PI(start + i) + score(start, start + i - 1));
	return ret;

}
int main()
{

	freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;
	while (testNum--)
	{
		memset(S, -1, sizeof(S));
		cin >> str;
		cout << PI(0) << endl;
	}
	return 0;
}