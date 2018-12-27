#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
//1 2 3 4 5 6 7 8 9 10
//0 1 1 2 3 2 3 3 2 3
using namespace std;

int D[1000001];
int main(void) {

	int N;
	cin >> N;

	D[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0)
			D[i] = min(D[i], D[i / 2] + 1);
		if (i % 3 == 0)
			D[i] = min(D[i], D[i / 3] + 1);
	}

	cout << D[N];
	return 0;
}