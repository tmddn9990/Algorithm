#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;
vector <char> str;
char ans[15];
bool promising()
{
	int ja = 0, mo = 0;
	for (int i = 0; i < L; i++)
	{
		char d = ans[i];
		if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u')
			mo++;
		else
			ja++;
	}
	if (ja >= 2 && mo >= 1)
		return true;
	else
		return false;
}
void search(int index, int i)
{
	if (index == L) {
		if (promising()) {
			cout << ans << endl;
		}
		return;
	}
	if (i >= C)
		return;
	ans[index] = str[i];
	search(index + 1, i + 1);
	search(index, i + 1);
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> L >> C;
	str.resize(C);
	for (int i = 0; i < C; i++)
	{
		char a;
		cin >> a;
		str[i] = a;
	}
	sort(str.begin(), str.end());
	search(0, 0);
	return 0;
}