#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
struct point//point ����ü ����
	using namespace std;

{
	int x;
	int y;
};
bool check(point rad, int r, point s)// ���̴��� ������ ������ ��ġ�� �޾� �Ÿ��� ���� 1,0����
{
	float d = sqrt(pow((rad.x - s.x), 2) + pow((rad.y - s.y), 2));
	if ((float)r >= d)
		return 1;
	else
		return 0;
}


void main() {
	int testNum;
	int r, n; //���̴��� ��ǥ(x,y) ������ ���Դ��
	int ans;
	point rader;
	point ship[50];
	fflush(stdin);
	freopen("input.txt", "r", stdin);//������ �Է¹޴´�
	cin >> testNum;//�׽�Ʈ �ѹ��� �Է�
	for (int test = 0; test < testNum; test++)
	{
		ans = 0;
		cin >> rader.x >> rader.y >> r >> n; // ���̴��� xy��ǥ �Է�
		for (int i = 0; i < n; i++)
		{
			cin >> ship[i].x; //������ x��ǥ
			cin >> ship[i].y; //������ y��ǥ
			ans = ans + check(rader, r, ship[i]);
		}
		cout << "#" << test + 1 << " " << ans << endl;
	}
}
