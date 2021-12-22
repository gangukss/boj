#include <iostream>
#include <queue>
using namespace std;

int n, m;
const int M = 1000;
int input[M][M];
bool visit[M][M];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct pos {
	int x;
	int y;
};
queue<pos> q;

bool isValid(int row, int col) {
	return row >= 0 && row < n && col >= 0 && col < m && input[row][col] == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> input[i][j];
			if (input[i][j] == 1)
				q.push({i, j});
		}
	}
	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nextRow = tmp.x + dx[i];
			int nextCol = tmp.y + dy[i];
			if (isValid(nextRow, nextCol)) {
				input[nextRow][nextCol] = input[tmp.x][tmp.y] + 1;
				q.push({nextRow, nextCol});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (input[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			ans = max(ans, input[i][j]);
		}
	}
	if (ans == 0)
		cout << ans;
	else
		cout << ans - 1;
}
