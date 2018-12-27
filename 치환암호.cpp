#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main()
{
	int testNum;
	int pad;
	string key;
	string word;
	fflush(stdin);
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	cin >> key;
	int keylen = key.length();
	for (int i = 0; i < testNum; i++)
	{
		cin >> word;
		int wordlen = word.length();
		if (wordlen%keylen == 0)
			pad = 0;
		else
			pad = keylen - wordlen % keylen;
		for (int j = 0; j < pad; j++)
			word += ('a' + j);
		cout << "#" << i + 1 << " ";
		wordlen = word.length();

		for (int l = 0; l < wordlen; l = l + keylen) {
			if (l + keylen < wordlen) {
				for (int k = l; k < l + keylen; k++)
				{
					int n = (key.at(k - l) - '0' - 1);
					cout << word[n + l];
				}
			}
			else {
				for (int k = l; k < wordlen; k++)
				{
					int n = (key.at(k - l) - '0' - 1);
					cout << word[n + l];
				}
			}
		}
		cout << endl;
	}
}
