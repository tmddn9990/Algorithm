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
		bool check[10] = { 0 };//����ȿ� ������ ���̶� ǥ���ϱ� ���� bool �迭
		string str;
		getline(cin, str);

		cout << str << endl;
		for (int i = 0; i < str.size(); i++)//string�� ũ�⸸ŭ�� �ݺ����� ������.
		{
			if (str[i] >= '1'&&str[i] <= '9') //�ڿ����� ���(0����)
			{

				if (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '\0')// ���� ���ڸ� ���� ���
				{
					int a = str[i] - '0';
					check[a - 1] = 1;
				}
				else if (str[i + 1] >= '0'&&str[i + 1] <= '9')//���ڸ��� �� ���
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
