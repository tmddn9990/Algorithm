#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;



int coin[100];
int cache[10001] = { 0 };
int main() {
	freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> coin[i];
	for (int i = 0; i <= k; i++)
		cache[i] = -1;
	cache[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - coin[i] >= 0 && cache[j - coin[i]] != -1) {
				if (cache[j] == -1 || cache[j] > cache[j - coin[i]] + 1) {
					cache[j] = cache[j - coin[i]] + 1;
				}
			}
		}
	}
	cout << cache[k];

	return 0;
}

