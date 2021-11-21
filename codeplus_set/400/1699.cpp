#include <iostream>
using namespace std;

const int M = 1e5 + 1;
int dp[M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		dp[i] = i;
		for (int j = 1; j * j <= i; ++j)
			if (dp[i] > dp[i - j * j] + 1)
				dp[i] = dp[i - j * j] + 1;
	}
	cout << dp[n];
}
