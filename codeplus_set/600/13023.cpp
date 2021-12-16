#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> v(2000);
bool visit[2000];
bool ans;

void dfs(int idx, int cnt) {
	if (cnt == 4 || ans) {
		ans = 1;
		return ;
	}
	visit[idx] = 1;
	for (size_t i = 0; i < v[idx].size(); ++i)
		if (!visit[v[idx][i]])
			dfs(v[idx][i], cnt + 1);
	visit[idx] = 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	for (int i = 0; i < n; ++i) {
		dfs(i, 0);
		if (ans)
			break ;
	}
	cout << ans;
}
