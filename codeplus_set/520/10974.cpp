#include <iostream>
using namespace std;

int n, ans[8];
bool visit[9];

void dfs(int cnt) {
	if (cnt >= n) {
		for (int i = 0; i < n; ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			ans[cnt] = i;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	dfs(0);
}