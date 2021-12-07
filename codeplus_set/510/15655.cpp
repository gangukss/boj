#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int input[9];
bool visit[9];
vector<int> v;

void dfs(int idx, int cnt) {
	if (cnt > m) {
		for (auto x : v)
			cout << x << " ";
		cout << "\n";
		return ;
	}
	for (int i = idx; i <= n; ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			v.emplace_back(input[i]);
			dfs(i + 1, cnt + 1);
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
	for (int i = 1; i <= n; ++i)
		cin >> input[i];
	sort(input + 1, input + n + 1);
	dfs(1, 1);
}