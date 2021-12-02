#include <iostream>
using namespace std;

int boardSize, ans[2], f;
bool board[10][10];
bool isPossibleL[19];
bool isPossibleR[19];

void dfs(int r, int c, int cnt) {
	ans[f] = max(ans[f], cnt);
	if (c >= boardSize)
		c = f ^ (++r % 2);
	if (r >= boardSize)
		return ;
	if (board[r][c] && !isPossibleL[r + c] && !isPossibleR[r - c + boardSize - 1]) {
		isPossibleL[r + c] = isPossibleR[r - c + boardSize - 1] = 1;
		dfs(r, c + 2, cnt + 1);
		isPossibleL[r + c] = isPossibleR[r - c + boardSize - 1] = 0;
	}
	dfs(r, c + 2, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> boardSize;
	for (int i = 0; i < boardSize; ++i)
		for (int j = 0; j < boardSize; ++j)
			cin >> board[i][j];
	dfs(0, 0, 0);
	f = 1;
	dfs(0, 1, 0);
	cout << ans[0] + ans[1];
}

// 	00	01	02	03	04
// 0	10	11	12	13	14
// 1	20	21	22	23	24
// 2	30	31	32	33	34
// 3	40	41	42	43	44
// 4	5	6	7	8

// 	00	01	02	03	04
// 	10	11	12	13	14	-4
// 	20	21	22	23	24	-3
// 	30	31	32	33	34	-2
// 	40	41	42	43	44	-1
// 		4	3	2	1	0	