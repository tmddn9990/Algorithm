#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	//freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;
	while (testNum--)
	{
		int lunch[10000][2];
		int size;
		int ans = 0;
		int temp;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			cin >> lunch[i][0];
		}
		for (int i = 0; i < size; i++)
		{
			cin >> lunch[i][1];
		}
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (lunch[i][1] < lunch[j][1])
				{

					swap(lunch[i][0], lunch[j][0]);
					swap(lunch[i][1], lunch[j][1]);
				}
		ans = lunch[0][0] + lunch[0][1];
		temp = ans;
		for (int i = 1; i < size; i++)
		{
			temp = temp - lunch[i - 1][1] + lunch[i][0] + lunch[i][1];
			ans = max(ans, temp);
		}
		cout << ans << endl;


	}
	return 0;
}
