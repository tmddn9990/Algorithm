#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


int H, W;
int board[50][20];

const int coverType[4][3][2] = {
	{ { 0,0 },{ 1,0 },{ 1,-1 } },
	{ { 0,0 },{ 1,0 },{ 1,1 } },
	{ { 0,0 },{ 0,1 },{ 1,1 } },
	{ { 0,0 },{ 0,1 },{ 1,0 } } };

bool set(int type, int y, int x, int delta) {
	int dx, dy;
	bool ok = true;

	for (int i = 0; i < 3; i++) {
		dx = coverType[type][i][1];
		dy = coverType[type][i][0];

		if (y + dy >= H || y + dy < 0 || x + dx >= W || x + dx < 0)
			ok = false;

		else if ((board[y + dy][x + dx] += delta) > 1)
			ok = false;
	}
	return ok;
}

int setting() {
	int y = -1;
	int x = -1;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)break;
	}

	if (y == -1)return 1;
	int ret = 0;

	for (int type = 0; type < 4; type++) {
		if (set(type, y, x, 1))
			ret += setting();
		set(type, y, x, -1);
	}
	return ret;
}

int main() {
	int testcase;
	freopen("input.txt", "r", stdin);
	cin >> testcase;
	while (testcase--) {
		cin >> H >> W;
		for (int i = 0; i < 30; i++)
			for (int j = 0; j < 30; j++)
				board[i][j] = 0;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char c;
				cin >> c;

				if (c == '#') {
					board[i][j] = 1;
				}
				else {
					board[i][j] = 0;
				}
			}
		}
		cout << setting() << endl;
	}
	return 0;
}