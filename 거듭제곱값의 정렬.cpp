#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;


void main()
{

	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int n = 1; n <= testNum; n++)
	{
		int a, b, num;
		cin >> a >> b >> num;
		int arr[50];
		arr[0] = a, arr[1] = b;
		int i = 0, x = 2;
		sort(arr, arr + 2);
		while (i < num)
		{

			int temp1, temp2;
			temp1 = arr[i] * a;
			temp2 = arr[i] * b;
			bool check1 = 0, check2 = 0;
			for (int j = 0; j < x; j++)
			{
				if (arr[j] == temp1)
					check1 = 1;
				if (arr[j] == temp2)
					check2 = 1;
			}

			if (!check1)
			{
				arr[x] = temp1;
				x++;
			}
			if (!check2)
			{
				arr[x] = temp2;
				x++;
			}
			sort(arr, arr + x);
			i++;

		}

		cout << "#" << n << " " << arr[num - 1] << endl;
	}

}
