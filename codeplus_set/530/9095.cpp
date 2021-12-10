#include <iostream>
using namespace std;

int t, n;
int ans[11];

void dfs(int sum, int &idx) {
	if (sum >= idx) {
		if (sum == idx) {
			++ans[idx];
			return ;
		}
		return ;
	}
	for (int i = 1; i < 4; ++i) {
		dfs(sum + i, idx);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int i = 1; i < 11; ++i)
		dfs(0, i);
	while (t--) {
		cin >> n;
		cout << ans[n] << "\n";
	}
}