// #include <iostream>
// #include <vector>
// using namespace std;

// const int M = 1001;
// int a[M];
// vector<vector<int>> dp(M);

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int n, idx = 0;
// 	cin >> n;
// 	for (int i = 1; i <= n; ++i) {
// 		cin >> a[i];
// 		for (int j = i - 1; j >= 0; --j)
// 			if (a[i] > a[j] && dp[i].size() < dp[j].size() + 1) {
// 				dp[i].clear();
// 				dp[i].insert(dp[i].begin(), dp[j].begin(), dp[j].end());
// 				dp[i].emplace_back(a[i]);
// 			}
// 		if (dp[idx].size() < dp[i].size())
// 			idx = i;
// 	}
// 	cout << dp[idx].size() << "\n";
// 	for (auto x : dp[idx])
// 		cout << x << " ";
// }

#include <iostream>
#include <vector>
using namespace std;

const int M = 1001;
int a[M];
int dp[M];
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, max = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = i - 1; j >= 0; --j)
			if (a[i] > a[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		if (dp[i] > max)
			max = dp[i];
	}
	cout << max << "\n";
	for (int i = n; i > 0; --i) {
		if (dp[i] == max) {
			ans.emplace_back(a[i]);
			--max;
		}
	}
	for (auto it = ans.end() - 1; it >= ans.begin(); --it)
		cout << *it << " ";
}
