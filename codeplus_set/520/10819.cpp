#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int n, input[8], ans;
bool visit[8];
vector<int> v;

void dfs(int cnt) {
	if (cnt >= n) {
		int sum = 0;
		for (int i = 0; i < n - 1; ++i)
			sum += abs(v[i] - v[i + 1]);
		ans = max(ans, sum);
		return ;
	}
	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			v.emplace_back(input[i]);
			dfs(cnt + 1);
			visit[i] = 0;
			v.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	dfs(0);
	cout << ans;
}