#include <iostream>
using namespace std;

const int M = 1e5;
int input[M];
int dp[M][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	int ans = dp[0][0] = dp[0][1] = input[0];
	for (int i = 1; i < n; ++i) {
		dp[i][0] = max(dp[i - 1][0] + input[i], input[i]);
		dp[i][1] = max(dp[i - 1][1] + input[i], dp[i - 1][0]);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	cout << ans;
}
