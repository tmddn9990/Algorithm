#define _CRT_SECURE_NO_WARNINGS
#include iostream
#include vector

using namespace std;

int arr[3];

void ans(vectorvectorint &map, int size, int x, int y) {

	if (size == 1) {
		arr[map[x][y] + 1] ++;
		return;
	}

	int before = map[x][y], after;
	bool check = true;

	for (int i = x; ix + size; i++)
	{
		for (int j = y; jy + size; j++)
		{
			if (x == i && y == j)
				continue;
			else {
				after = map[i][j];
				if (before != after)
				{
					check = false;
					break;
					before = after;
				}
			}
		}
	}

	if (check) {
		arr[before + 1] ++;
	}
	else {
		for (int i = 0; i3; i++) {
			for (int j = 0; j3; j++) {
				ans(map, size  3, x + (size  3)i, y + (size  3)j);
			}
		}
	}
	return;
}

int main() {
	freopen(input.txt, r, stdin);
	int N;
	cin  N;


	vectorvectorint map;
	int tmp;
	for (int i = 0; iN; i++) {
		vectorint temp;
		for (int j = 0; jN; j++) {
			cin tmp;
			temp.push_back(tmp);
		}
		map.push_back(temp);
	}

	ans(map, N, 0, 0);

	cout  arr[0]  endl  arr[1]  endl  arr[2]  endl;


	return 0;
}
