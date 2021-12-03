#include <iostream>
using namespace std;
#define MAX 1e9;

int input[1000][3];
int dp[1000][3];
int ans = MAX;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> input[i][0] >> input[i][1] >> input[i][2];
	for (int color = 0; color < 3; ++color) {
		for (int i = 0; i < 3; ++i) {
			if (color == i)
				dp[0][i] = input[0][color];
			else
				dp[0][i] = MAX;
		}
		for (int i = 1; i < n; ++i) {
			dp[i][0] = input[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = input[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = input[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
		dp[n - 1][color] = MAX;
		ans = min(ans, min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])));
	}
	cout << ans;
}