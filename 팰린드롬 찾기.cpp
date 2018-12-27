#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

bool palin(char str[50], int start, int end) {//문장에서 star부터 end까지가 회문인지 확인하는 함수

	int pal = 0;
	int j = end;
	for (int i = start; i <= (end + start) / 2; i++, j--)//시작부터 회문의 중심까지 반복
	{
		if (str[i] == str[j])//가운데로 모여가면서 같을떄마다 임시변수 pal을 증가
			pal++;
	}
	if (pal == (end - start + 2) / 2) {//pal값이 문장의 반의 크기와 같을 

		return 1;
	}
	else
		return 0;
}
void main() {
	int testNum;//테스트 케이스
	char str[50];//분석할 문장
	fflush(stdin);
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int a = 0; a < testNum; a++) {
		cout << "#" << a + 1 << " ";
		cin >> str;
		int len = strlen(str);
		int count = 0;
		for (int i = 0; i < len - 2; i++) {
			for (int j = i + 2; j < len; j++) {//3자리 이상부터 회문이다
				if (palin(str, i, j)) {
					for (int k = i; k <= j; k++) {
						cout << str[k];
					}
					cout << " ";
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return;
}
