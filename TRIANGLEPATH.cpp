#include<iostream>
#include<algorithm>
using namespace std;
int map[100][100];
int tri[100][100];

int triangle(int a, int b, int size)
{
	if (a == (size - 1))
		return map[a][b];
	int &tmp = tri[a][b];
	if (tmp != -1)
		return tmp;
	tmp = max(triangle(a + 1, b, size), triangle(a + 1, b + 1, size)) + map[a][b];
	return tmp;
}

int main() {
	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	while (testNum--)
	{
		int size;
		cin >> size;
		for (int i = 0; i < size; i++)
			for (int j = 0; j <= i; j++)
			{
				cin >> map[i][j];
				tri[i][j] = -1;
			}
		cout << triangle(0, 0, size) << endl;

	}

}