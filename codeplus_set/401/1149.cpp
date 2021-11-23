#include <iostream>
using namespace std;

int dp[1000][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	for (int i = 1; i < n; ++i) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}
	int ans = dp[n - 1][0];
	if (dp[n - 1][1] < ans)
		ans = dp[n - 1][1];
	if (dp[n - 1][2] < ans)
		ans = dp[n - 1][2];
	cout << ans;
}