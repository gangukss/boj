#include <iostream>
using namespace std;

const int M = 100;
const int base = 1e9;
int dp[M][10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < 10; ++i)
		dp[0][i] = 1;

	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < 9; ++j)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % base;
	}

	int ans = 0;
	for (int i = 0; i < 10; ++i)
		ans = (ans + dp[n - 1][i]) % base;
	cout << ans;
}
