#include <iostream>
#include <cstring>
using namespace std;

int w, h;
int input[50][50];
bool visit[50][50];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool isValid(int row, int col) {
	return row >= 0 && row < h && col >= 0 && col < w && !visit[row][col] && input[row][col];
}

void dfs(int row, int col) {
	visit[row][col] = 1;
	for (int i = 0; i < 8; ++i) {
		int nextRow = row + dx[i];
		int nextCol = col + dy[i];
		if (isValid(nextRow, nextCol))
			dfs(nextRow, nextCol);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int ans = 0;
		memset(visit, 0, sizeof(visit));
		cin >> w >> h;
		if (!w && !h)
			break ;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> input[i][j];
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (!visit[i][j] && input[i][j]) {
					dfs(i, j);
					++ans;
				}
		cout << ans << "\n";
	}
}
