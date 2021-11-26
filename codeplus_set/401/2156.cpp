#include <iostream>
using namespace std;

const int M = 1e4 + 1;
int input[M];
int dp[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> input[i];
	dp[1] = input[1];
	dp[2] = dp[1] + input[2];
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1];
		dp[i] = max(dp[i], dp[i - 2] + input[i]);
		dp[i] = max(dp[i], dp[i - 3] + input[i - 1] + input[i]);
	}
	cout << dp[n];
}
