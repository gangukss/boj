#include <iostream>
using namespace std;

const int M = 90;
long long dp[M][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	dp[0][1] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[n - 1][0] + dp[n - 1][1];
}
