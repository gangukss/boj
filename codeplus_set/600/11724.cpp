#include <iostream>
#include <vector>
using namespace std;

int n, m, u, v, ans;
vector<vector<int>> input(1001);
bool visit[1001];

void dfs(int idx) {
	visit[idx] = 1;
	for (size_t i = 0; i < input[idx].size(); ++i)
		if (!visit[input[idx][i]])
			dfs(input[idx][i]);
}

int isComponentRemain() {
	for (int i = 1; i <= n; ++i)
		if (!visit[i])
			return i;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		input[u].emplace_back(v);
		input[v].emplace_back(u);
	}
	int nextIdx;
	while ((nextIdx = isComponentRemain())) {
		dfs(nextIdx);
		++ans;
	}
	cout << ans;
}
