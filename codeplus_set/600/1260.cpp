#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, v, a, b;
vector<vector<int>> input(1001);
bool visit[1001];
queue<int> q;

void dfs(int idx) {
	cout << idx << " ";
	visit[idx] = 1;
	for (size_t i = 0; i < input[idx].size(); ++i)
		if (!visit[input[idx][i]])
			dfs(input[idx][i]);
}

void bfs(int idx) {
	q.emplace(idx);
	visit[idx] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (size_t i = 0; i < input[cur].size(); ++i)
			if (!visit[input[cur][i]]) {
				visit[input[cur][i]] = 1;
				q.emplace(input[cur][i]);
			}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		input[a].emplace_back(b);
		input[b].emplace_back(a);
	}
	for (int i = 1; i <= n; ++i)
		sort(input[i].begin(), input[i].end());
	dfs(v);
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	bfs(v);
}
