#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

bool palin(char str[50], int start, int end) {//���忡�� star���� end������ ȸ������ Ȯ���ϴ� �Լ�

	int pal = 0;
	int j = end;
	for (int i = start; i <= (end + start) / 2; i++, j--)//���ۺ��� ȸ���� �߽ɱ��� �ݺ�
	{
		if (str[i] == str[j])//����� �𿩰��鼭 ���������� �ӽú��� pal�� ����
			pal++;
	}
	if (pal == (end - start + 2) / 2) {//pal���� ������ ���� ũ��� ���� 

		return 1;
	}
	else
		return 0;
}
void main() {
	int testNum;//�׽�Ʈ ���̽�
	char str[50];//�м��� ����
	fflush(stdin);
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	for (int a = 0; a < testNum; a++) {
		cout << "#" << a + 1 << " ";
		cin >> str;
		int len = strlen(str);
		int count = 0;
		for (int i = 0; i < len - 2; i++) {
			for (int j = i + 2; j < len; j++) {//3�ڸ� �̻���� ȸ���̴�
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
