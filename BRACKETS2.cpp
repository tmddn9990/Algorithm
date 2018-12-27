define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main()
{
	int testNum, ans = 0;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int n = 1; n <= testNum; n++)
	{

		stack<char> stk;
		string str;
		cin >> str;
		int size = str.size();
		for (int i = 0; i < size; i++)
		{
			if (stk.empty() || stk.top() == ')' || stk.top() == '}' || stk.top() == ']')
				stk.push(str.at(i));
			else
			{
				switch (stk.top())
				{
				case '(':
					if (str.at(i) == ')')
						stk.pop();
					else
						stk.push(str.at(i));
					break;
				case '{':
					if (str.at(i) == '}')
						stk.pop();
					else
						stk.push(str.at(i));
					break;
				case '[':
					if (str.at(i) == ']')
						stk.pop();
					else
						stk.push(str.at(i));
					break;
				}
			}



		}
		if (stk.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
