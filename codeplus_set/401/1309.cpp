#include <iostream>
using namespace std;

const int M = 1e5;
const int base = 9901;
int dp[M][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	dp[0][0] = dp[0][1] = dp[0][2] = 1;
	for (int i = 1; i < n; ++i) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % base;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % base;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % base;
	}

	cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % base;
}