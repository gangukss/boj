#include <iostream>
using namespace std;

int dp[500][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= i + 1; ++j)
			cin >> dp[i][j];
		for (int j = 1; j <= i + 1; ++j)
			dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
	}
	int ans = dp[n - 1][1];
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dp[n - 1][i]);
	cout << ans;
}
