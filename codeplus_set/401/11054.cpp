#include <iostream>
using namespace std;

const int M = 1002;
int A[M];
int dp_up[M];
int dp_down[M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> A[i];
		for (int j = i - 1; j >= 0; --j)
			if (A[j] < A[i])
				dp_up[i] = max(1 + dp_up[j], dp_up[i]);
	}
	for (int i = n; i >= 1; --i) {
		for (int j = i + 1; j <= n; ++j)
			if (A[j] < A[i])
				dp_down[i] = max(1 + dp_down[j], dp_down[i]);
	}
	int ans = dp_up[1] + dp_down[1];
	for (int i = 2; i <= n; ++i)
		ans = max(ans, dp_up[i] + dp_down[i]);
	cout << ans;
}
