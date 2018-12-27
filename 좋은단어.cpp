#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main()
{
	int testNum, ans = 0;
	cin >> testNum;
	for (int n = 1; n <= testNum; n++)
	{
		stack<char> stk;
		string str;
		cin >> str;
		int size = str.size();
		int num = 0;
		for (int i = 0; i < size; i++)
		{
			if (stk.empty() || stk.top() != str.at(i))
				stk.push(str.at(i));
			else
				stk.pop();



		}
		if (stk.empty())
			ans++;
	}
	cout << ans;
	return 0;
}
