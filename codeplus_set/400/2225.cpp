#include <iostream>
using namespace std;

const int base = 1e9;
int n, k;
int dp[201][201];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i <= n; ++i)
		dp[1][i] = 1;
	for (int i = 2; i <= k; ++i)
		for (int j = 0; j <= n; ++j)
			for (int u = 0; u <= j; ++u)
				dp[i][j] = (dp[i][j] + dp[i - 1][u]) % base;
	cout << dp[k][n] << "\n";
	// for (int i = 0; i <= k; ++i) {
	// 	for (int j = 0; j <= n; ++j) {
	// 		cout << dp [i][j] << "	";
	// 	}
	// 	cout << "\n";
	// }
}
