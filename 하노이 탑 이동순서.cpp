#define _CRT_SECURE_NO_WARNINGS
#include iostream
#include cmath
using namespace std;
void hanoi(int num, int start, int mid, int end)
{

	if (num == 1)
	{

		printf(%d %dn, start, end);
		return;
	}
	hanoi(num - 1, start, end, mid);
	printf(%d %dn, start, end);
	hanoi(num - 1, mid, start, end);
}

int main() {
	freopen(input.txt, r, stdin);
	int N;
	cin  N;
	printf(%dn, (unsigned int)pow(2, N) - 1);
	hanoi(N, 1, 2, 3);
}
