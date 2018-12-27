#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	int n, m, max = 0, min = 0, sum = 0;
	int mid;
	int temp;
	cin >> n >> m;
	vector<int> tree;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (max < temp)
			max = temp;
		tree.push_back(temp);
	}
	while (min <= max)
	{
		sum = 0;
		mid = (max + min) / 2;
		for (int i = 0; i < n&&sum <= m; i++)
		{
			if (tree[i] > mid)
				sum += (tree[i] - mid);
		}
		if (sum == m) {
			cout << mid << endl;
			return 0;
		}
		else if (sum < m)
			max = mid - 1;
		else
			min = mid + 1;
	}
	cout << max << endl;
	return 0;
}
