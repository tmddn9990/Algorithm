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
		if (enter[j] == pass[0])//�н������� ù���ڿ� �´� �κ��� �߰�
		{
			for (int k = 1; k < len2; k++)//�� ������ �н������ ��
			{
				if (enter[j + k] == pass[k])// ������ ���ٸ� 1�� ����
					return 1;
				else// ���� �߰��� �ٸ� ���ڰ� ��Ÿ���ٸ� 0�� �����ϰ� �ݺ����� �������´�.
				{
					return 0;
					break;
				}
			}
		}
		else//�н������ �´� ���ڰ� ���� �ÿ��� 0�� ����
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