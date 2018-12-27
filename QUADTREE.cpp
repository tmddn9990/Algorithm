#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string quard(string::iterator& it)
{
	char head = *it; ++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string one = quard(it);
	string two = quard(it);
	string three = quard(it);
	string four = quard(it);
	return string("x") + three + four + one + two;
}



int main() {


	int testNum;
	freopen("input.txt", "r", stdin);
	cin >> testNum;
	while (testNum--)
	{
		string fir;
		cin >> fir;
		string::iterator itr = fir.begin();
		cout << quard(itr) << endl;
	}

}