#include <iostream>
using namespace std;

int t, n;

int dfs(int sum) {
	if (sum == n)
		return 1;
	if (sum > n)
		return 0;
	int ret = 0;
	for (int i = 3; i > 0; --i)
		ret += dfs(sum + i);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		cout << dfs(0) << "\n";
	}
}
