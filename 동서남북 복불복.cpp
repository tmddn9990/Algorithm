#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct point {
	int x;
	int y;
};
struct elem {
	char dir;
	char num;

};

void main() {

	int n;
	int testNum;
	int ans;
	int num;
	elem map[10][10];
	point p, temp;
	fflush(stdin);
	freopen("input.txt", "r", stdin);
	cin >> n;
	cin >> testNum;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j].dir;
			cin >> map[i][j].num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j].dir << map[i][j].num << "    ";
		}cout << endl;
	}
	for (int i = 0; i < testNum; i++)
	{
		cin >> p.y;
		cin >> p.x;
		cin >> num;

		temp.y = p.y - 1;
		temp.x = p.x - 1;

		for (int j = 0; j < num; j++)
		{
			if (map[temp.y][temp.x].dir == 'N')
				temp.y = temp.y - map[temp.y][temp.x].num;
			else if (map[temp.y][temp.x].dir == 'S')
				temp.y = temp.y + map[temp.y][temp.x].num;
			else if (map[temp.y][temp.x].dir == 'W')
				temp.x = temp.x - map[temp.y][temp.x].num;
			else if (map[temp.y][temp.x].dir == 'E')
				temp.x = temp.x + map[temp.y][temp.x].num;
			if (temp.x < 0 || temp.x >= n || temp.y < 0 || temp.y >= n)
				ans = 10000; break;
		}
		ans = map[temp.x][temp.y].num * 1000;
		cout << "#" << i + 1 << " " << ans << endl;
	}
}