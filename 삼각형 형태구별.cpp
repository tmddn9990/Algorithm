#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>

using namespace std;
struct point//point ����ü ����
{
	int x;
	int y;
};
struct triangle//point 3���� �̷���� �ﰢ�� ����ü ����
{
	point p1;
	point p2;
	point p3;
};
int check(triangle t)// �ﰢ���� ���� ����
{

	float a = sqrt(pow((t.p1.x - t.p2.x), 2) + pow((t.p1.y - t.p2.y), 2));
	float b = sqrt(pow((t.p2.x - t.p3.x), 2) + pow((t.p2.y - t.p3.y), 2));
	float c = sqrt(pow((t.p3.x - t.p1.x), 2) + pow((t.p3.y - t.p1.y), 2));//�Ÿ����ϴ� �������� ���� �� ���Ǳ���
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
	}//abc�� ũ������� ����
	if (a >= b + c)
		return 0;//���� ū���� ���̰� ������ �κ��� ������ �հ� ũ�ų� ���� �� �ﰢ���� �̷���� �� ����
	else
	{
		if (pow(a, 2) == pow(b, 2) + pow(c, 2)) return 1;//�����ﰢ�� ����
		else if (pow(a, 2) > pow(b, 2) + pow(c, 2)) return 2;// �а��ﰢ���� ����
		else return 3;// ���� �ﰢ��    
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
