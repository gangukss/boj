#include <iostream>
using namespace std;

int n, w[10][10], ans = 987654321;
bool visit[10];

void dfs(int i, int cnt, int sum) {
	if (cnt >= n) {
		if (w[i][0]) {
			sum += w[i][0];
			ans = min(ans, sum);
		}
		return ;
	}
	visit[i] = 1;
	for (int j = 0; j < n; ++j) {
		if (sum > ans) {
			visit[i] = 0;
			continue ;
		}
		if (!visit[j] && w[i][j])
			dfs(j, cnt + 1, sum + w[i][j]);
	}
	visit[i] = 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> w[i][j];
	dfs(0, 1, 0);
	cout << ans;
}