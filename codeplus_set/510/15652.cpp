#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void dfs(int idx, int cnt) {
	if (cnt > m) {
		for (auto x : v)
			cout << x << " ";
		cout << "\n";
		return ;
	}
	for (int i = idx; i <= n; ++i) {
		v.emplace_back(i);
		dfs(i, cnt + 1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	dfs(1, 1);
}