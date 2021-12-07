#include <iostream>
#include <vector>
using namespace std;

int n, m;
int visit[9];
vector<int> v;

void dfs(int cnt) {
	if (cnt > m) {
		for (auto x : v)
			cout << x << " ";
		cout << "\n";
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!visit[i]) {
			v.emplace_back(i);
			visit[i] = 1;
			dfs(cnt + 1);
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	dfs(1);
}