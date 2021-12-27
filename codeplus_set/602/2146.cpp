#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int M = 100;
int n, ans = 987654321;
int input[M][M];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int islandNum = 1;
bool visit[M][M];
struct pos {
	int x;
	int y;
	int islandNum;
	int len;
};

bool isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void setIslandNum(int x, int y) {
	input[x][y] = islandNum;
	for (int i = 0; i < 4; ++i) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (isValid(nextX, nextY) && input[nextX][nextY] == 1)
			setIslandNum(nextX, nextY);
	}
}

void getShortestBridge(int x, int y) {
	memset(visit, 0, sizeof(visit));
	queue<pos> q;
	q.push({x, y, input[x][y], 0});
	visit[x][y] = 1;
	while (!q.empty()) {
		pos tmp = q.front();
		q.pop();
		if (tmp.len >= ans)
			return ;
		for (int i = 0; i < 4; ++i) {
			int nextX = tmp.x + dx[i];
			int nextY = tmp.y + dy[i];
			if (isValid(nextX, nextY) && !visit[nextX][nextY]) {
				if (input[nextX][nextY] == 0) {
					q.push({nextX, nextY, tmp.islandNum, tmp.len + 1});
					visit[nextX][nextY] = 1;
				} else if (tmp.islandNum != input[nextX][nextY]) {
					ans = min(ans, tmp.len);
					return ;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> input[i][j];
	// set island number
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (input[i][j] == 1) {
				++islandNum;
				setIslandNum(i, j);
			}
	// get shortest bridge
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (input[i][j])
				getShortestBridge(i, j);
	cout << ans;
}
