#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<time.h>
#include<string>
#include<queue>
#include<deque>
using namespace std;

struct mem
{
	int ord;
	int pri;
};



int main()
{

	int testNum;
	//freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int tn = 1; tn <= testNum; tn++)
	{
		int count = 0;
		deque<mem> pri;
		mem temp;
		int size, num;
		cin >> size >> num;
		for (int i = 0; i < size; i++)
		{
			int pre;
			cin >> pre;
			temp.ord = i;
			temp.pri = pre;
			pri.push_back(temp);
		}
		while (!pri.empty())
		{
			bool max = true;
			temp = pri.front();
			pri.pop_front();
			for (int i = 0; i < pri.size(); i++)
			{
				if (temp.pri < pri[i].pri)
				{
					pri.push_back(temp);
					max = false;
					break;
				}
			}
			if (max)
			{
				count++;

				if (temp.ord == num)
				{
					break;
				}
			}
		}


		cout << count << endl;


	}
	return 0;
}
