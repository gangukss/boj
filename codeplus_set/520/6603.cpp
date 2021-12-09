#include <iostream>
#include <vector>
using namespace std;

int k, input[13];
bool visit[13];
vector<int> ans;

void dfs(int idx, int cnt) {
	if (cnt > 6) {
		for (auto x : ans)
			cout << x << " ";
		cout << "\n";
		return ;
	}
	for (int i = idx; i < k; ++i) {
		if (!visit[i]) {
			visit[i] = 1;
			ans.emplace_back(input[i]);
			dfs(i, cnt + 1);
			visit[i] = 0;
			ans.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		cin >> k;
		if (!k)
			break ;
		for (int i = 0; i < k; ++i)
			cin >> input[i];
		dfs(0, 1);
		cout << "\n";
	}
}