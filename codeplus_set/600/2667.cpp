#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char input[25][25];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visit[25][25];
vector<int> ans;

bool isValid(int row, int col) {
	return row >= 0 && row < n && col >= 0 && col < n && !visit[row][col] && input[row][col] != '0';
}

int dfs(int row, int col) {
	visit[row][col] = 1;
	int ret = 1;
	for (int i = 0; i < 4; ++i) {
		int nextRow = row + dx[i];
		int nextCol = col + dy[i];
		if (isValid(nextRow, nextCol))
			ret += dfs(nextRow, nextCol);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> input[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!visit[i][j] && input[i][j] == '1')
				ans.emplace_back(dfs(i, j));
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x << "\n";
}
