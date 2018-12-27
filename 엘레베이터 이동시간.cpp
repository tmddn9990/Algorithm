#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


void main() {

	int n;
	int time = 0;
	int temp = 1;
	int start, end;
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		if (start < 0)
			start = start + 1;
		if (end < 0)
			end = end + 1;
		time = time + abs(start - temp) + abs(end - start);
		temp = end;

	}
	cout << time;
}
