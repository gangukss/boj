#include <iostream>
using namespace std;

int n, m;
char input[50][50];
bool visit[50][50];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int x, int y, int prevX, int prevY) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (isValid(nextX, nextY) && input[nextX][nextY] == input[x][y]) {
			if (!visit[nextX][nextY] && dfs(nextX, nextY, x, y))
				return 1;
			if (visit[nextX][nextY] && !(nextX == prevX && nextY == prevY))
				return 1;
		}
	}
	visit[x][y] = 0;
	return 0;
}

void checkVisit(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (isValid(nextX, nextY) && !visit[nextX][nextY] && input[nextX][nextY] == input[x][y])
			checkVisit(nextX, nextY);
	}
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
			if (!visit[i][j]) {
				if (dfs(i, j, i, j)) {
					cout << "Yes";
					return 0;
				}
				checkVisit(i, j);
			}
		}
	}
	cout << "No";
}
