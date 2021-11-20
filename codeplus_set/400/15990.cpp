#include <iostream>
using namespace std;

const int M = 1e5 + 1;
const int base = 1e9 + 9;
int t, n;
unsigned int dp[M][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[1][0] = 1;
	dp[1][1] = 0;
	dp[1][2] = 0;

	dp[2][0] = 0;
	dp[2][1] = 1;
	dp[2][2] = 0;

	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;

	for (int i = 4; i < M; ++i) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % base;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % base;
		dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % base;
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << (dp[n][0] + dp[n][1] + dp[n][2]) % base << "\n";
	}
}
