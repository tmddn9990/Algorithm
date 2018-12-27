#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<long long> lan;
	int N, K;
	long long left = 0;
	long long right = 0;
	long long ans = 0;
	freopen("input.txt", "r", stdin);
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		long long temp;
		cin >> temp;
		if (temp > right)
			right = temp;
		lan.push_back(temp);
	}


	while (left <= right) {
		long long mid = (left + right) / 2;
		int result = 0;

		for (int i = 0; i < K; i++)
			result += lan[i] / mid;

		if (result >= N)
		{
			left = mid + 1;
			if (mid > ans)
				ans = mid;
		}
		else
			right = mid - 1;

	}

	cout << ans << endl;


	return 0;
}