#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
int maxOverlap(const string& a, const string& b)        //a�� ���̻����� b�� ���λ��� �ִ����
{
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);

	int begin = 0, matched = 0;
	while (begin < n)
	{
		if (matched < m && a[begin + matched] == b[matched])//��ġ�ϴ� �κ��� �ִ°��
		{
			++matched;                                    //���� ���� �˻�
			if (begin + matched == n)                    //���ڿ� ������ �˻��� ���
				return matched;                            // ���̸� ����
		}
		else
		{
			if (matched == 0)                            //�´� �κ��� �ϳ��� ������
				++begin;                                //�������� ��ĭ �δ�.
			else
			{
				begin += matched - pi[matched - 1];        //�´ºκи�ŭ �ǳʶڴ�.
				matched = pi[matched - 1];                //��ġ�ϴ� ���̸� �ǳʶڸ�ŭ����                           
			}
		}
	}
	return 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	int testNum;//�׽�Ʈ ���̽�
	cin >> testNum;
	while (testNum--)
	{
		string str, rev = "";
		cin >> str;
		int len = str.size();
		for (int i = len - 1; i >= 0; i--)
		{
			rev += str[i];
		}

		cout << 2 * len - maxOverlap(str, rev) << endl;
	}
	return 0;
}

