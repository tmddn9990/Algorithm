#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


int main() {

	//freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;
	while (testNum--)
	{
		deque<int> rus, kor;
		int size;
		int temp;
		int ans = 0;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cin >> temp;
			rus.push_back(temp);
		}
		for (int i = 0; i < size; i++)
		{
			cin >> temp;
			kor.push_back(temp);
		}
		sort(rus.begin(), rus.end());
		sort(kor.begin(), kor.end());

		while (kor.size() > 0)
		{
			if (rus.front() > kor.front())
				kor.pop_front();
			else
			{
				ans++;
				rus.pop_front();
				kor.pop_front();
			}

		}
		cout << ans << endl;

	}
	return 0;
}