#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int t, l, curX, curY, targetX, targetY;
const int M = 300;
int visit[M][M];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
struct pos {
	int x;
	int y;
};
queue<pos> q;

bool isValid(int row, int col) {
	return row >= 0 && row < l && col >= 0 && col < l && visit[row][col] == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> l >> curX >> curY >> targetX >> targetY;
		if (curX == targetX && curY == targetY) {
			cout << 0 << "\n";
			continue ;
		}
		q.push({curX, curY});
		memset(visit, 0, sizeof(visit));
		visit[curX][curY] = 1;
		while (!q.empty()) {
			pos tmp = q.front();
			q.pop();
			for (int i = 0; i < 8; ++i) {
				int nextRow = tmp.x + dx[i];
				int nextCol = tmp.y + dy[i];
				if (isValid(nextRow, nextCol)) {
					if (nextRow == targetX && nextCol == targetY) {
						cout << visit[tmp.x][tmp.y] << "\n";
						while (!q.empty())
							q.pop();
						break ;
					}
					visit[nextRow][nextCol] = visit[tmp.x][tmp.y] + 1;
					q.push({nextRow, nextCol});
				}
			}
		}
	}
}
