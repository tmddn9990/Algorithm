#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int fence[20000];

int main() {
	freopen("input.txt", "r", stdin);
	int testNum;
	cin >> testNum;
	while (testNum--) {
		int n, ret = 0;
		stack<int> st;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> fence[i];
		st.push(-1);
		for (int i = 0; i < n; i++) {
			while (!st.empty() && fence[i] < fence[st.top()]) {
				int temp = st.top();
				st.pop();
				if (!st.empty())
					ret = max(ret, fence[temp] * (i - st.top() - 1));
			}
			st.push(i);
		}
		while (!st.empty()) {
			int temp = st.top();
			st.pop();
			if (!st.empty())
				ret = max(ret, fence[temp] * (n - st.top() - 1));
		}
		cout << ret << endl;
	}
}