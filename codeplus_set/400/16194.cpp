#include <iostream>
using namespace std;

const int M = 1001;
int n, P[M], dp[M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> P[i];
		dp[i] = P[i];
		for (int j = 1; j <= i; ++j)
			dp[i] = min(dp[i - j] + P[j], dp[i]);
	}
	cout << dp[n];
}
