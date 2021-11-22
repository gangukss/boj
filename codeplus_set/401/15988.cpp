#include <iostream>
using namespace std;

const int M = 1e6 + 1;
const int base = 1e9 + 9;
unsigned int dp[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < M; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % base;

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}