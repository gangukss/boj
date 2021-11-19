#include <iostream>
using namespace std;

int ans;

void dfs(const int &n, int sum) {
	if (sum > n)
		return ;
	if (sum == n) {
		++ans;
		return ;
	}
	for (int i = 1; i <= 3; ++i) {
		dfs(n, sum + i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		dfs(n, 0);
		cout << ans << "\n";
		ans = 0;
	}
}
