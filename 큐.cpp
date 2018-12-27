#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<time.h>
#include<string>
using namespace std;

int queue[10000] = { 0, };
int key1 = -1, key2 = 0;




int main()
{

	int testNum;
	//freopen("input.txt", "r", stdin);
	cin >> testNum;

	for (int tn = 1; tn <= testNum; tn++)
	{

		string str;
		cin >> str;
		if (str == "pop")
		{
			if (key1 < key2)
				cout << -1 << endl;
			else
			{
				cout << queue[key2] << endl;;
				key2++;
			}
		}
		else if (str == "size")
		{
			cout << (key1 - key2 + 1) << endl;
		}
		else if (str == "empty")
		{
			cout << (key1 < key2) << endl;
		}
		else if (str == "front")
		{
			if (key1 < key2)
				cout << -1 << endl;
			else
			{
				cout << queue[key2] << endl;
			}
		}
		else if (str == "back")
		{
			if (key1 < key2)
				cout << -1 << endl;
			else
			{
				cout << queue[key1] << endl;
			}
		}
		else if (str == "push")
		{
			int n;
			cin >> n;
			key1++;
			queue[key1] = n;
		}


	}

	return 0;
}
