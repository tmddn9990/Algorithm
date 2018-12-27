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
int maxOverlap(const string& a, const string& b)        //a의 접미사이자 b의 접두사의 최대길이
{
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);

	int begin = 0, matched = 0;
	while (begin < n)
	{
		if (matched < m && a[begin + matched] == b[matched])//일치하는 부분이 있는경우
		{
			++matched;                                    //다음 문자 검사
			if (begin + matched == n)                    //문자열 끝까지 검사한 경우
				return matched;                            // 길이를 리턴
		}
		else
		{
			if (matched == 0)                            //맞는 부분이 하나도 없으면
				++begin;                                //시작점을 한칸 민다.
			else
			{
				begin += matched - pi[matched - 1];        //맞는부분만큼 건너뛴다.
				matched = pi[matched - 1];                //일치하는 길이를 건너뛴만큼에서                           
			}
		}
	}
	return 0;
}
int main() {
	freopen("input.txt", "r", stdin);
	int testNum;//테스트 케이스
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

