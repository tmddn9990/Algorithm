#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;


void main()
{

	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	getchar();
	for (int n = 0; n < testNum; n++)
	{
		bool check[10] = { 0 };//가방안에 있으면 참이라 표시하기 위한 bool 배열
		string str;
		getline(cin, str);

		cout << str << endl;
		for (int i = 0; i < str.size(); i++)//string의 크기만큼의 반복문을 돌린다.
		{
			if (str[i] >= '1'&&str[i] <= '9') //자연수인 경우(0제외)
			{

				if (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '\0')// 그중 한자릿 수인 경우
				{
					int a = str[i] - '0';
					check[a - 1] = 1;
				}
				else if (str[i + 1] >= '0'&&str[i + 1] <= '9')//두자릿수 인 경우
				{

					int a = 10 * (str[i] - '0') + (str[i + 1] - '0');
					check[a - 1] = 1;
				}
			}
			else
				continue;
		}
		for (int i = 0; i < 10; i++)
			cout << check[i];

		int count = 0;
		for (int i = 0; i < 10; i++)
			if (check[i] == 1)
				count++;



		cout << "#" << n + 1 << " " << count << endl;
	}
}
