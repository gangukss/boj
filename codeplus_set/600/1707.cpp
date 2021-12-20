#include <iostream>
#include <vector>
using namespace std;

int K, V, E, u, v;
const int M = 2e4 + 1;
vector<vector<int>> input(M);
int isRedColor[M];

bool dfs(int idx, bool redColor) {
	isRedColor[idx] = redColor;
	for (size_t i = 0; i < input[idx].size(); ++i) {
		if (redColor == isRedColor[input[idx][i]])
			return 0;
		if (isRedColor[input[idx][i]] == -1)
			if (!dfs(input[idx][i], !redColor))
				return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K;
	while (K--) {
		cin >> V >> E;
		for (int i = 0; i <= V; ++i) {
			isRedColor[i] = -1;
			input[i].clear();
		}
		for (int i = 0; i < E; ++i) {
			cin >> u >> v;
			input[u].emplace_back(v);
			input[v].emplace_back(u);
		}
		int ans = 1;
		for (int i = 1; i < V; ++i) {
			if (isRedColor[i] == -1 && !dfs(i, 1)) {
				ans = 0;
				break ;
			}
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
