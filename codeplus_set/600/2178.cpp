#include <iostream>
#include <queue>
using namespace std;

int n, m;
char input[100][100];
bool visit[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct pos {
	int x;
	int y;
	int cnt;
};
queue<pos> q;

bool isValid(int row, int col) {
	return row >= 0 && row < n && col >= 0 && col < m && !visit[row][col] && input[row][col] == '1';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> input[i][j];
	q.push({0, 0, 1});
	visit[0][0] = 1;
	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		if (tmp.x == n - 1 && tmp.y == m - 1) {
			cout << tmp.cnt;
			break ;
		}
		for (int i = 0; i < 4; ++i) {
			int nextRow = tmp.x + dx[i];
			int nextCol = tmp.y + dy[i];
			if (isValid(nextRow, nextCol)) {
				visit[nextRow][nextCol] = 1;
				q.push({nextRow, nextCol, tmp.cnt + 1});
			}
		}
	}
}
