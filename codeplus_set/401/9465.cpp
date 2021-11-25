#include <iostream>
using namespace std;

const int M = 1e5;
int dp[3][M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			dp[2][i] = 0;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < n; ++j)
				cin >> dp[i][j];
		for (int i = 1; i < n; ++i) {
			dp[0][i] += max(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] += max(dp[0][i - 1], dp[2][i - 1]);
			dp[2][i] += max(dp[0][i - 1], dp[1][i - 1]);
		}
		int ans = dp[0][n - 1]; 
		ans = max(dp[1][n - 1], ans);
		ans = max(dp[2][n - 1], ans);
		cout << ans << "\n";
	}
}