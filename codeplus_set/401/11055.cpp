#include <iostream>
using namespace std;

int A[1000];
int dp[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		dp[i] = A[i];
		for (int j = i - 1; j >= 0; --j)
			if (A[j] < A[i])
				dp[i] = max(A[i] + dp[j], dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
