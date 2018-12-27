#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<time.h>
#include<string>
using namespace std;

int stack[10000];
int key = -1;




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
			if (key == -1)
				cout << -1 << endl;
			else
			{
				cout << stack[key] << endl;;
				key--;
			}
		}
		else if (str == "size")
		{
			cout << (key + 1) << endl;
		}
		else if (str == "top")
		{
			if (key == -1)
			{
				cout << -1 << endl;
			}
			else
				cout << stack[key] << endl;
		}
		else if (str == "empty")
		{
			cout << (key == -1) << endl;
		}

		else if (str == "push")
		{
			int n;
			cin >> n;
			key++;
			stack[key] = n;
		}


	}

	return 0;
}
