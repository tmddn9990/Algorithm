#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void main()
{
	float table[62][11] = { 0 }; //ǥ�����Ժ���ǥ
	int d, rank; //�ο���,���
	float score, m, s, z, val; //������, ���, ǥ������, ��ȯ�� ����, ǥ���� ã�� ��

	cout << "������, ��ü���, ǥ������, ���ο����� �Է��Ͻÿ�";
	cin >> score >> m >> s >> d;
	fflush(stdin);
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 62; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> table[i][j];
		}
	}//ǥ�����Ժ���ǥ�� table�� �Է�

	z = (score - m) / s;
	for (int i = 0; i < 62; i++) {
		for (int j = 0; j < 11; j++) {
			if (((float)table[i][0] + table[0][j]) == z)
				val = table[i][j];
		}
	}
	val = table[(int)z * 10 + 1][(int)z * 100 % 100 + 1];
	if (z > 0)
		rank = d * (0.5 - val);
	else
		rank = d * (0.5 + val);



	cout << rank << "���Դϴ�.";







	return;
}
