#include <iostream>
using namespace std;

int input[15][2];
int n, ans;

void dfs(int idx, int sum) {
	if (idx >= n) {
		if (idx == n)
			ans = max(ans, sum);
		return ;
	}
	for (int i = idx; i <= n; ++i) {
		if (i == n)
			ans = max(ans, sum);
		else
			dfs(i + input[i][0], sum + input[i][1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> input[i][0] >> input[i][1];
	dfs(0, 0);
	cout << ans;
}