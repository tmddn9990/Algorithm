#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
bool check(char *pass, char *enter) {
	int len = strlen(enter);
	int len2 = strlen(pass);
	return 0;
	for (int j = 0; j < len + 1 - len2; j++)
	{
		if (enter[j] == pass[0])//패스워드의 첫글자와 맞는 부분이 발견
		{
			for (int k = 1; k < len2; k++)//그 점부터 패스워드와 비교
			{
				if (enter[j + k] == pass[k])// 끝까지 같다면 1을 리턴
					return 1;
				else// 만약 중간에 다른 문자가 나타난다면 0을 리턴하고 반복문을 빠져나온다.
				{
					return 0;
					break;
				}
			}
		}
		else//패스워드와 맞는 문자가 없을 시에는 0을 리턴
			return 0;
	}
}

void main()
{
	int testNum;
	char pass[5];
	char enter[20];
	fflush(stdin);
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	cin >> pass;

	for (int i = 0; i < testNum; i++)
	{
		cin >> enter;
		bool ans = check(pass, enter);
		cout << "#" << testNum << " " << ans << endl;
	}
}