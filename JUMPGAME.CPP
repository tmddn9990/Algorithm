#includeiostream
#includealgorithm
using namespace std;
int map[100][100];
bool vis[100][100];
bool ans;
void path(int n, int a, int b)
{
	if ((a == (n - 1)) && (b == (n - 1)))
	{
		ans = true; return;
	}
	if ((a = n)  (b = n))
	{
		return;
	}
	if (vis[a][b])
		return;
	vis[a][b] = true;
	path(n, a + map[a][b], b);
	path(n, a, b + map[a][b]);

}

int main() {
	int testNum;
	freopen(input.txt, r, stdin);
	cin  testNum;
	while (testNum--)
	{
		ans = false;
		int n;
		cin  n;
		for (int i = 0; i n; i++)
			for (int j = 0; j n; j++)
			{
				cin  map[i][j];
				vis[i][j] = false;
			}
		path(n, 0, 0);
		if (ans)
			cout  YES  endl;
		else
			cout  NO  endl;

	}

}