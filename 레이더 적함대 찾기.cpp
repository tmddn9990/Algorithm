#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
struct point//point 구조체 선언
	using namespace std;

{
	int x;
	int y;
};
bool check(point rad, int r, point s)// 레이더와 반지름 적함의 위치를 받아 거리를 비교해 1,0리턴
{
	float d = sqrt(pow((rad.x - s.x), 2) + pow((rad.y - s.y), 2));
	if ((float)r >= d)
		return 1;
	else
		return 0;
}


void main() {
	int testNum;
	int r, n; //레이더의 좌표(x,y) 반지름 적함대수
	int ans;
	point rader;
	point ship[50];
	fflush(stdin);
	freopen("input.txt", "r", stdin);//파일을 입력받는다
	cin >> testNum;//테스트 넘버를 입력
	for (int test = 0; test < testNum; test++)
	{
		ans = 0;
		cin >> rader.x >> rader.y >> r >> n; // 레이더의 xy좌표 입력
		for (int i = 0; i < n; i++)
		{
			cin >> ship[i].x; //적함의 x좌표
			cin >> ship[i].y; //적함의 y좌표
			ans = ans + check(rader, r, ship[i]);
		}
		cout << "#" << test + 1 << " " << ans << endl;
	}
}
