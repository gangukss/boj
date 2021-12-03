#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input[9], sum, flag;
vector<int> ans;

void dfs(int i, int cnt) {
	if (sum > 100 || flag)
		return ;
	if (cnt == 7) {
		if (sum == 100) {
			sort(ans.begin(), ans.end());
			for (const auto &x : ans)
				cout << x << "\n";
			flag = 1;
		}
		return ;
	}
	for (int j = i; j < 9; ++j) {
		sum += input[j];
		ans.emplace_back(input[j]);
		dfs(j + 1, cnt + 1);
		sum -= input[j];
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; ++i) {
		cin >> input[i];
	}
	dfs(0, 0);
}