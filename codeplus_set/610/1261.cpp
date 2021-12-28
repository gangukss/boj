#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int x;
	int y;
};
const int M = 100;
int n, m;
char input[M][M];
queue<pos> q;
int visit[M][M];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> input[i][j];
			input[i][j] -= '0';
			visit[i][j] = 987654321;
		}
	}
	q.push({0, 0});
	visit[0][0] = 0;
	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nextX = tmp.x + dx[i];
			int nextY = tmp.y + dy[i];
			if (isValid(nextX, nextY) && visit[nextX][nextY] > visit[tmp.x][tmp.y] + (int)input[nextX][nextY]) {
				q.push({nextX, nextY});
				visit[nextX][nextY] = visit[tmp.x][tmp.y] + input[nextX][nextY];
			}
		}
	}
	cout << visit[n - 1][m - 1];
}
