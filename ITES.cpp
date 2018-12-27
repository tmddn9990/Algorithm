#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;



int main() {
	freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;
	while (testNum--)
	{

		int k, n, sum = 0, count = 0, cnt = 0;;
		cin >> k >> n; //k==sum이되는 갯수 n까지
		queue<int> A;
		size_t pre = 1983;
		while (1)
		{
			if (sum > k)
			{
				sum -= A.front();
				A.pop();
			}
			else if (sum == k)
			{
				count++;
				sum -= A.front();
				A.pop();
			}
			else
			{
				cnt++;
				if (cnt > n)
					break;
				A.push(pre % 10000 + 1);
				pre = (pre * 214013 + 2531011);
				sum += A.back();

			}


		}
		cout << count << endl;
	}
	return 0;
}
