#include <iostream>
using namespace std;

int n, m, ans;
int input[500][500];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool visit[500][500];

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int cnt, int sum) {
    if (cnt >= 4) {
        ans = max(ans, sum);
        return ;
    }
    visit[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isValid(nextX, nextY) && !visit[nextX][nextY])
            dfs(nextX, nextY, cnt + 1, sum + input[nextX][nextY]);
    }
    visit[x][y] = 0;
}

void checkTShape(int x, int y) {
    if (isValid(x - 1, y + 2)) // ㅗ
        ans = max(ans, input[x - 1][y + 1] + input[x][y] + input[x][y + 1] + input[x][y + 2]);
    if (isValid(x + 1, y + 2)) // ㅜ
        ans = max(ans, input[x + 1][y + 1] + input[x][y] + input[x][y + 1] + input[x][y + 2]);
    if (isValid(x + 2, y - 1)) // ㅓ
        ans = max(ans, input[x + 1][y - 1] + input[x][y] + input[x + 1][y] + input[x + 2][y]);
    if (isValid(x + 2, y + 1)) // ㅏ
        ans = max(ans, input[x + 1][y + 1] + input[x][y] + input[x + 1][y] + input[x + 2][y]);
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
            dfs(i, j, 1, input[i][j]);
            checkTShape(i, j);
        }
    }
    cout << ans;
}

