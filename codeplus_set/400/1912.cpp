#include <iostream>
using namespace std;

const int M = 1e5;
int dp[M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> dp[i];
	int maxSum = dp[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);
		if (maxSum < dp[i])
			maxSum = dp[i];
	}
	cout << maxSum;
}
