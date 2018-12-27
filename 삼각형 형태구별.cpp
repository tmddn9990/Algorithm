#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>

using namespace std;
struct point//point 구조체 선언
{
	int x;
	int y;
};
struct triangle//point 3개로 이루어진 삼각형 구조체 선언
{
	point p1;
	point p2;
	point p3;
};
int check(triangle t)// 삼각형의 형태 구분
{

	float a = sqrt(pow((t.p1.x - t.p2.x), 2) + pow((t.p1.y - t.p2.y), 2));
	float b = sqrt(pow((t.p2.x - t.p3.x), 2) + pow((t.p2.y - t.p3.y), 2));
	float c = sqrt(pow((t.p3.x - t.p1.x), 2) + pow((t.p3.y - t.p1.y), 2));//거리구하는 공식으로 구한 세 변의길이
	float temp;
	if (a < b)
	{
		temp = a;    a = b;    b = temp;
	}
	if (b < c)
	{
		temp = b;    b = c;    c = temp;
	}
	if (a < b)
	{
		temp = a;    a = b;    b = temp;
	}//abc를 크기순서로 정렬
	if (a >= b + c)
		return 0;//가장 큰변의 길이가 나머지 두변의 길이의 합과 크거나 같을 때 삼각형이 이루어질 수 없음
	else
	{
		if (pow(a, 2) == pow(b, 2) + pow(c, 2)) return 1;//직각삼각형 조건
		else if (pow(a, 2) > pow(b, 2) + pow(c, 2)) return 2;// 둔각삼각형의 조건
		else return 3;// 예각 삼각형    
	}
}


void main()
{
	int testNum;
	triangle tri;
	fflush(stdin);
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int i = 0; i < testNum; i++)
	{
		cin >> tri.p1.x >> tri.p1.y >> tri.p2.x >> tri.p2.y >> tri.p3.x >> tri.p3.y;
		cout << "#" << i + 1 << " " << check(tri) << endl;
	}
}
