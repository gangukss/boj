#include <iostream>
#include <cstring>
using namespace std;

int n, m, ans;
int input[500][500];
int visit[500][500];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j, int sum, int cnt) {
	if (cnt >= 3) {
		ans = max(ans, sum);
		return ;
	}
	visit[i][j] = 1;
	for (int u = 0; u < 4; ++u) {
		int nextI = i + dx[u];
		int nextJ = j + dy[u];
		if (isValid(nextI, nextJ) && !visit[nextI][nextJ]) {
			dfs(nextI, nextJ, sum + input[nextI][nextJ], cnt + 1);
		}
	}
	visit[i][j] = 0;
}

void tShape1(int i, int j) {
	int tmp = 0;
	tmp = input[i][j] + input[i][j + 1] + input[i][j + 2] + input[i - 1][j + 1];
	ans = max(ans, tmp);
}
void tShape2(int i, int j) {
	int tmp = 0;
	tmp = input[i][j] + input[i][j + 1] + input[i][j + 2] + input[i + 1][j + 1];
	ans = max(ans, tmp);
}
void tShape3(int i, int j) {
	int tmp = 0;
	tmp = input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i + 1][j + 1];
	ans = max(ans, tmp);
}
void tShape4(int i, int j) {
	int tmp = 0;
	tmp = input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i + 1][j - 1];
	ans = max(ans, tmp);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> input[i][j];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dfs(i, j, input[i][j], 0);
			if (i - 1 >= 0 && j + 2 < m)
				tShape1(i, j);
			if (i + 1 < n && j + 2 < m)
				tShape2(i, j);
			if (i + 2 < n && j + 1 < m)
				tShape3(i, j);
			if (i + 2 < n && j - 1 >= 0)
				tShape4(i, j);
		}
	}
	cout << ans;
}
