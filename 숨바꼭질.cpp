#include<iostream>
#include<queue>
using namespace std;

int check[100001] = { 0 };
int N, K;
queue<int> que;

int find() {
	que.push(N);
	check[N] = 0;
	while (!que.empty()) {
		int a = que.front();
		que.pop();
		if (a == K)
			return check[a];

		if (a - 1 >= 0 && check[a - 1] == 0) {
			check[a - 1] = check[a] + 1;
			que.push(a - 1);
		}

		if (a + 1 <= 100000 && check[a + 1] == 0) {
			check[a + 1] = check[a] + 1;
			que.push(a + 1);
		}

		if (a * 2 <= 100000 && check[a * 2] == 0) {
			check[a * 2] = check[a] + 1;
			que.push(a * 2);
		}

	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	cout << find() << endl;
	return 0;
}