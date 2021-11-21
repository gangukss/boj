#include <iostream>
using namespace std;

const int M = 1001;
int a[M];
int dp[M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 0; j < i; ++j)
			if (a[i] > a[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
