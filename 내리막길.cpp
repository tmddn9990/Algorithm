#define _CRT_SECURE_NO_WARNINGS
#include<iostream>



using namespace std;

int map[500][500];
int D[500][500];
int width, height;
int maze(int a, int b)
{
	if (a == (height - 1) && b == (width - 1))
		return 1;
	if (D[a][b] == -1)
		D[a][b]++;

	int px, py;
	int plusx[4] = { 0,0,1,-1 }, plusy[4]{ 1,-1,0,0 };

	for (int i = 0; i < 4; i++)
	{
		px = a + plusx[i];
		py = b + plusy[i];
		if (px < 0 || py < 0 || px >= height || py >= width)
			continue;

		if (map[a][b] > map[px][py])
		{
			if (D[px][py] == -1)
				D[a][b] += maze(px, py);
			else
				D[a][b] += D[px][py];
		}

	}
	return D[a][b];
}


int main() {

	freopen("input.txt", "r", stdin);
	cin >> height >> width;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
			D[i][j] = -1;
		}
	cout << maze(0, 0);

	return 0;
}