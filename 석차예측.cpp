#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void main()
{
	float table[62][11] = { 0 }; //표준정규분포표
	int d, rank; //인원수,등수
	float score, m, s, z, val; //원점수, 평균, 표준편차, 변환후 변수, 표에서 찾은 값

	cout << "원점수, 전체평균, 표준편차, 총인원수를 입력하시오";
	cin >> score >> m >> s >> d;
	fflush(stdin);
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 62; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> table[i][j];
		}
	}//표준정규분포표를 table에 입력

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



	cout << rank << "등입니다.";







	return;
}
